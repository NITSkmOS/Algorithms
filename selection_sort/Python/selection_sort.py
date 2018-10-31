def selection_sort(arr):
    for i in range(len(arr)):
        min_i = min(arr[i:]) 
        min_index = arr[i:].index(min_i) 
        arr[i + min_index] = arr[i] 
        arr[i] = min_i
    sorted_arr = arr
    return sorted_arr

def main():
    arr = [2, 3, 0, 4]
    sorted_arr = selection_sort(arr)
    print(sorted_arr)

    
if __name__ == '__main__':
    main()
