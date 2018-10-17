#include<stdio.h>
#include<stdlib.h>
//SMMR  author - Ravi Mishra
// Multiplication of two square matrices using recursive calls.Theoritical time complexity = O(n^3)

int ** add(int **arr1, int **arr2, int size){
// add two matrices arr1 and arr2 of dimension size x size and returns the result matrix 
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++)
		{			
			arr1[i][j] = arr1[i][j] + arr2[i][j];					
		}		
	}
return arr1;
}
int** padding(int **arr1, int n){
// adds a row and column having values 0 in input matrix of size nxn and returns matrix of size (n+1) x (n+1)
//allocating space for matrix of size (n+1) x (n+1)
	int **arr  = (int**)malloc((n+1) * sizeof(int*));
	int i, j;
		for (i = 0; i < n+1; i++)
     {		   
        arr[i] = (int*)malloc((n+1) * sizeof(int));
     }
	// copying input matrix to the allocated matrix with a added row and column	
 	for(i = 0; i <= n; i++){
	for(j = 0; j <= n; j++){
    if(i == n || j == n){
   	arr[i][j] = 0;
         }
    else{
	arr[i][j] = arr1[i][j];
}	
}
}
return arr;
}
int ** smmr(int **arr1, int **arr2, int n){	
	  int i, j, k = 0;	  
	  //if n is odd then add padding to input matrices
	  if(n != 1 & (n % 2) != 0){	  	
	  	arr1 = padding(arr1, n);
		arr2 = padding(arr2, n);
	  	n = n+1;	  	
	  }	  
//allocate space to hold local result matrix 
int 	   **arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
    {
		   
            arr[i] = (int*)malloc(n * sizeof(int));
    }
//if size is one the multiply numbers and return
	if(n == 1){
		arr[0][0] = arr1[0][0] * arr2[0][0];		
		return arr;		
	}
	else {		
		//break the two input matrices in sub matrices of  size (n/2) x (n/2)
		// sub matrices of arr1 are a1,a2,a3,a4  and of arr2 are b1,b2,b3,b4 
			int **a1 = (int**)malloc(n/2 * sizeof(int *)); 
			int **a2 = (int**)malloc(n/2 * sizeof(int *));
			int **a3 = (int**)malloc(n/2 * sizeof(int *));
			int **a4 = (int**)malloc(n/2 * sizeof(int *));
			int **b1 = (int**)malloc(n/2 * sizeof(int *));
			int **b2 = (int**)malloc(n/2 * sizeof(int *));
			int **b3 = (int**)malloc(n/2 * sizeof(int *));
			int **b4 = (int**)malloc(n/2 * sizeof(int *));
	for (i = 0; i < n/2; i++)
     {
		    a1[i] = (int *) malloc(n/2*sizeof(int));
		    a2[i] = (int *) malloc(n/2*sizeof(int));
		    a3[i] = (int *) malloc(n/2*sizeof(int));
		    a4[i] = (int *) malloc(n/2*sizeof(int));
		    b1[i] = (int *) malloc(n/2*sizeof(int));
		    b2[i] = (int *) malloc(n/2*sizeof(int));
		    b3[i] = (int *) malloc(n/2*sizeof(int));
		    b4[i] = (int *) malloc(n/2*sizeof(int));
        }
 //copying values from arr1 and arr2 to their corresponding sub matrices	
	for(i = 0; i < n/2; i++){		
		for(j = 0; j < n/2; j++){			
			a1[i][j] = arr1[i][j];
			a2[i][j] = arr1[i][j+n/2];
			a3[i][j] = arr1[i+n/2][j];
			a4[i][j] = arr1[i+n/2][j+n/2];
			b1[i][j] = arr2[i][j];
			b2[i][j] = arr2[i][j+n/2];
			b3[i][j] = arr2[i+n/2][j];
			b4[i][j] = arr2[i+n/2][j+n/2];			
		}
	}  
    //multiplying the sub-matrices recursively and adding the result to get the sub parts of result matrices
	int **a = add(smmr(a1, b1, n/2), smmr(a2, b3, n/2), n/2);
	int **b = add(smmr(a1, b2, n/2), smmr(a2, b4, n/2), n/2);
	int **c = add(smmr(a3, b1, n/2), smmr(a4, b3, n/2), n/2);
	int **d = add(smmr(a3, b2, n/2), smmr(a4, b4, n/2), n/2);	
	//combine sub-parts to get result matrix
		for(i = 0 ;i < n/2; i++){	
		for(j = 0; j < n/2; j++){
			arr[i][j] = a[i][j];
			arr[i][j+n/2] = b[i][j];
			arr[i+n/2][j] = c[i][j];
			arr[i+n/2][j+n/2] = d[i][j]; 			
		}
	}
//free allocated space	
free(a1);
free(a2);
free(a3);
free(a4);
free(b1);
free(b2);
free(b3);
free(b4);
//return result matrix
	return arr;	
	}
} 
void main(){
int s;
printf("ENTER THE SIZE OF MATRICES: ");	
//scanf("%d",&s);
	s = 3;
int i=0,j=0;
//declare pointers for the input matrices and allocate memory of give size
int **arr;
int **arr2 = (int**)malloc(s * sizeof(int*));
int **arr1 = (int**)malloc(s * sizeof(int*));
for (i=0; i<s; i++)
    {
		    arr1[i] = (int *)malloc(s * sizeof(int));
            arr2[i] = (int *)malloc(s * sizeof(int));
    }
//input matrix-1
printf("ENTER MATRIX-1\n");
for(i = 0; i < s; i++){
	for(j = 0; j < s; j++){
	//scanf("%d",&arr1[i][j]);
		arr1[i][j] = i + j;
}
}
printf("ENTER MATRIX-2\n");
for(i = 0; i < s; i++){
	for(j = 0; j < s; j++){
	//scanf("%d",&arr2[i][j]);
		arr2[i][j] = i + j;
}
}
    arr = smmr(arr1,arr2,s);
//arr = add(arr1,arr2,s);
printf("-----MATRIX-1-------\n");
for(i = 0;i < s; i++){
	for(j = 0;j < s; j++){
	printf("%d\t", arr1[i][j]);
}
printf("\n");
}
printf("-----MATRIX-2--------\n");
for(i=0;i<s;i++){
	for(j=0;j<s;j++){
	printf("%d\t",arr2[i][j]);
}
printf("\n");
}
printf("----------MATRIX-1 X MATRIX-2-------\n");
for(i=0;i<s;i++){
	for(j=0;j<s;j++){
	printf("%d\t",arr[i][j]);
}
printf("\n");
}
//free allocated space
free(arr);
free(arr1);
free(arr2);
//getchar();	
}
