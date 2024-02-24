# Instruction
# Fizz buzz is a group word game for children to teach them about division. Players take turns to count incrementally, replacing any number divisible by five with the word "Fizz", and any number divisible by seven with the word "Buzz". Write a program where for multiples of 5 you print “Fizz”, for the multiples of 7 “Buzz” and FizzBuzz for multiples of both. Remember your answer should start from 1 and go up to and including 100.

# Your program should print each number from 1 to 100 in turn.

# When the number is divisible by 5 then instead of printing the number it should print "Fizz".

# When the number is divisible by 7, then instead of printing the number it should print "Buzz".

# And if the number is divisible by both 5 and 7 e.g. 35 then instead of the number it should print "FizzBuzz"

for n in range(1, 100+1):
    if (n % 5 == 0) and (n % 7 == 0):
        print('FizzBuzz')
    elif n % 7 == 0:
        print('Buzz')
    elif n % 5 == 0:
        print("Fizz")
    else:
        print(n)