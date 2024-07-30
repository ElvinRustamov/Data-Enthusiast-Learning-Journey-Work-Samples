# Binary search works when the data is sorted.
# Time complexity is O(log n).

def binary_search(a_list, n):
    first = 0
    last = len(a_list) - 1
    while last >= first:
        mid = (first + last) // 2
        if a_list[mid] == n:
            return True
        else:
            if n < a_list[mid]:
                last = mid - 1
            else:
                first = mid + 1
    return False

a_list = [1,3, 5, 6, 43, 53, 65, 96, 1003]

print(binary_search(a_list, 96))
print(binary_search(a_list, 55))


def binary_search_character(list_of_character, target):
    first = 0
    last = len(list_of_character) - 1
    while last >= first:
        mid = (first + last) // 2
        if ord(list_of_character[mid]) == ord(target):
            return True
        else:
            if ord(target) < ord(list_of_character[mid]):
                last = mid - 1
            else:
                first = mid + 1
    return False

list_of_character = sorted(['a', 'b', 'c', 'd', 'e', 'w', 's'])
print(binary_search_character(list_of_character, 'w'))
print(binary_search_character(list_of_character, 'z'))