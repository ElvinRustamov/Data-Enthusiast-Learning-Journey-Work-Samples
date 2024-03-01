import numpy as np
import pandas as pd
import re
import copy

class GradientDescent:
    derivative = {
        'sin(x)': {'function': lambda x: np.sin(x), 'derivative': lambda x: np.cos(x)},
        'cos(x)': {'function': lambda x: np.cos(x), 'derivative': lambda x: -np.sin(x)},
        'tan(x)': {'function': lambda x: np.tan(x), 'derivative': lambda x: 1 / np.cos(x) ** 2},
        'csc(x)': {'function': lambda x: 1 / np.sin(x), 'derivative': lambda x: -1 / (np.abs(np.sin(x)) * np.sin(x))},
        'sec(x)': {'function': lambda x: 1 / np.cos(x), 'derivative': lambda x: np.tan(x) / np.cos(x)},
        'cot(x)': {'function': lambda x: 1 / np.tan(x), 'derivative': lambda x: -1 / np.sin(x) ** 2}
    }

    def __init__(self, *f_parameters, intercept: float = 0.0):
        self.f_parameters = f_parameters
        self.intercept = intercept
        self.gradient_descent()

    def creating_function(self):
        function = {}
        p_c = 0  # parameter counter
        for p in self.f_parameters:
            p_c += 1

            parameter = f"x{p_c}"
            if p in self.derivative.keys():
                function[parameter] = {'multi': 1, 'power': 1, 'label': p}
            else:
                list_of_e = p.split('^')
                if len(list_of_e) > 1:
                    try:
                        power = float(list_of_e[1])
                    except:
                        temp = re.sub(r'\(|\)', '', list_of_e[1])
                        power = float(int(temp.split('/')[0]) / int(temp.split('/')[1]))

                    if list_of_e[0][0].isalpha(): multiply = 1
                    else:
                        if list_of_e[0][0] == '-':
                            multiply = float(list_of_e[0][:2])
                        else:
                            multiply = float(list_of_e[0][0])
                else: power = 1

                function[parameter] = {'multi': multiply, 'power': power, 'label': p}
        return function

    def creating_sample_dataset(self):
        function = self.creating_function()
        dataset_column_name = [f"Parameter {i}" for i in range(len(function))]
        dataset_column_name.append('y')
        parameters = []
        for _ in range(5):
            temp_p = []
            for v in function.values():
                f_value = np.random.randint(1, 5, dtype=int)
                if v['label'] in self.derivative.keys(): temp_p.append(self.derivative[v['label']]['function'](f_value))
                else: temp_p.append((f_value ** v['power']) * v['multi'])

            temp_y = sum(temp_p) + self.intercept
            temp_p.append(temp_y)
            parameters.append(temp_p)

        dataset = pd.DataFrame(parameters, columns=dataset_column_name)
        return function, dataset

    def gradient_descent(self):
        function = self.creating_function()
        initial_guess = []
        learning_rate_l = [0.01, 0.0001, 0.001]
        length_of_variables = len(function)
        for i in range(5):
            temp_guess = []
            for _ in range(length_of_variables):
                temp_guess.append(round(np.random.randint(1, 5), 2))
            initial_guess.append(temp_guess)

        data = []

        for ig in initial_guess:
            for l_r in learning_rate_l:
                guess = copy.deepcopy(ig)
                temp = []
                temp.append(ig)
                temp.append(l_r)
                for _ in range(100):
                    derivatives = []
                    idx = 0
                    for v in function.values():
                        if v['label'] in self.derivative.keys():
                            derivatives.append(self.derivative[v['label']]['derivative'](guess[idx]))
                        else:
                            derivatives.append((v['power'] - 1 * v['multi']) * (guess[idx]**(v['power'] - 1)))

                        guess[idx] = round((guess[idx] - l_r * derivatives[idx]), 2)
                        idx += 1
                temp.append(guess)
                data.append(temp)

        df = pd.DataFrame(data, columns=['Initial Guess', 'Learning Rate', 'Local Minimum'])
        print(df)

        # first_guess = [0.1, 0.3, 0.5]
        #
        # data = []
        # for y in first_guess:
        #     for l_r in learning_rate_l:
        #         x = y
        #         temp = []
        #         temp.append(y)
        #         temp.append(l_r)
        #         for _ in range(15):
        #             derivative_s = 0  # gradient
        #             for v in function.values():
        #                 if v['label'] in self.derivative.keys():
        #                     derivative_s += self.derivative[v['label']]['derivative'](x)
        #                 else:
        #                     derivative_s += (v['power'] - 1 * v['multi']) * (x**(v['power'] - 1))
        #             x = x - l_r * derivative_s
        #         temp.append(x)
        #         data.append(temp)
        #
        # df = pd.DataFrame(data, columns=['Initial Guess', 'Learning Rate', 'Local Minimum'])
        # print(df)


GradientDescent('sin(x)', '-3x^2', '4x^(1/2)')