def bubble_sort(a):
    """
        Function to sort the elements in an array

        :param a: A list of elements to sort using bubble sort algorithm
        Complexity: O(n^2)
    """
    for x in range(len(a)-1, 0, -1):
        for i in range(x):
            if a[i] > a[i+1]:
                temp = a[i]
                a[i] = a[i+1]
                a[i+1] = temp
    return a


A1 = [int(x) for x in input("Enter elements in the list: ").split()]
bubble_sort(A1)
s = " ".join(map(str, A1))
print("Your sorted list is:", s)
