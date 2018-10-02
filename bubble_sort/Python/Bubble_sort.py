def bubble_sort(mas):
    for i in range(len(mas)):
        for j in range(len(mas) - 1, i, -1):
            if mas[j] < mas[j-1]:
                mas[j], mas[j-1] = mas[j-1], mas[j]
    return mas
print(bubble_sort([4, 3, 2, 1]))
