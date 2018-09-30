a = []

for i in range(0,5):
    b = int(input())
    a.append(b)


n = len(a)

for i in range(n):
    min = i

    for j in range(i+1,n):
        if(a[min]>a[j]):
            min = j
    a[i],a[min] = a[min],a[i]


print(a)
