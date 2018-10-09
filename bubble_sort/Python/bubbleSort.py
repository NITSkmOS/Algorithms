#Bubble Sort in Python

array = [] #declaration of array


#getting f user inputs and append that values to the array
for x in range(5):
    array.append(eval(input("number " + "")))

n = len(array) #array length
print(array)  #prints initial array (unsorted)


def bubbleSort(array):
    for j in range(n):
        for i in range((n - 1), j, -1):
            if(array[i] < array[i - 1]):
                temp = array[i]
                array[i] = array[i - 1]
                array[i - 1] = temp


bubbleSort(array)
print(array)
