#include<stdio.h>
/*
Calculates GCD of two numbers a & b using the division-based Euclidean Algorithm
*/
int gcd_div(int a , int b) {
    while(b != 0) {
        int temp =b;
        b=a%b;
        a=temp;
    }
    return a;
}
/*
Calculates GCD of two numbers a & b using the recursive-based Euclidean Algorithm
*/
int gcd_rec(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd_rec(b%a, a); 
}
/*
Calculates GCD of two numbers a & b using the Recursive-based Extended Euclidean Algorithm
*/
int gcdExtended(int a, int b, int *x, int *y) { 
    if (a == 0) { 
        *x = 0; 
        *y = 1; 
        return b; 
    }
    int x1, y1;
    int result = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1;
    return result; 
}
// Main Method
int main() {
    int a,b,x,y;
    printf("Enter the two numbers a & b \n");
    scanf("%d %d",&a,&b);
    printf("Division: GCD(%d, %d) = %d \n", a, b, gcd_div(a, b));

    printf("Recursive: GCD(%d, %d) = %d \n", a, b, gcd_rec(a, b));

    int gcd_ext = gcdExtended(a, b, &x, &y); 
    printf("Extended: GCD(%d, %d) = %d \n", a, b, gcd_ext); 
}

