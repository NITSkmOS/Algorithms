#include<bits/stdc++.h>
using namespace std;
#define end _end
#define next _nxt

const int MaxN=500500;
int end[MaxN];
int next[27][MaxN];

bool created[MaxN];
int sz=0;
void insert(string &s)
{
    int v=0;
    for(int i=0;i<s.size();i++)
    {
        int c=s[i]-'a';
        if(!created[next[c][v]])
        {
            next[c][v]=++sz;
            created[sz]=1;
        }
        v=next[c][v];
    }
    ++end[v];
}

bool search(string tmp)
{
    int v=0;
    for(int i=0;i<tmp.size();i++)
    {
        int c=tmp[i]-'a';
        if(!created[next[c][v]])
            return false;
        v=next[c][v];
    }

    return end[v]>0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    string key[n];
    for(int i=0;i<n;i++)
    {
        cin>>key[i];
        insert(key[i]);
    }


    string output[]={" N ","Y"};
    for(int i=0;i<m;i++)
       {

       string a;
       cin>>a;

    cout<<output[search(a)]<<endl;
       }
}
