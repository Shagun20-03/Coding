class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prod=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=-1;
            }
            else if(nums[i]>0){
                nums[i]=1;
            }
            prod=prod*nums[i];
        }
        if(prod>0){
            return 1;
        }
        else if(prod<0){
            return -1;
        }
        else
            return 0;
    }
};