def counting_sort(arr, digit: int, radix=10):
    """
    Fuction to sort using Counting Sort
    <https://en.wikipedia.org/wiki/Counting_sort>.

    :param arr:     A list of number to sort
    :param digit:   The digit we want to sort by
    :param radix:   The base of the number system
    :return result: The sorted list of given arr list
    """

    arr_len = len(arr)
    count = [0]*radix   # counts the number of occurences of each digit in arr
    result = [0]*arr_len

    def _digit_find(num, digit, radix):
        return int((num / radix ** digit) % radix)

    for i in range(arr_len):
        digit_of_arr_i = _digit_find(arr[i], digit, radix)
        count[digit_of_arr_i] += 1

    for j in range(1, radix):
        count[j] += count[j-1]

    for m in range(arr_len-1, -1, -1):
        digit_of_arr_i = _digit_find(arr[m], digit, radix)
        count[digit_of_arr_i] -= 1
        result[count[digit_of_arr_i]] = arr[m]

    return result


def main():
    arr = [6, 5, 4, 3, 2, 1]
    print('Sorted element using Counting Sort: {}'.format(
              ' '.join(map(str, counting_sort(arr, 0)))))


if __name__ == '__main__':
    main()
