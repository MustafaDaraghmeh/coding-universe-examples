def merge_sort(arr):
    """
    Perform merge sort on the array

    Parameters:
    arr (list of int): The list to be sorted

    Returns:
    list of int: The sorted list
    """

    if len(arr) > 1:

        # Finding the middle of the array
        middle = len(arr)//2

        # Dividing the array elements
        left_half = arr[:middle]
        right_half = arr[middle:]

        # Recursive call on each half
        merge_sort(left_half)
        merge_sort(right_half)

        # Initializers for two subarrays and the merged array
        i = j = k = 0

        # Copy data to temp arrays left_half and right_half
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

    return arr


# Test the function
if __name__ == "__main__":
    array_to_sort = [12, 11, 13, 5, 6, 7]
    print("Original array:", array_to_sort)
    sorted_array = merge_sort(array_to_sort)
    print("Sorted array:", sorted_array)
