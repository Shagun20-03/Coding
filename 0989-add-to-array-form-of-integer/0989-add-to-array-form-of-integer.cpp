class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> ans;
        int cur=k, i=n;
        
         while(--i>=0 || cur>0){
            if(i>=0)
                cur+=num[i];
            ans.push_back(cur%10);
            cur/=10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};