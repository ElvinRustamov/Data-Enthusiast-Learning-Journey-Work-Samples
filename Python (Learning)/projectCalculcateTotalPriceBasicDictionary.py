import pprint

def calculate_total_price():
    available_parts = {
        1: 'computer',
        2: 'monitor',
        3: 'keyboard',
        4: 'mouse',
        5: 'hdmi cable',
        6: 'dvd drive',
        0: 'to finish'
    }

    price_quantity = {
    'computer': {'price': 500, 'quantity' : 10},
    'monitor': {'price': 200, 'quantity' : 8},
    'keyboard': {'price': 500, 'quantity' : 5},
    'mouse': {'price': 10, 'quantity' : 0},
    'hdmi cable': {'price': 20, 'quantity' : 7},
    'dvd drive': {'price': 50, 'quantity' : 5}
    }

    print('Please add options from the list: ')
    pprint.pprint(available_parts)
    parts = []
    while True:
        user_input = int(input("Add to basket: "))
        if user_input == 0:
            print("Calculating the price ...")
            break
        else:
            if price_quantity[available_parts[user_input]]['quantity'] == 0:
                print("Sorry, out of stock!")
            else:
                parts.append(user_input)

    total_price = sum([price_quantity[available_parts[i]]['price'] for i in parts])
    print(f"Total price {total_price}$")

    while True:
        calculate_again = input("Calculate again (y/n): ").lower()
        if calculate_again in ['y', 'n']:
            if calculate_again == 'y':
                calculate_total_price()
            else:
                break
        else:
            print("Write y (yes) or n (no).")

calculate_total_price()