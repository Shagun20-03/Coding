//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int maxi=arr[n-1];
        int mini=arr[0];
        int diff=maxi-mini;
        
        //to minimize the difference we have to add with smallest and subtract with greatest
        for(int i=1;i<n;i++){
            maxi=max(arr[i-1]+k, arr[n-1]-k);
            mini=min(arr[i]-k, arr[0]+k);
            
            diff=min(diff, maxi- mini);
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends