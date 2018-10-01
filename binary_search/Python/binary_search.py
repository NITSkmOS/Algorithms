def binary_search(arr, key):
    """
    Function to search an element `key` in `arr` array.

    :param arr: A list of element to sort.
    :param key: Element to search in the given `arr` list
    """
    left = 0
    right = len(arr)-1
    while left <= right:
        mid = int(left + (right-left)/2)
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            left = mid+1
        else:
            right = mid-1

    return -1


def main():
    arr = [1, 2, 3, 4, 5, 6]
    key = 5
    print("Index of " + str(key) + " in the array: ",
          str(binary_search(arr, key)))
    key = 8
    print("Index of " + str(key) + " in the array: ",
          str(binary_search(arr, key)))


if __name__ == '__main__':
    main()
