def bubble_sort():
    for i in range(n - 1):  # the last element will be automatically sorted
    
        swapped = False  # swapped is used to reduce the time complexity for best case
        
        for j in range(n - i - 1):  # after each pass i elements will be sorted and comparison will be one less
            # than total no of elements
            
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break


arr = []
n = int(input("How many numbers: "))
for i in range(n):
    arr.append(int(input("Enter number: ")))
bubble_sort()
print("Sorted Array is: ")
print(arr)
