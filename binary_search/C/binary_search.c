#include <stdio.h>

int binary_search(int find,int arr[],int len){

	int s = 0; // start
	int e = len - 1; // end
	int p = (s+e)/2; // pivo
	int ret = -1;

	while(s < e){
		if(arr[p] < find){
			s = p+1;
			p = (s+e)/2;
		}
		else if(arr[p] > find){
			e = p - 1;
			p = (s+e)/2;
		}
		else{
			ret = p; // ok
			s = e;
		}
	}

	return ret;
}

int main(){

	int arr[] = {3,4,5,7,8,34,36,76,87,98,456,654,654,878,90000};
	int len = 15; // lenght of array
	int find = 7; // find

	int idx = binary_search(find,arr,len);

	if(idx != -1) printf("Ok, id = %d\n",idx);
	else printf("number does not exist in array\n");

}
