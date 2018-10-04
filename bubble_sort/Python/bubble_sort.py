""" Python code to bubble sort an array """


def bubble_sort(a, l):  # Function to bubble sort a given array
    for i in range(l):
        for j in range(l-i-1):
            if a[j] > a[j+1]:  # Checking for the greater number
                a[j], a[j+1] = a[j+1], a[j]  # Swapping if condition satisfied


length = int(input("Enter the length of array:"))  # Input length of array
array = []  # creating an empty array
print("Enter the array:")  # Taking the input for array
for p in range(length):
    num = int(input())
    array.append(num)

bubble_sort(array, length)  # Calling the bubble_sort function
print("Sorted array:")
for p in range(length):     # Printing the sorted array
    print(array[p])
