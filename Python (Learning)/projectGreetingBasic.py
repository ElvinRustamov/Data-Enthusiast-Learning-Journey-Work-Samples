# Instruction
# Write a program that uses input to prompt a user for their name and then welcomes them.

user_name = input('Write your name: ')

def greeting_project(user_name='Guest'):
    print(f'Hello {user_name}.\nWellcome to the Python')

# First Case: Give a parameter
greeting_project(user_name)

print('**'*20)

# Second Case:
greeting_project()