"""
Bubble Sort Algorithm
The bubble sort makes multiple passes through a list.
It compares adjacent items and exchanges those that are out of order.
Each pass through the list places the next largest value in its proper place.
In essence, each item “bubbles” up to the location where it belongs.

A bubble sort is often considered the most inefficient sorting method since it
must exchange items before the final location is known.
These “wasted” exchange operations are very costly.
However, because the bubble sort makes passes through the entire unsorted
portion of the list, it has the capability to do something most sorting
algorithms cannot.
In particular, if during a pass there are no exchanges, then we know that the
list must be sorted.
A bubble sort can be modified to stop early if it finds that the list has
become sorted.
This means that for lists that require just a few passes, a bubble sort may
have an advantage in that it will recognize the sorted list and stop.
"""


def bubbleSort(list):
    """
    Fuction to do bubblesort.

    :param list: A list of element to sort.
    """
    for passnum in range(len(list) - 1, 0, -1):
        for i in range(passnum):
            if list[i] > list[i + 1]:
                temp = list[i]
                list[i] = list[i + 1]
                list[i + 1] = temp


def main():
    list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    bubbleSort(list)
    print(list)


if __name__ == '__main__':
    main()
