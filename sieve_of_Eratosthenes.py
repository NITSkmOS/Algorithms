def sieve_of_eratosthenes(n):

    prime = [True] * (n + 1)
    p = 2
    while (p * p <= n):
        # If prime[p] is not changed, then it is a prime
        if (prime[p] is True):
            # Update all multiples of p
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
    # Print all prime numbers
    for p in range(2, n):
        if prime[p]:
            print(p)


if __name__ == '__main__':
    n = 30
    print("Following are the prime numbers smaller than "
          " or equal to {}: {}".format(n, sieve_of_eratosthenes(n))
