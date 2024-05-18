# Initialize an empty list to store sorted elements
new_arr = []


def selectionSort(l: list):
    """
    Recursively sorts a list using the selection sort algorithm and stores the sorted elements in new_arr.

    Args:
        l (list): The list to be sorted.

    The function works by finding the minimum element in the list, removing it from the list,
    and appending it to new_arr. This process is repeated recursively until the original list is empty.
    """
    # Assume the first element is the minimum
    element = l[0]
    idx = 0

    # Iterate over the list to find the actual minimum element
    for i in range(len(l)):
        if element > l[i]:
            element = l[i]
            idx = i

    # Remove the minimum element from the list and append it to new_arr
    new_arr.append(l.pop(idx))

    # If the list is empty, the sorting process is complete
    if l == []:
        print("Process finished.")
    else:
        # Recursively call selectionSort to sort the remaining elements
        selectionSort(l)


# Sample list to sort
sample_list = [5, 3, 2, 10, 9, 8]

# Call the selectionSort function with a copy of the sample list
selectionSort(sample_list.copy())

# Print the original and sorted lists
print(f"Original list: {sample_list}")
print(f"After Sorting: {new_arr}")