def heapify(arr, n, var):
    """
    Recursive function to rearrange a heap to maintain the heap property.
    Heap Property:  The key of the root node is greater or less than
                    or equal to the keys of its children.
    :param arr: A list of element to heapify.
    :param n:   Size of heap.
    :param var: To heapify subtree rooted at index.
    """
    highest = var
    left = (2*var)+1
    right = (2*var)+2

    if left < n and arr[var] < arr[left]:
        highest = left

    if right < n and arr[highest] < arr[right]:
        highest = right

    if highest != var:
        arr[var], arr[highest] = arr[highest], arr[var]

        heapify(arr, n, highest)


def heapSort(arr):
    """
    The main function to implement Heap Sorting Algorithm.
    <https://en.wikipedia.org/wiki/Heapsort>

    :param arr: A list of element to sort.
    """
    n = len(arr)
    for i in range(n, -1, -1):
        heapify(arr, n, i)

    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

    return arr


def main():
    arr = [15, 12, 36, 63, 96]
    print('Sorted elements using Heap Sort: {}'.format(
              ' '.join(map(str, heapSort(arr)))))


if __name__ == '__main__':
    main()
