"""
Bubble sort

It is the most common sort algorithm.
It simply finds the first element and place at
the first by comparing all elements.

you should use the sort built in python 
instead of this code.
"""


def bubblesort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr


def main():
    arr = [6, 99, 102, 199, -1, -55, 5, 4, 3, 2, 1, -200]
    print(
        "Sorted element using bubble sort: {}".format(
            " ".join(map(str, bubblesort(arr)))
        )
    )


if __name__ == "__main__":
    main()
