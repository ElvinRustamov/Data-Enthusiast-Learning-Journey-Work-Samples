# Instruction
# Write a program to prompt the user for hours and rate per hour to compute gross pay. You need to take into account that the result has exactly two digits after the decimal place

def grossPay():
    hours = int(input("Enter Hours: "))
    rate = round(float(input("Enter Rate: ")), 2)

    print(f'Pay: {hours * rate}')

grossPay()
