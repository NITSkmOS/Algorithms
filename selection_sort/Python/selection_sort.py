
def selectionsort(ar):
    for i in range(len(ar)):
        min = i
        for j in range(i+1,len(ar)):
            if(ar[j] < ar[min]):
                min = j
        ar[i],ar[min] = ar[min],ar[i]
    return ar

def main():
    ar = [5,-1,13,1,22,3,0,3]
    sorted_arr = selectionsort(ar)
    print(sorted_arr)

if __name__ == '__main__':
    main()
