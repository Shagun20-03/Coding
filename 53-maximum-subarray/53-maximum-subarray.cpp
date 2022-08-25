class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};