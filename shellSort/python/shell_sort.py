def shellSort(arr):
    gap = int((len(arr)/2))
    while gap > 0:
        for i in range (gap, len(arr)):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap/=2  
        gap = int(gap)


def main():
    arr = [15, 12, 36, 63, 96]
    sorted_arr = shellSort(arr)
    print(sorted_arr)

    
if __name__ == '__main__':
    main()