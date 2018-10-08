def radix_sort(array, base=10):
    """
    Fuction to sort using radix sort algorithm
    <https://en.wikipedia.org/wiki/Radix_sort>.

    :param array:   A list of elements to sort.
    :param base:    Integer number to represent base number
    """
    maxLen = len(str(max(array)))

    for i in range(maxLen):
        digit_ref = [[] for _ in range(base)]
        for num in array:
            digit_ref[(num // base ** i) % base].append(num)
        array = []
        for section in digit_ref:
            array.extend(section)
    return array


def main():
    array = [6, 5, 4, 3, 2, 1]
    print('Sorted element using Radix Sort: {}'.format(
              ' '.join(map(str, radix_sort(array)))))


if __name__ == '__main__':
    main()
