#include <iostream>
using namespace std;
//recursion - O(2^n)
//dp solution - O(w*n)
//dp i,j tells maxval for i weight and j number of elements from the last
//we can optimize space if we take dp[i][j] as maxwal for j weight ans i number of elements from last
//then we will require only current row and prev row
int knapsack(int w , int n , int sizes[] , int val[]){
	int dp1[w + 1] , dp2[w + 1];
	int * curr = dp1 , * prev = dp2; //pointers used to swap between arrays
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= w ; j++){
			if(i == 0 || j == 0)	curr[j] = 0;
			else if(sizes[n - i] <= j)	curr[j] = max(val[n - i] + prev[j - sizes[n - i]] , prev[j]);
			else	curr[j] = prev[j];//if weight of current element is greater than bag size
		}
		swap(curr , prev);
	}
	return prev[w];
}
int main(){
	//w - weight capacity of bag
	//n - no. of items
	int w , n;
	n = 5 , w = 20;
	//sizes[i] - tells individual weight of item[i]
	//sizes[i] - tells individual value of item[i]
	int sizes[n], val[n];
	sizes[0] = 7, val[0] = 2 ;
	sizes[1] = 10, val[1] = 15 ;
	sizes[2] = 11, val[2] = 13 ;
	sizes[3] = 4, val[3] = 12 ;
	sizes[4] = 9, val[4] = 8 ;
	
	cout << "Maximum value : " << knapsack(w , n, sizes , val) << endl;
}
