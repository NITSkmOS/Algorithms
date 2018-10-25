# Function to do selection sort of given array(Arr)
def selection_sort(Arr):
    for i in range(len(Arr)):
        low = i;
        for j in range(i+1, len(Arr)):
            if Arr[j] < Arr[low]:
                low = j
        Arr[i], Arr[low] = Arr[low], Arr[i]

# Given array
Arr = [4, 3, 42, 82, 5, 2, 33]

print("The unsorted array is:")
print(Arr)

# Calling selection sort algorithm
selection_sort(Arr)

print("The sorted array is:")
print(Arr)
