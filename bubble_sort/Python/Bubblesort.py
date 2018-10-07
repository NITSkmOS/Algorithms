def Bubble_sort(arr):
    for j in range(n-1,0,-1):
        for i in range (j):
            if arr[i]>arr[i+1]:
                arr[i],arr[i+1]=arr[i+1],arr[i] //swapping elements
arr=[45,78,3,45,76,78,23]
n=len(arr)
Bubble_sort(arr)
print(arr)
