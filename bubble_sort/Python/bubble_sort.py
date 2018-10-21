def Bubble_Sort(array):
    """function takes an array as an argument and sorts it."""
    for i in range(len(array)):
        for j in range(len(array) - 1):
            if array[j] > array[j + 1]:
                temp = array[j + 1]
                array[j + 1] = array[j]
                array[j] = temp

    return array


print(Bubble_Sort([2, 4, 3, 5, 1]))
