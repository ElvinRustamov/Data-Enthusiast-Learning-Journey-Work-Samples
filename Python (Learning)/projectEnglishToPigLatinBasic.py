# Instructions
# Like with any new language, it is crucial to learn the formal rules of pig Latin. This not only gives you a solid foundation in the language game, but it also helps you understand its usage. These rules will also come handy if you have a text to translate to pig Latin.
#
# Rules:
#
# 1. If Words Beginning With Consonants:
#   - Move first character from the initial location of that particular word to the last position of the name.
#   - Add a suffix the suffix “-ay” to the end of the word.
# 2. If Words Beginning With Vowels:
#   - Add a suffix the suffix “-yay” to the end of the word.

def english_to_pig_latin():
    txt_new = ''
    txt = input("Write here: ")
    for i in txt.split():
        if i[0].lower() in 'aeiuo':
            txt_new += f"{i}yay "
        else:
            txt_new += f"{i[1:]}{i[0]}ay "
    print(txt_new.strip())

english_to_pig_latin()