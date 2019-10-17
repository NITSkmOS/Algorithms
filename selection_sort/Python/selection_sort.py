def selection_sort(values):
  for i in range(len(values)):
    mini = min(values[i:]) #find minimum element
    min_index = values[i:].index(mini) #find index of minimum element
    values[i + min_index] = values[i] #replace element at min_index with first element
    values[i] = mini #replace first element with min element
  return values

def main():
  values = [4,2,1,10,5,3,100]
  selection_sort(values)
  print(values)
  
if __name__ == '__main__':
    main()
