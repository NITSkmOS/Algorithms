def selectionsort( aList ):
  for i in range( len( aList ) ):
    least = i
    for k in range( i + 1 , len( aList ) ):
      if aList[k] < aList[least]:
        least = k

    swap( aList, least, i )


def swap( A, x, y ):
  tmp = A[x]
  A[x] = A[y]
  A[y] = tmp
l=[]
size=int(input("enter size of array: "))
for i in range(size):
	x=int(input("enter element: "))
	l.append(x)

selectionsort(l)
print(l)
