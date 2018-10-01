"""
QuickSort Algorithm
- If the list is empty, return the list and terminate. - (Base case)
- Choose a pivot element in the list.
- Take all of the elements that are less than or equal to the pivot and use
  quicksort on them.
- Take all of the elements that are greater than the pivot and use quicksort
  on them.
- Return the concatenation of the quicksorted list of elements that are less
  than or equal to the pivot, the pivot, and the quicksorted list of elements
  that are greater than the pivot.
"""


def quicksort(arr):
    """
    Fuction to do quicksort.

    :param arr: A list of element to sort.
    """
    less = []
    pivotList = []
    more = []

    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        for i in arr:
            if i < pivot:
                less.append(i)
            elif i > pivot:
                more.append(i)
            else:
                pivotList.append(i)
        less = quicksort(less)
        more = quicksort(more)
        return less + pivotList + more


def main():
    arr = [6, 5, 4, 3, 2, 1]
    print('Sorted element using Quicksort: {}'.format(
              ' '.join(map(str, quicksort(arr)))))


if __name__ == '__main__':
    main()
