#include<bits/stdc++.h>
int main (){
	int stack[1000], op, top=9999, po, aux;
	printf("Enter the length of vector\nThe system suports until 1000 elements!\n");
	scanf("%d", &op);
	printf("Enter the elements!\n");
	
	for ( int i=0; i<op; i++){
		scanf("%d", &stack[i]);
	}
	
	for ( int i=0; i<op; i++){
		top=stack[i];
		po=i;
		for ( int j=i; j<op; j++){
			if(stack[j]<top){
				top=stack[j];
				po=j;		
			}
		}
		aux=stack[i];
		stack[i]=stack[po];
		stack[po]=aux;
		
	}
	for( int i=0; i<op; i++)
		printf(" %d ", stack[i]);
}
