# Instructions
# Developer a program which simulates very simpe Music APP.
#
# Rules:
#
# 1. Create Nested Tuple with given song list.
#     - Green Day
#             1. Somewhere Now
#             2. Bang Bang
#             3. Revolution Radio
#             4. Say Goodbye
#             5. Outlaws
#     - Metallica
#             1. Battery
#             2. Master of Puppets
#             3. The Thing That Should Not Be
#             4. Welcome Home (Sanitarium)
#     - U2
#             1. The Miracle
#             2. Every Breaking Wave
#             3. California
#             4. Song for Someone
#             5. Iris (Hold Me Close)
# 2. Show Ascii art logo
# 3. Print Song list
# 4. Ask from user to select a song based on number (1:1). First digit is band number and second digit is song number. For example 1:1 means first band and first song which is "Green Day Somewhere" Now in our case.
# 5. Playing song and asking if a user want to select different song or not. If not app terminates.

class MusicApp:
    logo = """  
    ███    ███ ██    ██ ███████ ██  ██████      █████  ██████  ██████  
    ████  ████ ██    ██ ██      ██ ██          ██   ██ ██   ██ ██   ██ 
    ██ ████ ██ ██    ██ ███████ ██ ██          ███████ ██████  ██████  
    ██  ██  ██ ██    ██      ██ ██ ██          ██   ██ ██      ██      
    ██      ██  ██████  ███████ ██  ██████     ██   ██ ██      ██   
    """

    song_list = (
        ('Green Day', ("Somewhere Now", "Bang Bang", "Revolution Radio", "Say Goodbye", "Outlaws")),
        ('Metallica', ("Battery", "Master of Puppets", "The Thing That Should Not Be", "Welcome Home (Sanitarium)")),
        ('U2', ("The Miracle", "Every Breaking Wave", "California", "Song for Someone","Iris (Hold Me Close)"))
    )

    song_list_txt = """
    1:1 Green Day - Somewhere Now
    1:2 Green Day - Bang Bang
    1:3 Green Day - Revolution Radio
    1:4 Green Day - Say Goodbye
    1:5 Green Day - Outlaws
    2:1 Metallica - Battery
    2:2 Metallica - Master of Puppets
    2:3 Metallica - The Thing That Should Not Be
    2:4 Metallica - Welcome Home (Sanitarium)
    3:1 U2 - The Miracle
    3:2 U2 - Every Breaking Wave
    3:3 U2 - California
    3:4 U2 - Song for Someone
    3:5 U2 - Iris (Hold Me Close)
    """
    print(logo)
    
    def __init__(self):
        self.play_song()
        self.play_again()

    def play_song(self):
        user_input = input("Select a song to play using number:(1:1) ")
        print(f"{self.song_list[int(user_input[0])-1][0]} - {self.song_list[int(user_input[0])-1][1][int(user_input[2])-1]} playing now....")

    def play_again(self):
        stop = True
        while stop:
            ask = input("Press C to change song or any letter to quit APP: ").lower()
            if ask == 'c':
                self.play_song()
            else:
                stop = False

MusicApp()