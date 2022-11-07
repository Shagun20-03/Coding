class Solution {
    private:
    //ind is to check for all element of array
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<arr.size(); i++){
            //to avoid duplicate element after current index
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            //if current element is greater than the sum we want
            if(arr[i]>target){
                break;
            }
            temp.push_back(arr[i]);
            findCombination(i+1, target-arr[i], arr, ans, temp);
            temp.pop_back();    //backtrack for not picking 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        findCombination(0, target, candidates, ans, temp);
        return ans;
    }
};