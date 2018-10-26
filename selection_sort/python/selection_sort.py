def selection_sort(arr): # Function that performs the SelectionSort
    """
    - The SelectionSort function takes in an array as argument
    - Sorts the elements in array by making use of inner and outer loops
    - Returns a sorted array as output
    :papram arr: An array for sorting
    """
    n = len(arr) # Length of arr is stored for further use

    for i in range(n): # Traverse through all array elements
        low = i # Set the current element to low
        for j in range(i+1, n):
            """
            Traverse the array from i+1 to n-i as inner loop,
            i.e. i is the counter for outer loop and j for 
            the inner loop
            """
            if arr[j] < arr[low]: # Set low to current j, if it's value is smaller
                low = j
        arr[i], arr[low] = arr[low], arr[i] # Swap element at i with element low


def main():
    arr = [4, 3, 42, 82, 5, 2, 33] # Declare a sample array
    print('Unsorted elements before using SelectionSort: {}'.format(
              ' '.join(map(str, arr)))) # Print current state of array

    selection_sort(arr)
    print('Sorted element using SelectionSort: {}'.format(
              ' '.join(map(str, arr)))) # Print the state of array after selection sorting


if __name__ == '__main__':
    main()
