
def binarySearch (arr, l, r, key): 
	"""
    Fuction to do binary search.

    :param 
    	arr: A sorted list of elements,
    	l: indekey of left pointer
    	r: indekey of right pointer
    	key: 
    """
  
    # Check base case 
	if r >= l:
		mid = int(l + (r - l)/2)
  
		# If element is present at the middle itself 
		if arr[mid] == key: 
			return mid 
          
       	# If element is smaller than mid, then it  
        # can only be present in left subarray 
		elif arr[mid] > key: 
			return binarySearch(arr, l, mid-1, key) 
  
        # Else the element can only be present  
        # in right subarray 
		else: 
			return binarySearch(arr, mid+1, r, key) 
	else: 
        # Element is not present in the array 
		return -1

  
def main():
	# Test array 
	arr = [ 2, 3, 4, 10, 40 ] 
	key = 10
  
	# Function call 
	result = binarySearch(arr, 0, len(arr)-1, key) 
	  
	if result != -1: 
	    print("Element is present at index %d" % result)
	else: 
	    print("Element is not present in array")


if __name__ == "__main__":
	main()