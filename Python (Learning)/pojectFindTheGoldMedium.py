# Instructions
# You are going to write a program which will automatically place the Golden STAR in a map and we will find it by marking a spot with an X.

import random
def print_map(p_map):
    print('\n'.join([' '.join(['{:2}'.format(item) for item in row]) for row in p_map]))

def golden_star():
    map1 = [["⬜️", "️⬜️", "️⬜️"], ["⬜️", "️⬜️", "️⬜️"], ["⬜️", "️⬜️", "️⬜️"]]
    print("This is our initial map...")
    print_map(map1)

    golden_star_r, golden_star_c = random.choice([1, 2, 3]), random.choice([1, 2, 3])
    user_guess = input("What do you think: where is the Golden Star in the map? ")
    u_r, u_c = int(user_guess[0]), int(user_guess[1])

    if golden_star_r == u_r and golden_star_c == u_c:
        print("Congratulations!!! You have found the Golden STAR!")
        map1[u_r-1][u_c-1] = '⭐️'
        print_map(map1)
    else:
        print("Unfortunatly you could find it 🙁")
        map1[golden_star_r - 1][golden_star_c - 1] = '⭐️'
        map1[u_r - 1][u_c - 1] = '🆇'
        print_map(map1)

    play_again = input("Play again (y/n): ").lower()
    if play_again == 'y':
        golden_star()
    elif play_again == 'n':
        return False

golden_star()