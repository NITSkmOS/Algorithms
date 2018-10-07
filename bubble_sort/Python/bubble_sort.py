def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp


def bubble_sort(arr, n):
    i = 0
    j = 0
    swapped = False
    for i in range(n):
        for j in range(n-i-1):
            if (arr[j] > arr[j+1]):
                swap(arr, j, j+1)
                swapped = True
			
        if (swapped == False):
            break
	


#Function to print an array
def print_array(arr, size):
    for i in range(size):
        print(arr[i], end=" ")
    print()

#Driver program to test above functions
def main():
    arr = [64, 34, 25, 12, 22, 11, 90]
    n = len(arr)
    bubble_sort(arr, n)
    print("Sorted array: ")
    print_array(arr, n)
    return 0
main()
