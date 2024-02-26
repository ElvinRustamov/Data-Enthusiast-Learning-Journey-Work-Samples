# Instruction
# Create a program that simulates Blind Auction. [https://en.wikipedia.org/wiki/First-price_sealed-bid_auction] (https://en.wikipedia.org/wiki/First-price_sealed-bid_auction)
#
# Step 1: Print Logo - Blind Auction
# Step 2: Ask user name
# Step 3: Input Bid
# Step 4: If there is another user, type YES, then the program asks for next bidder by cleaning everything from console
# Step 5: Finally, If there is not another bidder return the highest bidder with bid amount

import os

def clear_console():
    os.system('cls' if os.name == 'nt' else 'clear')

class BlindAuction():
    logo = """
    ██████╗ ██╗     ██╗███╗   ██╗██████╗      █████╗ ██╗   ██╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗
    ██╔══██╗██║     ██║████╗  ██║██╔══██╗    ██╔══██╗██║   ██║██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║
    ██████╔╝██║     ██║██╔██╗ ██║██║  ██║    ███████║██║   ██║██║        ██║   ██║██║   ██║██╔██╗ ██║
    ██╔══██╗██║     ██║██║╚██╗██║██║  ██║    ██╔══██║██║   ██║██║        ██║   ██║██║   ██║██║╚██╗██║
    ██████╔╝███████╗██║██║ ╚████║██████╔╝    ██║  ██║╚██████╔╝╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║
    ╚═════╝ ╚══════╝╚═╝╚═╝  ╚═══╝╚═════╝     ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝

    """
    print(logo)

    user_bid = 0
    user_name = ''
    def __init__(self):
        self.user()

    def user(self):
        user_name = input("What's your name? ")
        correct_bid = True
        while correct_bid:
            try:
                bid = float(input("What is your bid amount?: $"))
                if bid > self.user_bid:
                    self.user_bid = bid
                    self.user_name = user_name
                correct_bid = False
            except:
                print("Error, write a number!")

        correct_other = True
        while correct_other:
            other = input("Are there any other bidder?(Y/N): ").upper()
            if other in ['Y', 'N']:
                if other == 'Y':
                    clear_console()
                    self.user()
                    correct_other = False
                else:
                    print(f"The winner is {self.user_name} with a bid of ${self.user_bid}")
                    correct_other = False
            else:
                print("Write y (yes) or n (no).")



BlindAuction()