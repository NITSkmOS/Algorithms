def bubbleSort(arr,lim):
    for i in range(lim):
        for j in range(0,lim-i-1):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]

limit=int(input("Enter the limit:"))
array=[]
print ("Enter the numbers:")

for i in range(limit):
    temporary=int(input())
    array.append(temporary)
print("Unsorted array :", array)

bubbleSort(array,limit)

print("Sorted array :", array)    
