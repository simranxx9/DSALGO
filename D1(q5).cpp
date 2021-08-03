#include <bits/stdc++.h>
using namespace std;
struct Interval{
  int start,end;
};
bool compInt(Interval i1,Interval i2)
{
  return (i1.start<i2.start);
}
void mergeIntervals(Interval arr[],int n)
{
  sort(arr,arr+n,compInt);
  stack<Interval> s;
  s.push(arr[0]);
  int i=1;
  while(i<n)
  {
    Interval top = s.top();
    if(top.end<arr[i].start)
    {
     s.push(arr[i]); 
    }
    else if(top.end<arr[i].end)
    {
      top.end = arr[i].end;
      s.pop();
      s.push(top);
    }
i++;
  }
  while(!s.empty())
  {
    Interval top = s.top();
    cout<<"["<<top.start<<" , "<<top.end<<"]";
    s.pop();
  }
  cout<<endl;
}
int main()
{
    Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
