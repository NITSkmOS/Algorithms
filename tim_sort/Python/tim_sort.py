
def tim_sort(arr):  # Function that performs the tim sort
   arr.sort()


def main():
    arr = [12, 96, 24, 48, 36, 60, 84, 72]    # Declaring a sample array
    tim_sort(arr)  # Calling the bubbleSort function and passing the array
    print('Sorted array is: {}'.format(' '.join(map(str, arr))))


if __name__ == '__main__':
    main()