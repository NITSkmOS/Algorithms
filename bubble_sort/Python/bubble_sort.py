
def bubble_sort(arr):
    length = len(arr)
    for i in range(length):
        for j in range(0, length-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


def main():
    arr = [1, 5, 0, 4, 2]
    sorted_arr = bubble_sort(arr)
    print(sorted_arr)


if __name__ == '__main__':
    main()
