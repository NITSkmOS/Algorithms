#include<bits/stdc++.h>

using namespace std;

void show_queue(const queue <int> q)
{
  queue <int> temp_q = q;
  while(!temp_q.empty())
  {
    cout<<temp_q.front()<<" -> ";
    temp_q.pop();
  }
}

int main()
{
  queue <int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  show_queue(q);
  cout<<"\nPop "<<q.front()<<endl;
  q.pop();
  show_queue(q);
  cout<<"\nPush 5"<<endl;
  q.push(5);
  show_queue(q);
  return 0;
}
