def bubbleSort(theList):
    for num in range(len(theList)-1,0,-1):
        for i in range(num):
            if theList[i]>theList[i+1]:
                temp = theList[i]
                theList[i] = theList[i+1]
                theList[i+1] = temp

somelist = [14,2,-1,77,2222,6]

bubbleSort(somelist)
print(somelist)
