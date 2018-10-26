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
