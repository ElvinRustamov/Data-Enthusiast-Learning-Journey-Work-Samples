# Instruction
# Create a program that simulates Quiz APP.
#
# Step 1: Print Logo - Quiz App
# Step 2: Ask for players and start with first player
# Step 3: For each questions a player can attempt two times, if first attempt is false the current player can attempt second time. But if the second time the answer is incorrect we switch players
# Step 4: If the answer is correct we switch players and the next question will be answered by next player
# Step 5: Finally, If there is not any question left we print out winner and ask if the want to see correct answers. If Yes we print the questions with answers if not we termiante the progrsm
import pprint


class QuizApp:
    logo = """ 
     ██████  ██    ██ ██ ███████      █████  ██████  ██████  
    ██    ██ ██    ██ ██    ███      ██   ██ ██   ██ ██   ██ 
    ██    ██ ██    ██ ██   ███       ███████ ██████  ██████  
    ██ ▄▄ ██ ██    ██ ██  ███        ██   ██ ██      ██      
     ██████   ██████  ██ ███████     ██   ██ ██      ██      
        ▀▀                                                  """
    print(logo)

    questions = {
        "1. What is a string?": "Text",
        "2. What is an integer?": "Whole number",
        "3. What is a float?": "Decimal number",
        "4. What is a boolean?": "True/False",
        "5. What is NoneType?": "Null value",
    }
    players_point = {}

    def __init__(self):
        self.players()
        self.quiz_play()
        self.winner()

    def players(self):
        while True:
            player_name = input("What is your name: ")
            other_player = input("Is there any other players (y/n): ").lower()
            self.players_point[player_name] = 0
            while True:
                if other_player in ['y', 'n']:
                    if other_player == 'y':
                        self.players()
                        break
                    else:
                        break
                else:
                    print("Please write y (yes) or n (no).")
            break

    def quiz_play(self):
        print("Game is starting. You have 2 attempts. Most correct answers win the game!")
        for k, v in self.players_point.items():
            print(f"Turn to answer: {k}")
            n = 2
            for q, qa in self.questions.items():
                user_answer = input(f"{q} ")
                if user_answer.lower() == qa.lower():
                    print("Correct !!!")
                    v += 1
                else:
                    n -= 1
                    print(f"Wrong! Attempts: {n}")
                    if n == 0:
                        print("Don't be sorry! You did your best.")
                        break

            self.players_point.update({k: v})

    def winner(self):
        names = ""
        values = []
        for k, v in self.players_point.items():
            values.append(v)

        if sum(values) == 0:
            print("There are no winners.")
        else:
            for k, v in self.players_point.items():
                if v == max(values):
                    names += f"{k}, "

            print(f"Our winners are: {names}")

        pprint.pprint(self.questions)

QuizApp()