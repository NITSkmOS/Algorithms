
def selection(sort_list):
    for j in range(len(sort_list)):
        smallest_element = min(sort_list[j:])
        index = sort_list.index(smallest_element)
        sort_list[j], sort_list[index] = sort_list[index], sort_list[j]
    print('\n\nThe sorted list: \t', sort_list)
    print('\n')


array_list = []
size = int(input("Enter size of the list: "))

for i in range(size):
    elements = int(input("Enter an element: "))
    array_list.append(elements)

selection(array_list)
