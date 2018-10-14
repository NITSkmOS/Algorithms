def insertion_sort(arr):
    """
    Fuction to do insertion sort.

    :param arr: A list of element to sort.
    """
    for slot in range(1, len(arr)):
        value = arr[slot]
        test_slot = slot - 1
        while test_slot > -1 and arr[test_slot] > value:
            arr[test_slot + 1] = arr[test_slot]
            test_slot = test_slot - 1
        arr[test_slot + 1] = value

    return arr


def main():
    arr = [6, 5, 4, 3, 2, 1]
    print('Sorted element using Insertion Sort: {}'.format(
              ' '.join(map(str, insertion_sort(arr)))))


if __name__ == '__main__':
    main()
