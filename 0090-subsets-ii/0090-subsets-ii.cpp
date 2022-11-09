class Solution {
    private:
    void Subset(int ind, vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp){
        ans.push_back(temp);
        //taking all the elements at same level of same size
        for(int i=ind; i<nums.size(); i++)
        {
            //if i (which is inc) not equal to ind which is at same level leave that i
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            //if we can put that element put it into temp
            temp.push_back(nums[i]);
            Subset(i+1, nums, ans, temp);
            temp.pop_back(); //remove the inserted element for the list of next size
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        //sorting to keep all the duplicate elements together
        sort(nums.begin(), nums.end());
        Subset(0, nums, ans, temp);
        //ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};