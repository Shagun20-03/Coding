class Solution {
    private:
    void permutation(int begin, vector<int>& nums, vector<vector<int>> &ans){
        if(begin>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=begin; i<nums.size(); i++){
            //to avoid duplicates
            // if(i!=begin && nums[i]==nums[i-1])
            //     continue;
            swap(nums[begin], nums[i]);
            permutation(begin+1, nums, ans);
            swap(nums[i], nums[begin]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permutation(0, nums, ans);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};