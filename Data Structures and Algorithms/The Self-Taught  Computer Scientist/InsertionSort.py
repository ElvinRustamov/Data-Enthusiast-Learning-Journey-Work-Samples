# Time complexity is O(n**2)

def insertion_sort(l):
    for i in range(1, len(l)):
        value = l[i]
        while i > 0 and l[i - 1] > value:
            l[i] = l[i - 1]
            i = i - 1
        l[i] = value
    return l

l = [6, 5, 8, 2]
sorted_l = insertion_sort(l)
print(f"Sorted list: {sorted_l}")