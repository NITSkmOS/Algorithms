"""
Bubble Sort Algorthm
"""


def bubble_sort(arr):
    """
    Function to do bubble sort.

    :param arr: A list of element to sort.
    """
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


def main():
    arr = [6, 5, 4, 3, 2, 1]
    print('Sorted element using Bubble Sort: {}'.format(
              ' '.join(map(str, bubble_sort(arr)))))


if __name__ == '__main__':
    main()
