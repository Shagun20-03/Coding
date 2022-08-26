class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                count0++;
            else if(nums[i]==1)
                count1++;
            else
                count2++;
        }
        int j=0;
        while(count0>0){
            nums[j++]=0;
            count0--;
        }
        while(count1>0){
            nums[j++]=1;
            count1--;
        }
        while(count2>0){
            nums[j++]=2;
            count2--;
        }
    }
};