# Instruction
# Create an encrypt function which takes two parameters : message and shift number. Then inside this function shift each letter of the message forwards in the alphabet by the shift number and return encrypted text.
# Create an decrypt function which takes two parameters : message and shift number. Then inside this function shift each letter of the message backwards in the alphabet by the shift number and return decrypted text.

class Cryptography:
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    def __init__(self):
        self.txt = input('Write your message: ').lower()

        self.shift_number = input("Shift number: ")
        while True:
            if self.shift_number.isdigit():
                self.shift_number = int(self.shift_number)
                break
            else:
                print("Error, write a number.")
                self.shift_number = input("Shift number: ")

        self.method = input("Encryption or Decryption (e/d): ").lower()
        while True:
            if self.method in ['e', 'd']:
                break
            else:
                print("Error, write method correctly (e or d)!")
                self.method = input("Encryption or Decryption (e/d): ").lower()

        self.convert_txt()

    def convert_txt(self):
        new_text = ''
        if self.method == 'e':
            for l in self.txt:
                if self.alphabet.find(l) != -1:
                    if self.alphabet.find(l) + self.shift_number > len(self.alphabet):
                        new_text += self.alphabet[(self.alphabet.find(l) + self.shift_number) - len(self.alphabet)]
                    else:
                        new_text += self.alphabet[self.alphabet.find(l) + self.shift_number]
                else:
                    new_text += l
        elif self.method == 'd':
            for l in self.txt:
                if self.alphabet.find(l) != -1:
                    if self.alphabet.find(l) - self.shift_number < 0:
                        new_text += self.alphabet[len(self.alphabet) - (self.shift_number - self.alphabet.find(l))]
                    else:
                        new_text += self.alphabet[self.alphabet.find(l) - self.shift_number]
                else:
                    new_text += l
        print(new_text)

Cryptography()

