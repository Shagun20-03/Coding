class Solution {
public:
    void findSubset(int ind, vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            findSubset(i+1, nums, temp, ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        findSubset(0, nums, temp, ans);
        return ans;
    }
};