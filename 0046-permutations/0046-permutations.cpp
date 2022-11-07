class Solution {
    private:
    void permutation(vector<int>& nums, int ind, vector<vector<int>> &ans){
        if(ind>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind], nums[i]);
            permutation(nums, ind+1, ans);
            swap(nums[i], nums[ind]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permutation(nums, 0, ans);
        
        //rt(ans.begin(), ans.end());
        //s.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};