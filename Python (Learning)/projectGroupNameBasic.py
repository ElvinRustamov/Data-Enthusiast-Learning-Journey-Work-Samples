# Instruction
# Step 1: Create a greeting for your program.
# Step 2: Ask the user for their favorite color.
# Step 3: Ask the user for their favotire animal.
# Step 4: Combine the name of their favorite color and animal and show them their group name.

def groupName():
    print('Welcome to the Group Name Generator.')
    color = input("What's your favorite color? ")
    animal = input("What's your favorite animal? ")
    print(f"Your group name could be {color.title()} {animal.title()}s")

groupName()