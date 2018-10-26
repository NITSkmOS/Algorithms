# Element style: gcd(a,b)-> a*x + b*y = r = gcd(a,b)

# Inverse of elements if gcd(a,b)==1:
# * a^-1 mod (b) = x mod(b)
# * b^-1 mod (a) = y mod(a)

# Naming is according to Bézout's identity, matching to that on Wikipedia


def extended_euclidean_gcd(a, b):
    x, y, u, v = 0, 1, 1, 0
    while a != 0:
        q, r = b//a, b % a
        m, n = x-u*q, y-v*q
        b, a, x, y, u, v = a, r, u, v, m, n

    gcd = b
    return gcd, x, y


def main():
    a, b = 26, 15
    gcd, x, y = extended_euclidean_gcd(a, b)
    print("GCD of {} and {} is {}".format(a, b, gcd))
    print("The Equation : {}*{} + {}*{} = {}".format(a, x, b, y, gcd))


if __name__ == '__main__':
    main()
