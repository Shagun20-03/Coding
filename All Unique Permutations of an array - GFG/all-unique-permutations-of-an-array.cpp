//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void permutation(int begin, vector<int> arr, vector<vector<int>> &ans){
        if(begin>=arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=begin; i<arr.size(); i++){
            swap(arr[begin], arr[i]);
            permutation(begin+1, arr, ans);
            swap(arr[i], arr[begin]);
        }
    }
    public:
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        vector<vector<int>> ans;
        permutation(0, arr, ans);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends