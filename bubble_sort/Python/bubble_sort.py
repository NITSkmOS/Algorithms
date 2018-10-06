def bubble_sort(arr):
    """
    Function to sort a list of integers using bubble sort algorithm
    """
    for i in range(len(arr)-1):
        for j in range(len(arr)-i-1):
            if arr[j] > arr[j+1]:
                tmp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = tmp

    return arr


def main():
    arr = [3, 1, 4, 2, 5]
    sorted_arr = bubble_sort(arr)
    print("Sorted array: ")
    for i in sorted_arr:
        print(i, end=" ")


if __name__ == '__main__':
    main()
