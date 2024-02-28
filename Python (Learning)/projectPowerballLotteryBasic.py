# Step 1 - Ask the player to enter first 5 numbers between 1 and 69
# To do list
#
# TODO 1 - Check that the player entered 5 things
#
# TODO 2 - Convert the strings into integers
#
# TODO 3 - Check that the numbers are between 1 and 69
#
# TODO 4 - Check that the numbers are unique
#
# Step 2 - Ask the player to select the powerball between 1 to 26
# To do list
#
# TODO 1 - Convert the strings into integers
#
# TODO 2 - Check that the number is between 1 and 26
#
# Step 3 - Enter the number of times you want to play
# To do list
#
# TODO 1 - Convert the strings into integers
#
# TODO 2 - Check that the number is between 1 and 1000000
#
# Step 4 - Run the simulation
# To do list
#
# TODO 1 - Come up with lottery numbers
#
# TODO 2 - Display winning numbers
#
# TODO 3 - Check for winner
import random
import numpy as np

def powerballlottery():
    logo = """
     /$$$$$$$                                             /$$                 /$$ /$$
    | $$__  $$                                           | $$                | $$| $$
    | $$  \ $$ /$$$$$$  /$$  /$$  /$$  /$$$$$$   /$$$$$$ | $$$$$$$   /$$$$$$ | $$| $$
    | $$$$$$$//$$__  $$| $$ | $$ | $$ /$$__  $$ /$$__  $$| $$__  $$ |____  $$| $$| $$
    | $$____/| $$  \ $$| $$ | $$ | $$| $$$$$$$$| $$  \__/| $$  \ $$  /$$$$$$$| $$| $$
    | $$     | $$  | $$| $$ | $$ | $$| $$_____/| $$      | $$  | $$ /$$__  $$| $$| $$
    | $$     |  $$$$$$/|  $$$$$/$$$$/|  $$$$$$$| $$      | $$$$$$$/|  $$$$$$$| $$| $$
    |__/      \______/  \_____/\___/  \_______/|__/      |_______/  \_______/|__/|__/

    """
    print(logo)


    def w():
        while True:
            user_number = input("Enter 5 different numbers from 1 to 69, with spaces between each number. (For example: 5 17 23 42 50) -> ")
            user_number = list(map(int, user_number.split()))
            if max(user_number) <= 69 and min(user_number) >= 1 and len(set(user_number)) == 5:
                break

        while True:
            powerball_number = int(input("Enter the powerball number from 1 to 26 -> "))
            if (powerball_number >= 1) and (powerball_number <= 26):
                break

        times = int(input("How many times do you want to play (Max: 1000000 | 1 time cost 0.5$)? "))

        play = input(f"""
        It costs ${times * 0.5} to play {times} times, but don't worry. 
        I'm sure you'll win it all back.
        Press Enter to start...""")

        if len(play) == 0:
            win_rates = 0
            for _ in range(times):
                comp_guess = set()
                while len(comp_guess) < 5:
                    comp_guess.add(random.randint(1, 70))
                comp_number = np.random.randint(1, 26)

                if (len(set(user_number).difference(comp_guess)) == 0) and (comp_number == powerball_number):
                    print(f"The winning numbers are: {user_number} and {comp_number} You lost.")
                    win_rates += 1
                else:
                    print(f"The winning numbers are: {' '.join(list(map(str, comp_guess)))} and {comp_number}  You lost.")

            if win_rates == 0:
                print(f"""
                You have wasted ${times * 0.5}.
                Thanks for playing!
                """)
            else:
                print(f"""
                You won ${(times * 0.5)*win_rates}.
                Thanks for playing!
                """)

    w()

powerballlottery()