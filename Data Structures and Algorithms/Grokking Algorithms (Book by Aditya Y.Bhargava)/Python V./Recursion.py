# Solving factorial with using recursion

# factorial(n) = n × factorial(n – 1)

def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)

answer = factorial(3)
print(answer)