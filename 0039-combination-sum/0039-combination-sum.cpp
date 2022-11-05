class Solution {
    private:
    void findCombination(int i, int target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> &v){
        //base cond
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(v);
            }
            return; //no further recursion will take place
        }
        //pick the element
        if(candidates[i]<=target) {
            v.push_back(candidates[i]);
            //find for that index only 
            findCombination(i, target-candidates[i], candidates, ans, v);
            v.pop_back();   //pop out that element for not pick condition
        }
        //we decide to move further with next index value 
        findCombination(i+1, target, candidates, ans, v);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        findCombination(0, target, candidates, ans, v);
        return ans;
    }
};