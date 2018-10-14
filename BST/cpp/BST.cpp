#include<iostream>
#include<deque>
using namespace std;

struct node
{
  node* left;
  node* right;
  node* parent;
  int data;
};

node* generate(int key,node*p)
{
  node* n = new node;
  n->left = NULL;
  n->right = NULL;
  if(p!=NULL)n->parent = p;
  else n->parent = NULL;
  n->data = key;
  return n;
}

void level(node* root)
{
  if(root != NULL){
  deque< node* > q;
  q.push_back(root);
  while(!q.empty())
  {
    node* n = q.front();
    if(n->left)q.push_back(n->left);
    if(n->right)q.push_back(n->right);
    if(n->parent!=NULL)cout<<n->data<<" "<<n->parent->data<<endl;
    else cout<<n->data<<" NULL"<<endl;
    q.pop_front();
  }
  cout<<endl;}
}

node* insert(node* root,node* parent,int n)
{
  if(root != NULL)
  {
    if(n > root->data)
    {
      root->right = insert(root->right,root,n);
    }
    else
    {
      root->left = insert(root->left,root,n);
    }
    return root;
  }
  else
  {
    return generate(n,parent);
  }
}

node* search(node*root,int key)
{
  if(root!=NULL)
  {
    if(root->data == key) return root;
    node *a = new node;
    node*b = new node;
    a = search(root->left,key);
    b = search(root->right,key);
    if(a!=NULL)return a;
    else return b;
  }
  else return NULL;
}

int getIdentity(node*root)
{
  if(root->parent!=NULL)
  {
    if(root->parent->left==root) return 0;
    else return 1;
  }
  return -1;
}

node* delete1(node* root,node* ultraroot)
{
  int boo = 0;
  if(root==ultraroot) boo = 1;
  int children = 2;
  if(root->left == NULL) children-=1;
  if(root->right== NULL) children-=1;
  int identity = getIdentity(root);
  if(children==0)
  {
    if(identity==-1) {root = NULL;ultraroot = NULL;}
    else if(identity==0) {root->parent->left = NULL; root = NULL;}
    else if(identity==1) {root->parent->right = NULL; root = NULL;}
    if(boo)return NULL;
    else return ultraroot;
  }
  else if(children==1)
  {
    node* child;
    if(root->left!=NULL) child = root->left;
    else child = root->right;
    if(identity==-1) {child->parent = NULL; root = NULL;}
    else if(identity == 0) {root->parent->left = child; child->parent = root->parent; root = NULL;}
    else {root->parent->right = child; child->parent = root->parent; root = NULL;}
    if(boo) return child;
    else return ultraroot;
  }
  else
  {
    node* child = root->right;
    while(child->left!=NULL) child = child->left;
    delete1(child,ultraroot);
    //Taking care of children
    root->left->parent = child;
    if(root->right!=NULL)root->right->parent = child;
    //Taking care of self and child(node replacing self)
    child->left = root->left;
    child->right = root->right;
    child->parent = root->parent;
    if(identity==-1) {root = NULL;}
    else if(identity==0){root->parent->left = child;root = NULL;}
    else if(identity==1){root->parent->right = child;root = NULL;}
    if(boo) return child;
    else return ultraroot;
  }
}
int main()
{
  typedef struct node node;
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  node* root = NULL;
  node *p = root;
  root = insert(root,NULL,l[0]);
  // cout<<root->data<<endl;
  for(int i=1;i<n;i++)insert(root,NULL,l[i]);
  // level(root);
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int a;
    cin>>a;
    if(a==1)//Insert value
    {
      int b;
      cin>>b;
      insert(root,NULL,b);
      // level(root);
    }
    else if(a==2)
    {
      int key;
      cin>>key;
      node* p = search(root,key);
      node*k = delete1(p,root);
      if(k!=NULL)root = k;
      level(root);
    }
  //   else if(a==3)
  //   {
  //     int b;
  //     cin>b;
  //     search(b);
  //   }
  }
}
