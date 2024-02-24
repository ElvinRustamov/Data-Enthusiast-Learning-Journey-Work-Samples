# Instruction
# Create a program will generate a random number unknown to the user between upper and lower bond that user provided. The user needs to guess what that number is. If the user’s guess is wrong, the program should return some sort of indication as to how wrong (e.g. The number is too high or too low). If the user guesses correctly, a positive indication should appear.

# Your program should ask for upper and lower bound from the user initially.

# Calculate chances of user based on upper and lower bounds.

# Based on calculated number of chances ask input from user for guessing the number.

# If the guessed number is greater than the generated number then print - "You guessed too high", otherwise print - "You guessed too low". And finally if the numbers match print - "Congratulations you did it in"

def guessing_number():
    import random

    lower = int(input('Enter Lower Bound: '))
    higher = int(input("Enter Upper Bound: "))
    print("""
            You've only  3  chances to guess the number!
    """)
    c_guessing_number = random.randint(lower, higher)
    n = 1
    while True:
        try:
            g_n = int(input("Guess a number: "))
            n += 1
        except:
            print("Error, enter a number.")

        if g_n > c_guessing_number:
            print("You Guessed too high!")
        elif g_n < c_guessing_number:
            print('You guessed too small!')
        elif g_n == c_guessing_number:
            print(f"""
                    Congratulations you did it in {n} try.
            """)
            break

        if n == 4:
            print(f"You lose! The number is {c_guessing_number} Better Luck Next time!")
            break
    play_again = input("Play again (y/n): ").lower()
    if play_again == 'y':
        guessing_number()
    else:
        return False

guessing_number()