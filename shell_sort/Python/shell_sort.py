def shellSort(arr):
    gap = int((len(arr)/2))                            #beginning with a big gap. eventually will reduce it by 2 times.
    while gap > 0:                                         #loop controling the gap
        for i in range (gap, len(arr)):             #loop to add a[i] to the elements that have been gap sorted; save a[i] in temp and make a hole at position i 
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp: #loop to shift the elements
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp                              #put the original value
        gap/=2                                           #reducing the gap
        gap = int(gap)
    return arr

def main():
    arr = [15, 12, 36, 63, 96]                      #sample array
    sorted_arr = shellSort(arr)
    print(sorted_arr)                                #printing sample array

#driver code    
if __name__ == '__main__':
    main()