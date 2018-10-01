a = []

for i in range(0,5):
    b = int(input())
    a.append(b)


n = len(a)

for i in range(n):
    min_element = i

    for j in range(i+1,n):
        if(a[min_element]>a[j]):
            min = j
    a[i],a[min_element] = a[min_element],a[i]


print(a)
