def bubble_sort(lst):
	for i in range(0, len(lst)):
		swap = False
		for j in range(0, len(lst)-1):
			if lst[j] > lst[j+1]:
				aux = lst[j]
				lst[j] = lst[j+1]
				lst[j+1] = aux
				swap = True
		if not swap:
			break

	return lst


test = [10, 666, 250, 3, 75, 9, 100, 99, 0]

print("Unordered list: " + str(test))

test = bubble_sort(test)

print("Ordered list: " + str(test))