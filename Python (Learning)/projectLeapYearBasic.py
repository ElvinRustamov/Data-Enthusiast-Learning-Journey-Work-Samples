# Instructions
# Write a program that works out whether if a given year is a leap year. A normal year has 365 days, leap years have 366, with an extra day in February.

# Three criteria must be taken into account to identify leap years:

# This is how you work out whether if a particular year is a leap year.

#The year must be evenly divisible by 4; If the year can also be evenly divided by 100, it is not a leap year; **unless** the year is also evenly divisible by 400 e.g. The year 2000:

# 2000 ÷ 4 = 500 (Leap)

# 2000 ÷ 100 = 20 (Not Leap)

# 2000 ÷ 400 = 5 (Leap!)

# So the year 2000 is a leap year.

def leapYear():
    year = int(input("Year: "))
    if (year % 4 == 0) and (year % 400 == 0):
        print(f'Leap Year. Input: {year}')
    elif (year % 4 == 0) and (year % 100 != 0):
        print(f'Leap Year. Input: {year}')
    else:
        print(f'Not leap Year. Input: {year}')

leapYear()

