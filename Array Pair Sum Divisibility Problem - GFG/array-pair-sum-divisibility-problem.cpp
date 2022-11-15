//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int> freq;
         //it cannot be divided in pair then
        if(nums.size()%2!=0)
        return false;
        
        //if sum of remainders of pairs is divisible by k it will make a valid pair
        //(rem, k-rem)-->valid pair
        //so the no of times we are getting remainder as 0 should be even
        for(int i=0; i<nums.size(); i++){
            freq[nums[i] % k]++;
        }
        for(int i=0; i<nums.size(); i++){
            //current remainder
            int rem=nums[i]%k;
            if(rem==0) {
                //if freq of rem=0 is even
                if(freq[0]%2 != 0)
                return false;
            }
            else if(freq[rem]!=freq[k-rem])
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends