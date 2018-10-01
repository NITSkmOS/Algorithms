"""
Merge Sort Algorthm
- Create an empty list called the result list.
- Do the following until one of the input lists is empty:
    - Remove the first element of the list that has a lesser first element
      and append it to the result list.
- When one of the lists is empty, append all elements of the other list to
  the result.
"""


def _merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change
        # the direction of the sort
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1

    if left:
        result.extend(left[left_idx:])
    if right:
        result.extend(right[right_idx:])
    return result


def merge_sort(arr):
    """
    Fuction to do merge sort.

    :param arr: A list of element to sort.
    """
    if len(arr) <= 1:
        return arr

    middle = len(arr) // 2
    left = arr[:middle]
    right = arr[middle:]

    left = merge_sort(left)
    right = merge_sort(right)
    return list(_merge(left, right))


def main():
    arr = [6, 5, 4, 3, 2, 1]
    print('Sorted element using Merge Sort: {}'.format(
              ' '.join(map(str, merge_sort(arr)))))


if __name__ == '__main__':
    main()
