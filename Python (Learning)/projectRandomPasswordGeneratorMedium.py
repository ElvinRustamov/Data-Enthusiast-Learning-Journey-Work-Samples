# Instruction
# Create a program will generate a password based on user inputs. Initial variables are already provided.
# Your program should ask for number of letters, symbols and numbers initially
# Then based on these inputed values it will generate password

def passwordGenerator():
    import random

    letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    nums = "1234567890"
    symbols = "-+=!@#$%^&*"

    password = []

    while True:
        try:
            letters_c = int(input("How many letters do you want in your password? "))
            break
        except:
            print("Error, write a number!")

    while True:
        try:
            numbers_c = int(input("How many numbers do you want in your password? "))
            break
        except:
            print("Error, write a number!")
    while True:
        try:
            symbols_c = int(input("How many symbols do you want in your password? "))
            break
        except:
            print("Error, write a number!")

    for _ in range(letters_c):
        password.append(random.choice(letters))

    for _ in range(numbers_c):
        password.append(random.choice(nums))

    for _ in range(symbols_c):
        password.append(random.choice(symbols))

    random.shuffle(password)
    print(''.join(password))

    generate_again = input("Generate again (y/n): ").lower()
    if generate_again == 'y':
        passwordGenerator()
    else:
        return False

passwordGenerator()