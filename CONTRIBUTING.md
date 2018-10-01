# Contributing

## Code of Conduct

### Our Pledge

In the interest of fostering an open and welcoming environment, we as
contributors and maintainers pledge to making participation in our project
and our community a harassment-free experience for everyone, regardless of
age, body size, disability, ethnicity, gender identity and expression, level
of experience, nationality, personal appearance, race, religion, or sexual
identity and orientation.

### Our Standards

Examples of behavior that contributes to creating a positive environment
include:

* Using welcoming and inclusive language
* Being respectful of differing viewpoints and experiences
* Gracefully accepting constructive criticism
* Focusing on what is best for the community
* Showing empathy towards other community members

Examples of unacceptable behavior by participants include:

* The use of sexualized language or imagery and unwelcome sexual attention or
  advances
* Trolling, insulting/derogatory comments, and personal or political attacks
* Public or private harassment
* Publishing others' private information, such as a physical or electronic
  address, without explicit permission
* Other conduct which could reasonably be considered inappropriate in a
  professional setting

### Our Responsibilities

Project maintainers are responsible for clarifying the standards of acceptable
behavior and are expected to take appropriate and fair corrective action in
response to any instances of unacceptable behavior.

Project maintainers have the right and responsibility to remove, edit, or
reject comments, commits, code, wiki edits, issues, and other contributions
that are not aligned to this Code of Conduct, or to ban temporarily or
permanently any contributor for other behaviors that they deem inappropriate,
threatening, offensive, or harmful.

## Samples Code

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

## Write Good Commit Messages

A commit message consists of 3 parts:
- shortlog
- commit body
- issue reference
Example:
```
quicksort.py Add QuickSort Algorithm

This adds QuickSort Algorithm which return the concatenation of the
quicksorted list of elements that are less than or equal to the pivot, the
pivot, and the quicksorted list of elements that are greater than the pivot.

Closes https://github.com/NITSkmOS/Algorithms/issues/2
```

### Shortlog

Example:
```
quicksort.py: Add QuickSort Algorithm
```
- **Maximum of 50 characters.**

  Keeping subject lines at this length ensures that they are readable, and
  explains the change in a concise way.
- Should describe the change - the action being done in the commit.
- Should not include WIP prefix.
- Should have a tag and a short description separated by a colon (`:`)
  - **Tag**
    - The file or class or package being modified.
    - Not mandatory.

  - **Short Description**
    - Starts with a capital letter.
    - Written in imperative present tense (i.e. `Add something`, `not Adding
    something` or `Added something`).
    - No trailing period.

### Commit Body

Example:
```
This adds QuickSort Algorithm which return the concatenation of the
quicksorted list of elements that are less than or equal to the pivot, the
pivot, and the quicksorted list of elements that are greater than the pivot.
```
- Maximum of 72 chars excluding newline for each line.

  The recommendation is to add a line break at 72 characters, so that Git has
  plenty of room to indent text while still keeping everything under 80
  characters overall.
- Not mandatory - but helps explain what you’re doing.

- Should describe the reasoning for your changes. This is especially important
for complex changes that are not self explanatory. This is also the right place
to write about related bugs.
- First person should not be used here.

### Issue reference

Example:
```
Closes https://github.com/NITSkmOS/Algorithms/issues/2
```
- Should use the `Fixes` keyword if your commit fixes a bug, or `Closes` if it
adds a feature/enhancement.
- In some situations, e.g. bugs overcome in documents, the difference between
`Fixes` and `Closes` may be very small and subjective. If a specific issue may
lead to an unintended behaviour from the user or from the program it should be
considered a bug, and should be addresed with `Fixes`. If an issue is labelled
with `bug` you should always use `Fixes`. For all other issues use `Closes`.
- Should use full URL to the issue.
- There should be a single space between the `Fixes` or `Closes` and the URL.

```
Note:

- The issue reference will automatically add the link of the commit in the
issue.
- It will also automatically close the issue when the commit is accepted into
repository.
```

## Scope

This Code of Conduct applies both within project spaces and in public spaces
when an individual is representing the project or its community. Examples of
representing a project or community include using an official project e-mail
address, posting via an official social media account, or acting as an
appointed representative at an online or offline event. Representation of a
project may be further defined and clarified by project maintainers.

## Enforcement

Instances of abusive, harassing, or otherwise unacceptable behavior may be
reported by contacting the project team at <nitsikkimcodingclub@gmail.com>. All
complaints will be reviewed and investigated and will result in a response that
is deemed necessary and appropriate to the circumstances. The project team is
obligated to maintain confidentiality with regard to the reporter of an
incident. Further details of specific enforcement policies may be posted
separately.

Project maintainers who do not follow or enforce the Code of Conduct in good
faith may face temporary or permanent repercussions as determined by other
members of the project's leadership.
