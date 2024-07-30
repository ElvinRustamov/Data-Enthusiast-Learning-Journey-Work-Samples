# A merge sort is an example of a divide-and-conquer algorithm.
# Time complexity is O(n * log n)

def merge_sort(l):
    if len(l) > 1:
        mid = len(l) // 2
        left_half = l[:mid]
        right_half = l[mid:]
        merge_sort(left_half)
        merge_sort(right_half)

        left_ind = 0
        right_ind = 0
        l_ind = 0
        while left_ind < len(left_half) and right_ind < len(right_half):
            if left_half[left_ind] <= right_half[right_ind]:
                l[l_ind] = left_half[left_ind]
                left_ind += 1
            else:
                l[l_ind] = right_half[right_ind]
                right_ind += 1
            l_ind += 1

        while left_ind < len(left_half):
            l[l_ind] = left_half[left_ind]
            left_ind += 1
            l_ind += 1

        while right_ind < len(right_half):
            l[l_ind] = right_half[right_ind]
            right_ind += 1
            l_ind += 1


    return l

l = [6, 3, 9, 2]
sorted_l = merge_sort(l)
print(f"Sorted list: {sorted_l}")