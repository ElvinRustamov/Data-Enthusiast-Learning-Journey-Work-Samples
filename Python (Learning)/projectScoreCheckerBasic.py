# Instructions
# Write a program to prompt for a score between 0.0 and 1.0. If the score is out of range, print an error message. If the score is between 0.0 and 1.0, print a grade using the following table:

# Grade	Score
# A	>= 0.9
# B	>= 0.8
# C	>= 0.7
# D	>= 0.6
# F	< 0.6

def scoreChecker():
    score = float(input('Score (Between 0.0 and 1.0): '))
    if (score < 0) or (score > 1):
        print('Score must be in 0 and 1.')
        scoreChecker()
    elif score >= 0.9: print('A')
    elif score >= 0.8: print('B')
    elif score >= 0.7: print('C')
    elif score >= 0.6: print('D')
    elif score < 0.6: print('F')

scoreChecker()