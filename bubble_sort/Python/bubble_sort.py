def bubble_sort(a):
    sorted = False
    while not sorted:
        sorted = True
        for i in range(1, len(a) - 1):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                sorted = False
    return a
