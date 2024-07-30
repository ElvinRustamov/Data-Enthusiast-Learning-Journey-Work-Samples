# Time complexity is O(n).

def linear_search(a_list, n):
    for i in a_list:
        if i == n:
            return True
    return False

a_list = [1, 8, 32, 91, 5, 15, 100, 24]
print(linear_search(a_list, 91))
