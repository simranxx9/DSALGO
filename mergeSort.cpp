#include <iostream>
using namespace std;

void merge(int a[] , int low, int mid, int high)
{
  int i =0 ,j =0 ,k = low ;
  int n1 = mid - low + 1;
  int n2 = high - mid ;
  int left[n1] , right[n2];
  for( i =0 ; i < n1;i++)
  {
    left[i] = a[low+i];
  }
  for( i = 0;i<n2;i++)
  {
    right[i] = a[mid+i+1];
  }
  i=0 ,j=0;
  while(i < n1 && j < n2)
  {
    if(left[i]<=right[j]) a[k++] =left[i++];
    else a[k++] = right[j++];
  }
  while(i<n1)
  {
    a[k++] = left[i++];
  }
  while(j<n2)
  {
    a[k++] = right[j++];
  }
}
void conquere(int a[] , int l, int r)
{
  if(l < r) // exactly 2 elements
  {
    int mid = l + (r-l)/2;
    conquere(a, l , mid);
    conquere(a,mid+1, r);
    merge(a,l,mid, r);
  }
  
}
int main() {
  int a[] = {  12, 11, 13, 5, 6, 7 };
  int n = sizeof(a)/sizeof(a[0]);
  conquere(a,0,n-1);
  for(int i = 0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
