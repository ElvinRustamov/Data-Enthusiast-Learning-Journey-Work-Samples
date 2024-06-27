

## Items must be a sorted list.
def binarySearch(items: list, target):
    """
    Perform binary search on a sorted list to find the target element.

    Args:
        items (list): A sorted list of comparable elements.
        target: The element to search for in the list.

    Returns:
        tuple: A tuple containing the number of steps taken to find the target
               and the index of the target in the list. If the target is not found,
               returns (None, None).
    """
    step = 0
    while True:
        mid = len(items) // 2
        if target == items[mid]:
            step += 1
            idx = mid
            return step, idx
        if mid == 0:
            return None, None
        elif target > items[mid]:
            step += 1
            items = items[mid+1:]
        elif target < items[mid]:
            items = items[:mid]
            step += 1

#   For any list of n, binary search will take log2n steps to run in the worst case.
items = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 9
steps, idx = binarySearch(items, target)
print(f"Steps: {steps}, Index of element: {idx}")