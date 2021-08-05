#include <iostream>
using namespace std;
int uniquePaths(int m ,int n, int i, int j)
{
  if(i >= m || j >= n) return 0;
  if(i == m-1 && j == n-1) return 1;

  return uniquePaths(m, n, i+1, j) + uniquePaths(m , n , i , j+1);
}
int main() {
  int m = 2, n = 3;
  int i =0 ,j =0;
  cout<<uniquePaths(m,n,i,j)<<endl;
}
