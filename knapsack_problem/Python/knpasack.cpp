#include <bits/stdc++.h> 
using namespace std;
 
// Returns the maximum value that can be placed in knapsack
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int Knap[n + 1][W + 1];
 
    // Build Knap[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                Knap[i][w] = 0;
            else if (wt[i - 1] <= w)
                Knap[i][w]= max(val[i - 1] + Knap[i - 1][w - wt[i - 1]], Knap[i - 1][w]);
            else
                Knap[i][w] = Knap[i - 1][w];
        }
    }
 
    return Knap[n][W];
}
 
int main()
{
    cout << "Enter the number of items in a Knapsack basket:";
    int n, w;
    cin >> n;
    int val[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight" << i << ":";
        cin >> val[i];
        cin >> weight[i];
    }
 
    
    cout << "Enter the capacity of knapsack";
    cin >> w;
    cout << knapSack(w, weight, val, n);
 
    return 0;
}
