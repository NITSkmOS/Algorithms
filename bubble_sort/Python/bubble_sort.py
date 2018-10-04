
# bubble sort function
def bubbleSort(alist):
    for num in range(len(alist)-1,0,-1):
        for i in range(num):
            if alist[i]>alist[i+1]:
                temp = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = temp


# main function 
def main():
    alist = [54,26,93,17,77,31,44,55,20]
    bubbleSort(alist)
    print(alist)