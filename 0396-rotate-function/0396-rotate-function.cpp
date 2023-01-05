class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int sum=0, prod=0, maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            prod += i*nums[i];
        }
        vector<int> dp(n, 0);
        dp[0]=prod;
        maxi=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+sum-n*nums[n-i];
            maxi=max(maxi, dp[i]);
        }
        return maxi;
    }
};