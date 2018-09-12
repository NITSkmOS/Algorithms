def euclidean_gcd(first, second):
    """
    Calculates GCD of two numbers using the division-based Euclidean Algorithm
    :param first:   First number
    :param second:  Second number
    """
    while(second):
        first, second = second, first % second
    return first


def main():
    first, second = map(int, input('Enter 2 integers: ').split())
    print('GCD of {} and {} is: {}'.format(first,
                                           second,
                                           euclidean_gcd(first, second)))


if __name__ == '__main__':
    main()
