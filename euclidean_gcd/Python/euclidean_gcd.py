def euclidean_gcd(first, second):
    """
    Calculates GCD of two numbers using the division-based Euclidean Algorithm
    :param first:   First number
    :param second:  Second number
    """
    while(second):
        first, second = second, first % second
    return first


def euclidean_gcd_recursive(first, second):
    """
    Calculates GCD of two numbers using the recursive Euclidean Algorithm
    :param first:   First number
    :param second:  Second number
    """
    if not second:
        return first
    return euclidean_gcd_recursive(second, first % second)


def main():
    inp = '20 30'
    first, second = map(int, inp.split())
    print('Division-based: GCD of {} and {} is: {}'.format(first,
                                                           second,
                                                           euclidean_gcd(
                                                               first, second)))
    print('Recursive: GCD of {} and {} is: {}'.format(first,
                                                      second,
                                                      euclidean_gcd_recursive(
                                                          first, second)))


if __name__ == '__main__':
    main()
