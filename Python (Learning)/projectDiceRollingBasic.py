# Instruction
# When the program runs, it will randomly choose a number between 1 and 6. Then program will print what that number is. It should then ask you if you’d like to roll again.
import random

def dice_rolling():
    dice1, dice2 = random.randint(1, 6), random.randint(1, 6)
    print(f'First dice value: {dice1}')
    print(f'Second dice value: {dice2}')
    roll_again = input("Roll the dice again? (Y/N): ")
    if roll_again == 'Y':
        dice_rolling()
    elif roll_again == 'N':
        return False

dice_rolling()