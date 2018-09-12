## Samples

#### C

```c
void quicksort(int ar_size, int *ar) {
    /*
        Your implementation here...
    */
}

int main() {
	int ar_size = 4, i;
	int a[4] = {2, 3, 0, 4};
	quicksort(ar_size, a);

	for (i=0; i<ar_size; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}
```

#### Python

```py
def quicksort(arr):
    #
    # Your implementation here...
    #


def main():
    arr = [2, 3, 0, 4]
    sorted_arr = quicksort(arr)
    print(sorted_arr)

    
if __name__ == '__main__':
    main()
```

#### Java

```java
public class QuickSort {
    
    static void quickSort(int[] a) {
        /*
            Your implementation here...
        */
    }
    
    public static void main(String[] args) {
        int[] arr = new int[] {2, 3, 0, 4};
        quickSort(arr);
        for(int element: arr) {
            System.out.println(element);
        }
    }
}
```

#### Golang

```go
package main

import "fmt"

// QuickSort sorts an array using QuickSort algorithm
func QuickSort(array []int) []int {
    // Your implementation here
    return array
}

func main() {
    array := []int{2, 3, 0, 4}
    sortedArray := QuickSort(array)
    fmt.Println(sortedArray)
}
```

#### JavaScript

```JS
function quickSort (arr) {
	/*
	Your implementation here
	*/
}

function main () {
	let input = [2, 3, 0, 4];
	quickSort(input);
	for (let x in input) {
		console.log(input[x] + ' ');
	}
}

main();
```

#### C#

```csharp
using System;

public class QuickSort
{  
    public static void DoQuickSort(int[] a)
    {
        /*
            Your implementation here...
        */
    }
    
    public static void Main()
    {
        int[] arr = new int[] {2, 3, 0, 4};
        DoQuickSort(arr);
        foreach(int element in arr)
        {
            Console.Write(element + " ");
        }
        Console.WriteLine("");
    }
}
```
