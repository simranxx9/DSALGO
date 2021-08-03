#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        int sum=arr[0];
        for(int i=1;i<n;i++)
        {
            sum = sum^arr[i];
        }
        for(int i=1;i<=n;i++)
        {
            sum = sum^i;
        }
        int set_bit_no = sum & ~(sum-1);
        int  x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&set_bit_no)
            {
                x=x^arr[i];
            }
            else{
                y=y^arr[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i&set_bit_no)
            {
                x=x^i;
            }
            else{
                y=y^i;
            }
        }
        int repeating = y,missing =x;
        for(int i=0;i<n;i++)
        {
            if(x==arr[i])
            {
                repeating = x;
                missing = y;
            }
        }
        int* res = new int[2];
        res[0] = repeating;
        res[1] = missing;
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driv
