"""
Here Maximum SubArray problem has been implemented on the Share
Market Data Analysis. Where prices of every day has been given.
We have to find the buying and selling day so that the profit will
be maximum. Here the Divide and Conquer method is used and
time-complexity is O(nlogn).For more information visit-
<https://en.wikipedia.org/wiki/Maximum_subarray_problem>
"""


def max_sub_array(arr, low, high):
    """
    Method to find maximum sub array.

    :param low: kjndn
    :param high: kjndknfg
    """
    if low == high:
        # if there is only one day
        return low, low + 1, arr[low]

    else:
        mid = int((low + high) / 2)
        # ll, lh, ls are respectively left-low, left-high, left-sum
        # rl, rh, rs are respectively right-low, right-high, right-sum
        # cl, ch, cs are respectively cross-low, cross-high, cross-sum

        ll, lh, ls = max_sub_array(arr, low, mid)
        rl, rh, rs = max_sub_array(arr, mid + 1, high)
        cl, ch, cs = cross_sub_array(arr, low, mid, high)

        max_sum = max(ls, rs, cs)

        if max_sum is ls:
            return ll, lh, ls
        elif max_sum is rs:
            return rl, rh, rs
        else:
            return cl, ch, cs


def cross_sub_array(arr, low, mid, high):
    """
    :param mid: lsum is left sum
    """
    lsum = -10000
    sum = 0
    maxl = mid
    maxr = mid + 1
    for i in range(mid, low - 1, -1):
        sum = sum + arr[i]
        if sum > lsum:
            lsum = sum
            maxl = i

    # rsum is right sum
    rsum = -10000
    sum = 0
    for i in range(mid + 1, high + 1):
        sum = sum + arr[i]
        if sum > rsum:
            rsum = sum
            maxr = i + 1
    return maxl, maxr, (lsum + rsum)


def main():
    # price is array of the prices where each index of array
    # represents the day.
    # price_difference is array of profit(either +ve or -ve)

    price = [4, 9, 5, 13, 16, 7, 8]

    if len(price) <= 1:
        print('Same day purchase and sell.So no profit.')
        return

    price_difference = []
    for day in range(1, len(price)):
        price_difference.append(price[day] - price[day - 1])

    # l is day of purchasing
    # h is day of selling
    # s is profit

    l, h, s = max_sub_array(price_difference, 0, (len(price_difference) - 1))
    if s < 0:
        # if it happens that price drops and never rises to
        # the price when it was purchased

        print('No days found to get profit')
    else:
        # To be more real-life oriented we start counting from day-1 instead of
        # day-0

        print('Day of Purchase:', l + 1,
              '\nDay of Selling:', h + 1,
              '\nProfit:', s)


if __name__ == '__main__':
    main()
