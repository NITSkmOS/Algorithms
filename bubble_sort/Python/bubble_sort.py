
def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

a = [76,74,63,74,24,93,25]

bubbleSort(a)

print("Sorted array is:")
print(a)
