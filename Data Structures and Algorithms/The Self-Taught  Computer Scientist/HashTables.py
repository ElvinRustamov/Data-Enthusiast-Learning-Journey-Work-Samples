# A hash table is a linear data structure that stores key- value pairs with unique keys,
## which means you cannot store duplicate keys in a hash table.


###  Characters in a String
def count_chracter(sample_string):
    dict_ = {}
    for char in sample_string:
        if char in dict_:
            dict_[char] += 1
        else:
            dict_[char] = 1
    print(dict_)

count_chracter("Hello, how are you ?")


### Two Sum
def two_sum(numbers, target):
    dict_ = {}
    for idx, n in enumerate(numbers):
        rem = target - n
        if rem in dict_:
            return idx, dict_[rem]
        else:
            dict_[n] = idx

two_sum_test = two_sum([-1, 2, 3, 4, 7], 5)
print(two_sum_test)