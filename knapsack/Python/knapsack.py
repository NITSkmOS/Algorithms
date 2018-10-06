def knapsack(v, w, n, W):
    '''
    Function solves 0/1 Knapsack problem
    Function to calculate frequency of items to be added to knapsack to maximise value
    such that total weight is less than or equal to W
    :param v: set of values of n objects, first element is useless because relevant values are assumed to begin from index 1
    :param w: set of weights of n objects, first element is useless because relevant weights are assumed to begin from index 1
    :param n: number of items
    :pram W: maximum weight allowd by knapsack
    '''
    m = [[0 for j in range(W+1)] for i in range(n+1)]
    for j in range(W+1):
        m[0][j] = 0

    for i in range(1, n+1):
        for j in range(W+1):
            if w[i]>j:
                m[i][j] = m[i-1][j]
            else:
                m[i][j] = max(m[i-1][j], m[i-1][j-w[i]]+v[i])
    return m[n][W]

def main():
    v = [0, 1, 2, 3, 4, 5]
    w = [0, 5, 6, 2, 3, 4]
    n = 5
    W = 8
    print("Answer to 0/1 Knapsack problem(Maximum value possible in given weight limit): "+str(knapsack(v, w, n, W)))

if __name__ == '__main__':
    main()