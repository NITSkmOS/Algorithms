def combsort(numbers_list):
	ordered = numbers_list.copy()
	gap = len(numbers_list) # initial gap (first and last element)
	swaps = True
	while swaps or gap!=1: 
		swaps = False
		for i in range(len(numbers_list)-gap):
			if ordered[i] > ordered[i+gap]: # swaps without extra variable
				ordered[i] = ordered[i+gap] - ordered[i]
				ordered[i+gap] = ordered[i+gap] - ordered[i]
				ordered[i] = ordered[i+gap] + ordered[i]
				swaps = True
		gap = max(gap-1, 1)	# update gap, minimum gap is 1
	return ordered

def main():
    arr = [12, 96, 24, 48, 36, 60, 84, 72]    # Declaring a sample array
    combsort(arr)  # Calling the combsort function and passing the array
    print('Sorted array is: {}'.format(' '.join(map(str, arr))))


if __name__ == '__main__':
    main()
