/* 

Knuth—Morris—Pratt algorithm for stirng matching


A function that takes in two strings and 
checks if the first string contains the second one 
using the Knuth—Morris—Pratt algorithm.

first string size = O(n)
second string size = O(m)
O(n + m) time complexity 
O(m) space complexity


*/



#include<bits/stdc++.h>
//#include<vector>
using namespace std;
vector<int> buildpattern(string substr);
bool doesmatch(string &str, string &substr, vector<int> &pattern);

bool knuthMorrisPrattAlgorithm(string str, string substr) {
	vector<int> pattern = buildpattern(substr);
	return doesmatch(str, substr, pattern);
	
}

int main(){
	string str1 = "aefoaefcdaefcdaedaef";
	string str2 = "aefcdaed";
	bool ans = knuthMorrisPrattAlgorithm(str1, str2);
	if(ans)
	    cout<< "YES" << endl;
	else 
	    cout<< "NO" << endl;
	return 0;
}

vector<int> buildpattern(string substr){
	vector<int> pattern(substr.size()-1, -1);
	int i=1, j=0;
	while(i<substr.size()){
		if(substr[i] == substr[j]){
			pattern[i] = j;
			i++;
			j++;
		}else if(j > 0){
			j = pattern[j-1] + 1;
		}else{
			i++;
		}
	}
	return pattern;
}

bool doesmatch(string &str, string &substr, vector<int> &pattern){
	int i =0;
	int j=0;
	while(i<str.size()){
		if(str[i] == substr[j]){
			i++;
			j++;
		}else if(j>0){
			j = pattern[j-1] + 1;
		}else{
			i++;
		}
		if(j == substr.size()){
			break;
		}
	}
	return j == substr.size();
}