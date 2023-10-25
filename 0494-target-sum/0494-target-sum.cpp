class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        target=abs(target);
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0 || ((sum+target)%2)!=0)
            return 0;
        
        int sum1=(target+sum)/2;
        int dp[n+1][sum1+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum1;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum1];
    }
};