# Instruction
# Write a program which prompts the user for a Celsius temperature, convert the temperature to Fahrenheit, and print out the converted temperature. Formula : (°C × 9/5) + 32 = °F

def temperatureCoventer():
    celcius = float(input("Enter Temperature in Celsius: "))
    fahrenheit = (celcius * 9 / 5) + 32
    print(f"{celcius} Celsius = {fahrenheit} Fahrenheit")

temperatureCoventer()