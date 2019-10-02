# Python program implementation of Selection Sort

import sys

# Declare static array

Array = [25, 98, 71, 66, 1, 28, 53, 74]

# Traverse through all the elements

for i in range(len(Array)):
    # Find minimum element in unsorted array
    # Assume index i in minimum and look for minimum element
    # in rest of the array. If found change index j is minimum.
    min = i
    for j in range(i+1, len(Array)):
        if Array[min] > Array[j]:
            min = j
    # Swap the minimum element with the first element
    Array[i], Array[min] = Array[min], Array[i]
# Driver Code
print(" Sorted Array: ")
print(Array)
