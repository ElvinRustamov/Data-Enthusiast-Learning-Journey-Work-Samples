# Instruction
# Write a program which calculates trip cost for a user.

# Step 1: Create a greeting for your program.
# Step 2: Ask the user for number of days.
# Step 3: Ask the user for hotel price.
# Step 4: Ask the user for flight price.
# Step 5: Ask the user for rental car price.
# Step 6: Ask for other expenses.
# Step 7: Combine all expenses together and print with 2 digits after decimal places.

def tripCostCalculator():
    print("Welcome to the Trip Cost Calculator!")
    days = input("How many days will you stay? ")
    hotel_cost = input("How much does hotel cost per night? $")
    flight_cost = input("How much does flight cost? $")
    rental_car = input("If you need rental car please enter the price otherwise enter zero (daily). $")
    other = input("Enter other possible expenses $")

    total = float(days) * float(hotel_cost) + float(flight_cost) + float(days) * float(rental_car) + float(other)
    print(f"Total Cost: ${round(total, 2)}")

tripCostCalculator()