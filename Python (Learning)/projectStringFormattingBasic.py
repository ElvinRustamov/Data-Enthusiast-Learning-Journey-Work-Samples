# Instruction
# Create a program which prints out student names and their score as shown below
#
# names and scores lists are given
#
# names = ['John', 'Edy', 'Jane', 'Kane']
# scores = [90, 95, 80, 75]
# Sample Output:
#
# Name Score
#
# John 90
# Edy 95
# Jane 80
# Kane 75

names = ['John', 'Edy', 'Jane', 'Kane']
scores = [90, 95, 80, 75]

def string_formatting(names, scores):
    for idx in range(len(names)):
        print(f'Name: {names[idx]} --- Score: {scores[idx]}')

string_formatting(names, scores)