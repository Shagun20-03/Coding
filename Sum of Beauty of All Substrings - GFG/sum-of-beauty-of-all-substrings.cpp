//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    int findbeauty(vector<int> freq){
        int maxi=INT_MIN, mini=INT_MAX;
        for(auto f: freq){
            if(f==0)
            continue;
            maxi=max(maxi, f);
            mini=min(mini, f);
        }
        return maxi-mini;
    }
  public:
    int beautySum(string s) {
        // Your code goes here
        int n=s.length();
        int ans=0;
        
        //unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            vector<int> freq(26, 0);
            for(int j=i;j<n;j++) {
                freq[s[j]-'a']++;
                ans+=findbeauty(freq);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends