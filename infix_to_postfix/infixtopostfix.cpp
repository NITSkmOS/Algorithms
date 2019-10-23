#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stack>
using namespace std;

int getpriority(char ch) {
switch (ch) {
case '/':
case '*': return 2;
case '+':
case '-': return 1;
default : return 0;
}
}
// convert infix expression to postfix using a stack
void infix2postfix(char infix[], char postfix[], int size)
{
stack<char> s;
int priority;
int i = 0;
int k = 0;
char ch;
while (i < size)//read while infix expression not ended
{
ch = infix[i];
if (ch == '(') {// if left paranthesis occur---simply push the opening
s.push(ch);
i++;
continue;
}
if (ch == ')') { 
while (!s.empty() && s.top() != '(') {
postfix[k++] = s.top();
s.pop();
}
// pop off the opening parenthesis also
if (!s.empty()) {
s.pop();
}
i++;
continue;
}
priority = getpriority(ch);
if (priority == 0) {
postfix[k++] = ch;
}
else {
if (s.empty()) {
s.push(ch);
}
else {

while (!s.empty() && s.top()!='(' && priority<=getpriority(s.top()))
postfix[k++] =s.top();
s.pop();
s.push(ch);
}
}
i++;
}
while (!s.empty()) {
postfix[k++] = s.top();
s.pop();
}
postfix[k] = 0;   // null terminate the postfix expression
}
// C++ program for expression tree
//#include<bits/stdc++.h>
//using namespace std;
// An expression tree node
struct et
{
char value;
et* left, *right;
};
// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
return true;
return false;
}
// Utility function to do inorder traversal
void inorder(et *t)
{
if(t)
{
inorder(t->left);
printf("%c ", t->value);
inorder(t->right);
}
}
// Utility function to do preorder traversal
void preorder(et *t)
{
if(t)
{
printf("%c ", t->value);
preorder(t->left);
preorder(t->right);
}
}
// Utility function to do postorder traversalvoid postorder(et *t)
void postorder(et *t)
{
 if(t)
{
postorder(t->left);
postorder(t->right);
printf("%c ", t->value);
}
}
// A utility function to create a new node
et* newNode(int v)
{
et *temp = new et;
temp->left = temp->right = NULL;
temp->value = v;
return temp;
};
// Returns root of constructed tree for given
// postfix expression
et* constructTree(char postfix[])
{
stack<et *> st;
et *t, *t1, *t2;
// Traverse through every character of
// input expression
for (int i=0; i<strlen(postfix); i++)
{
// If operand, simply push into stack
if (!isOperator(postfix[i]))
{
t = newNode(postfix[i]);
st.push(t);
}
else // operator
{
t = newNode(postfix[i]);
// Pop two top nodes
t1 = st.top(); // Store top
st.pop();
// Remove top
t2 = st.top();
st.pop();
// make them children
t->right = t1;
t->left = t2;
// Add this subexpression to stack
st.push(t);
}
}
// only element will be root of expression
// tree
t = st.top();
st.pop();
return t;
}
// Driver program to test above
// main
int main() {
char infix[20];
cout<<"enter the infix expression";
cin>>infix;
int size = strlen(infix);
char postfix[size];
infix2postfix(infix,postfix,size);
cout<<"\nInfix Expression :: "<<infix<<"\n";
cout<<"\nPostfix Expression :: "<<postfix<<"\n";
et* r = constructTree(postfix);
printf("infix expression is \n");
inorder(r);
printf("prefix expression is \n");
preorder(r);
printf("postfix expression is \n");
postorder(r);
return 0;
}
