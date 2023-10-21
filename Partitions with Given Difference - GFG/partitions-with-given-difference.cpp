//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        //In this code we will just return the sum of subset 1 and everything is same as count of
        //subset with a given sum
        int mod=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]%mod;
        }
        if(sum-d<0 || ((sum+d)%2)!=0)
            return 0;
            
        int sum1=((sum+d)/2);    //sum of subset 1
        vector<vector<int>> t(n+1, vector<int> (sum1+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum1;j++){
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum1;j++){   //here we are taking from j=0 beacuse {0} can also be one subset
                if(arr[i-1]<=j){
                    t[i][j]=(t[i-1][j-arr[i-1]] + t[i-1][j])%mod;
                }
                else{
                    t[i][j]=t[i-1][j]%mod;    
                }
            }
        }
        return t[n][sum1]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends