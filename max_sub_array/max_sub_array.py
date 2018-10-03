def max_sub_array_sum(a, size):
    max_so_far = -9999999 - 1
    max_ending_here = 0
    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here
        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far
a = [-2, -3, 4, -1, -2, 1, 5, -3]
print("Maximum contiguous sum is", max_sub_array_sum(a, len(a)))
