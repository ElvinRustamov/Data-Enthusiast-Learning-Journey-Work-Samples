# Step 1 - Picking a secret word and asking for player input
import random


class Hangman:
    word_list = ["LEARNING"]
    health = 6
    hangman_stages = ['''
      +---+
      |   |
      |   O
      |  /|\  
      |  / \ 
      |    
    ==========
    ''', '''
      +---+
      |   |
      |   O
      |  /|\  
      |  / 
      |    
    ==========
    ''', '''
      +---+
      |   |
      |   O
      |  /|\  
      |  
      |    
    ==========
    ''', '''
      +---+
      |   |
      |   O
      |  /| 
      |  
      |    
    ==========''', '''
      +---+
      |   |
      |   O
      |   |
      |  
      |    
    ==========
    ''', '''
      +---+
      |   |
      |   O
      |   
      |  
      |    
    ==========
    ''', '''
      +---+
      |   |
      |   
      |   
      |  
      |    
    ==========
    ''']

    def __init__(self):
        self.hangman()

    def play_again(self):
        while True:
            ask = input("Play again (Y/N): ").upper()
            if ask in ['Y', 'N']:
                if ask == 'Y':
                    Hangman()
                    break
                else:
                    return False

    def hangman(self):
        word = random.choice(self.word_list)
        word_underscores = ["_" for i in range(len(word))]
        guessed_word = []
        new_word = ''
        while True:
            print(self.hangman_stages[self.health])
            user_guess = input("Write a letter: ").upper()
            if user_guess in word:
                if user_guess in guessed_word:
                    print("Try a new letter.")
                else:
                    idx = 0
                    index_ = []
                    for wl in word:
                        if wl == user_guess:
                            index_.append(idx)
                        idx += 1

                    for i in index_:
                        word_underscores[i] = user_guess
                        guessed_word.append(user_guess)
                        new_word = ' '.join(word_underscores)
                    print(new_word)
            else:
                self.health -= 1
            if self.health == 0:
                print(f"You lose. The word is {word}. You guessed {new_word}.")
                self.play_again()
                break
            if ''.join(new_word.split()) == word:
                print("You win the game !!!")
                self.play_again()
                break


Hangman()
