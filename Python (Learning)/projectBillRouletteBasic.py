# Instruction
# Create a program which which asks for names and select random name from the list of names. The person selected will have to pay for everybody's food bill.

def bill_roulette():
    import random

    group_names = input('Names (Example -> A B): ')
    names = group_names.split()
    print(random.choice(names))

bill_roulette()