def knapsack(profit, weight, capacity):
    """
    Here Knapsack problem has been implemented using Greedy Approach
    where the weight and and corresponding profit of some items has been
    given. And also the maximum capacity of a sack(bag) is given. we have
    to take items so that capacity does not exceed and we get maximum profit.
    For more information visit: <https://en.wikipedia.org/wiki/Knapsack_problem>

    :param profit: array of profit of the items
    :param weight: array of weight of the items
    :param capacity: capacity of the sack
    :return: maximum profit and the fraction of items
    """

    # array of profit/weight ratio
    ratio = [v / w for v, w in zip(profit, weight)]

    # a list of (0, 1, ..., n-1)
    index = list(range(len(profit)))

    # index is sorted according to ratio in descending order
    index.sort(key=lambda i: ratio[i], reverse=True)

    # max_profit is the maximum profit gained
    max_profit = 0

    # fraction is the fraction in which items should be taken
    fraction = [0] * len(profit)

    for i in index:
        if weight[i] <= capacity:
            fraction[i] = 1
            max_profit += profit[i]
            capacity -= weight[i]
        else:
            fraction[i] = capacity / weight[i]
            max_profit += profit[i] * fraction[i]
            break

    return max_profit, fraction


def main():
    # profit is array of profit of the items
    # weight is array of weight of the items
    # capacity is capacity of the sack

    profit = [50, 60, 80]
    weight = [10, 30, 20]
    capacity = 50

    # max_profit is the maximum profit gained
    # fraction is the fraction in which items should be taken
    max_profit, fraction = knapsack(profit, weight, capacity)
    print('Maximum profit:', max_profit)
    print('Items should be taken in fraction of:', fraction)


if __name__ == '__main__':
    main()
