//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        int ans=0;
        int maxval=*max_element(A, A+n);
        //no of rows will be max element of array cz in worst case max value will be the max diff
        //col will be no of elements
        vector<vector<int>> dp(2*maxval+1, vector<int> (n, 0));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=A[i]-A[j];
                dp[diff][i]=dp[diff][j]+1;
                ans=max(ans, dp[diff][i]);
            }
        }
        return ans+1;   //ans contains no of ap and ans+1 will be length of longest ap
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends