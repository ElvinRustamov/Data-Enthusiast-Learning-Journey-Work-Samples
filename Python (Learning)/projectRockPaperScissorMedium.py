# Instruction
# Create a program which simulates Rock, Paper, Scissors Game Steps:

# Ask user to select rock, paper or scissors

# Then generate computer selection by using random module

# Then determine winner based on computer selection and user selection

# Finally, ask whether they want to play again or not

def rockPaperScissors():
    import random

    options = ['rock', 'paper', 'scissors']
    c_guess = random.choice(options)

    while True:
        user_g = input('Enter a choice (rock, paper, scissors): ').lower()
        if user_g in options:
            break
        else:
            print('Choose from options -> rock, paper, scissors')

    print(f"You chose {user_g}, computer chose {c_guess}.")

    if user_g == c_guess:
        print("It's a tie!")
    elif user_g == 'rock':
        if c_guess == 'paper':
            print("Computer wins!")
        else:
            print("You win!")
    elif user_g == 'paper':
        if c_guess == 'scissors':
            print("Computer wins!")
        else:
            print("You win!")
    elif user_g == 'scissors':
        if c_guess == 'rock':
            print("Computer wins!")
        else:
            print("You win!")

    while True:
        play_again = input('Play again (y/n)? ').lower()
        if play_again in ['y', 'n']:
            if play_again == 'y':
                rockPaperScissors()
            else:
                break

rockPaperScissors()
