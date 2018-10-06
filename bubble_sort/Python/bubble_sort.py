def bubble_sort(a_list):
    for n in range(len(a_list)-1,0,-1):
        for k in range(n):
            if a_list[k] > a_list[k+1]:
                temp = a_list[k]
                a_list[k] = a_list[k+1]
                a_list[k+1] = temp
    return a_list

def main():
    arr = [2, 3, 0, 4]
    sorted_arr = bubble_sort(arr)
    print(sorted_arr)


if __name__ == '__main__':
    main()
