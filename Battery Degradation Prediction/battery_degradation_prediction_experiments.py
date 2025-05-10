import xgboost as xgb
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import StandardScaler
import pandas as pd
import joblib
import matplotlib.pyplot as plt
import lime
import lime.lime_tabular
import shap
from sklearn.ensemble import RandomForestRegressor
import lightgbm as lgb
import numpy as np
from scipy import stats

df = pd.read_csv(r'battery_degradation_dataset.csv')

usefull_columns = [i.lower() for i in ['Current', 'Voltage', 'Charge_Capacity','Discharge_Capacity', 'Charge_Energy',
                    'Discharge_Energy', 'dV/dt','Internal_Resistance', 'Temperature']]

df = df.loc[:, usefull_columns]

df = df.sample(n=100000)

Q_NOMINAL = 1.1
df['SOH'] = (df['charge_capacity'] / Q_NOMINAL) * 100

df['SOH'] = np.log1p(df['SOH'])

X = df.drop('SOH', axis=1)
y = df['SOH']

df_cleaned = df[(np.abs(stats.zscore(df[['charge_capacity', 'discharge_capacity', 'voltage', 'current', 'charge_energy']])) < 3).all(axis=1)]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(df_cleaned.drop('SOH', axis=1))

X_train, X_test, y_train, y_test = train_test_split(X_scaled, y[df_cleaned.index], test_size=0.2, random_state=42)

xgb_model = xgb.XGBRegressor(
    objective='reg:squarederror',
    eval_metric='rmse',
    alpha=0.3,
    lambda_=0.3,
    random_state=42
)

lgb_model = lgb.LGBMRegressor(
    objective='regression',
    metric='rmse',
    lambda_l1=0.3,
    lambda_l2=0.3,
    max_depth=6,
    num_leaves=31,
    random_state=42
)

rf_model = RandomForestRegressor(
    random_state=42,
    max_depth=7,
    min_samples_split=10,
    min_samples_leaf=5
)

param_grid = {
    'n_estimators': [100, 300, 500],
    'learning_rate': [0.01, 0.1, 0.3],
    'max_depth': [3, 5, 7],
    'subsample': [0.8, 1.0],
    'colsample_bytree': [0.8, 1.0]
}

param_grid_rf = {
    'n_estimators': [100, 300],
    'max_depth': [5, 7, 10],
    'min_samples_split': [5, 10],
    'bootstrap': [True, False]
}

def grid_search_optimization(model, param, name, cv_c=3):
    grid_search = GridSearchCV(estimator=model, param_grid=param, scoring='neg_mean_squared_error', cv=cv_c,
                               verbose=2)

    grid_search.fit(X_train, y_train)
    print(f"Best Parameters: {grid_search.best_params_}")
    best_model = grid_search.best_estimator_

    joblib.dump(best_model, f'{name}.pkl')

    y_pred = best_model.predict(X_test)

    print(f'{name} R^2 Score: {r2_score(y_test, y_pred):.2f}')
    print(f'{name} Mean Squared Error: {mean_squared_error(y_test, y_pred):.2f}')

    return best_model, y_pred, name

best_model, y_pred, name = grid_search_optimization(xgb_model, param_grid, 'xgb_model')

plt.figure(figsize=(8,6))
plt.scatter(y_test, y_pred, alpha=0.6)
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'k--', lw=2)
plt.title('Actual vs Predicted SOH')
plt.xlabel('Actual SOH')
plt.ylabel('Predicted SOH')
plt.show()

if name == 'xgb':
    xgb.plot_importance(best_model, importance_type='weight', max_num_features=10)
    plt.title('Feature Importance (Weight)')
    plt.show()
elif name == 'gbm':
    lgb.plot_importance(best_model, importance_type='weight', max_num_features=10, figsize=(8, 6))
    plt.title('Feature Importance')
    plt.show()
else:
    feat_importances = pd.Series(best_model.feature_importances_, index=X.columns)
    feat_importances.nlargest(10).plot(kind='barh', figsize=(8, 6))
    plt.title('Feature Importance')
    plt.show()

explainer = lime.lime_tabular.LimeTabularExplainer(
    training_data=X_train,
    training_labels=y_train,
    mode='regression',
    feature_names=X.columns,
    class_names=['SOH'],
    verbose=True,
    random_state=42
)

i = 10
exp = explainer.explain_instance(X_test[i], best_model.predict)

print(exp.as_list())

fig = exp.as_pyplot_figure()
fig.set_size_inches(10, 6)
plt.tight_layout()
plt.show()

explainer_shap = shap.TreeExplainer(best_model)

shap_values = explainer_shap.shap_values(X_test)

shap.summary_plot(shap_values, X_test, feature_names=X.columns)
plt.show()
