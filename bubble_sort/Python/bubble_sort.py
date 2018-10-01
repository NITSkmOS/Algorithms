def bubble_sort(arr, n):
    if (n == 0):
        return arr
    else:
        bubble_swap(arr,0,1,n)
    return bubble_sort(arr, n-1)

def bubble_swap(arr, i, j, n):
    if (j >= n) | (i >= n):
        return arr
    elif (arr[j] < arr[i]):
        arr[i], arr[j] = arr[j], arr[i]
    return bubble_swap(arr,i+1,j+1,n)


def main():
    arr = [64, 34, 25, 12, 22, 11, 90]
    bubble_sort(arr,len(arr))
    print(arr)

if __name__ == '__main__':
    main()