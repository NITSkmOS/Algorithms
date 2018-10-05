print("************************Linear search*****************************")
arr=list()
n=input("Enter the number of elements : ")
for i in range(int(n)):
	ele=int(input("Element : "))
	arr.append(int(ele))
key=int(input("Enter the key(elemt to be searched): "))
flag=0
for i in range(int(n)):
	if(arr[i]==key):
		print("Element Found at ",  i+1)
		flag=1
if flag==0:
	print("Element not found ")
k=input("************************* Press Enter to Exit****************")

