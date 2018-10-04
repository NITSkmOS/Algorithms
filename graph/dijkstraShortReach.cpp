#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <utility> 
#include <algorithm>
#include <limits>
using namespace std;

int minindex(int dist[],bool vis[],int n)
{
    int min=INT_MAX,y=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false && dist[i]!=INT_MAX && min>dist[i])
        {
            min = dist[i];
            y=i;
        }   
    }   
    return y;
}    
int main() {
    int test;
    scanf("%d",&test);
    cout<<"Enter number of test cases";
while(test--)
{
     int n,m;
    cin>>n>>m;
    vector< pair<int,int> > vec[n];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cout<<"Enter start and end point with weight";
        scanf("%d%d%d",&a,&b,&c); a--;b--;
        vec[a].push_back(make_pair(b,c));
        vec[b].push_back(make_pair(a,c));
    }    
  
    int src;
    cout<<"enter source";
    cin>>src;src--;
    int dist[n];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src] = 0;
    bool vis[n]={false};
    for(int i=0;i<n-1;i++)
    {
        int index = minindex(dist,vis,n);
        if(index==-1) continue;
        vis[index] = true;
        for(int j=0;j<vec[index].size();j++)
        { 
          if(vis[vec[index][j].first]==false &&  dist[vec[index][j].first]>(dist[index]+vec[index][j].second))
           {
                dist[vec[index][j].first] = dist[index]+vec[index][j].second; 
           }  
        } 
    }    
    for(int i=0;i<n;i++) 
    {
        if(i!=src)
        {
            if(dist[i]==INT_MAX) cout<<"-1 ";
            else cout<<dist[i]<<" ";
        }    
    }
    cout<<endl;
}    
    
return 0;
}
/*
input 
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
output
24 3 15
*/
