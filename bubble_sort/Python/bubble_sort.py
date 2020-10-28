def BubbleSort(arr):  # Function that performs the bubbleSort
    """
    The BubbleSort funtion takes an array as an argument
    and then sorts the elements present in that array.
    :param arr: A array for sorting
    """
    n = len(arr)  # Finding the length of the array using the len function

    for i in range(n):  # Traverse through all array elements
        for j in range(0, n-i-1):  # Traverse the array from 0 to n-i-1
            if arr[j] > arr[j+1]:  # Swap if the element found
                arr[j], arr[j+1] = arr[j+1], arr[j]  # greater than next element


def main():
    arr = [12, 96, 24, 48, 36, 60, 84, 72]    # Declaring a sample array
    BubbleSort(arr)  # Calling the bubbleSort function and passing the array
    print('Sorted array is: {}'.format(' '.join(map(str, arr))))


if __name__ == '__main__':
    main()
