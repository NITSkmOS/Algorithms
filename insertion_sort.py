a = []

for i in range(0,5):
    b = int(input())
    a.append(b)


n = len(a)

for i in range(1,n):
    key = a[i]
    j = i-1
    while(j>=0 and key< a[j]):
        a[j+1] = a[j]
        j=j-1
    a[j+1] = key

print(a)
