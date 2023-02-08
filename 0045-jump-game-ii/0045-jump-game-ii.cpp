class Solution {
public:
    int jump(vector<int>& nums) {
        int l, r, step;
        l=r=step=0;
        while(r<nums.size()-1){
            int max_r=0;
            for(int i=l;i<=r;i++){
                max_r=max(nums[i]+i, max_r);
            }
            l=r+1;
            r=max_r;
            ++step;
        }
        return step;
    }
};