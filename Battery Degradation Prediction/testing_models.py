import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import joblib
from sklearn.metrics import mean_squared_error, r2_score
import shap
from scipy import stats

MODEL_PATH = 'Models/xgb_model.pkl'
SCALER_PATH = 'scaler.pkl'
TEST_CSV = '2017-05-12_6C-50per_3_6C_CH35.csv'
Q_NOMINAL = 1.1
FEATURE_COLUMNS = ['current', 'voltage', 'charge_capacity', 'discharge_capacity',
                   'charge_energy', 'discharge_energy', 'dv/dt', 'internal_resistance', 'temperature']


model = joblib.load(MODEL_PATH)
scaler = joblib.load(SCALER_PATH)


df = pd.read_csv(TEST_CSV)
df.columns = df.columns.str.lower()
df = df[[col.lower() for col in FEATURE_COLUMNS]]
df = df.sample(n=50000, random_state=42)


df['SOH'] = (df['charge_capacity'] / Q_NOMINAL) * 100
df['SOH'] = np.log1p(df['SOH'])


df_cleaned = df[(np.abs(stats.zscore(df[['charge_capacity', 'discharge_capacity', 'voltage', 'current', 'charge_energy']])) < 3).all(axis=1)]


X_test = df_cleaned.drop('SOH', axis=1)
y_test = df_cleaned['SOH']
X_test_scaled = scaler.transform(X_test)


y_pred = model.predict(X_test_scaled)


print(f"R^2 Score: {r2_score(y_test, y_pred):.4f}")
print(f"Mean Squared Error: {mean_squared_error(y_test, y_pred):.4f}")

plt.figure(figsize=(8,6))
plt.scatter(y_test, y_pred, alpha=0.5)
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'r--')
plt.xlabel("Actual SOH")
plt.ylabel("Predicted SOH")
plt.title("Actual vs Predicted SOH")
plt.grid(True)
plt.tight_layout()
plt.show()

explainer = shap.Explainer(model)
shap_values = explainer(X_test_scaled)

shap.summary_plot(shap_values, features=X_test_scaled, feature_names=X_test.columns)
