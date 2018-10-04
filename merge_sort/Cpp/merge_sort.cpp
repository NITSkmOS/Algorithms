#include<iostream>
#include<vector>
using namespace std;


// this code folows c++11 standards

//merging 2 sorted subarrays into one sorted array
vector<int> merging(vector<int> subarr1, vector<int> subarr2)
{

    vector<int> sorted_subarr;


    while(subarr1.size() >0 || subarr2.size()>0) //continue merging as long as one of the subarrays is not empty
    {

        if(subarr1.size() > 0  && subarr2.size() > 0) // if the 2 are not empty, compare their fronts respectively
        {

             if(subarr1.front() <= subarr2.front())
             {
                 sorted_subarr.push_back(subarr1.front());
                 subarr1.erase(subarr1.begin());
             }
             else
             {
                 sorted_subarr.push_back(subarr2.front());
                 subarr2.erase(subarr2.begin());
             }


        }

        else if (subarr1.size()>0) //if one them is not empty , push all its content in the result vector
        {

            for(int i = 0 ; i < subarr1.size() ;i++)
            {
                sorted_subarr.push_back(subarr1[i]);

            }

             break;
        }
        else if(subarr2.size()>0)
        {

             for(int i = 0 ; i < subarr2.size() ;i++)
            {
               sorted_subarr.push_back(subarr2[i]);
            }
            break;

        }

    }

    return sorted_subarr;

}

//merge sort algorithm (recursive divide and conquer

vector<int> merge_sort(vector<int> arr)
{
    if(arr.size() == 1) //base case (there's nothing to divide,if array size = 1  )
        return arr;

    int middle = (arr.size())/2; //get the middle of the array to divide it into 2 subarrays

    vector<int> left,right;


    for(int i = 0 ; i< middle ;i++) // get the left subarray
        left.push_back(arr[i]);


    for(int i = middle ; i< arr.size() ;i++)  //get the right subarray
        right.push_back(arr[i]);

    left = merge_sort(left);       //recursively divide the subarrays to be sorted
    right =  merge_sort(right);

    return merging(left,right);
}

int main()
{

int array_size;
vector<int> arr;
cout<<"enter the size of your array: ";

cin>>array_size;
cout<<"enter array elements: ";

int number;


for(int i = 0 ; i< array_size;i++)
{
    cin>>number;

    arr.push_back(number);
}

vector <int> sorted_array = merge_sort(arr);

for(vector<int>::iterator it = sorted_array.begin(); it!= sorted_array.end();it++)
    cout << *it << ' ';

}

