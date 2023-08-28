class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot=0, left=0, right=0;
        for(int i=1;i<nums.size();i++) {
            right+=nums[i];
        }
        while(pivot<nums.size()-1 && right!=left){
            pivot++;
            right-=nums[pivot];
            left+=nums[pivot-1];
        }
        if(left==right){
            return pivot;
        }
        else{
            return -1;
        }
    }
};