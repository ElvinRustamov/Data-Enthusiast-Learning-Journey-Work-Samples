# Time complexity is O(n**2)

def bubble_sort(l):
    length_list = len(l) - 1
    for i in range(length_list):
        no_swaps = True
        for j in range(length_list - i):
            if l[j] > l[j + 1]:
                l[j], l[j+1] = l[j+1], l[j]
        if no_swaps:
            return l
    return l

list_ = [32, 5, 6, 7]
list_sorted = bubble_sort(list_.copy())
print(f"Original list: {list_}")
print(f"Sorted list: {list_sorted}")
