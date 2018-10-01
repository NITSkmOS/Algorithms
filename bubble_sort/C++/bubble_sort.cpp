#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubble_sort(vector<T>& arr)
{
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for(size_t i = 1; i < arr.size(); i++)
        {
            if(arr[i-1] > arr[i])
            {
                swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
    }
}

int main()
{
    vector<int> arr = {3,1,2,5,4,6};
    bubble_sort(arr);

    for(auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
