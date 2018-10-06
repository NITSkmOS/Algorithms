/*-----------------Graph coloring with atmost d+1 colors-------------------------*/
#include<iostream>
using namespace std;
int main()
{
    int n,i,j,e;
    cout<<"enter the number of vertices ";
    cin>>n;
    int col[n];  
    int a[n][n]; 
    //cout<<"\n enter the vertices ";
    for(i=0;i<n;i++)
    {
        col[i]=0;
        for(j=0;j<n;j++)
        {
           a[i][j]=0;
        }
    }
    cout<<"enter the number of edges ";
    cin>>e;
    cout<<"enter the edges ";     
    for(i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    
    }
    col[0]=1;
    //int x;
    for(i=1;i<n;i++)
    {
        int x=1;
        for(j=0;j<n;j++)
        {
            if(a[i][j]&&col[j]==x)
            {
                x++;
            }
        }
        col[i]=x;
    }   
    for(i=0;i<n;i++)
    {
        cout<<" vertex "<<i<<" has color "<<col[i];
        cout<<"\n";
    }
    return 0;
}
