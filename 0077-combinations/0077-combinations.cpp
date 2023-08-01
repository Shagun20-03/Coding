class Solution {
public:
    vector<vector<int>> ans;
    void findCombinations(int num, int k, int n, vector<int> &v){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=num;i<=n;i++){
            v.push_back(i);
            findCombinations(i+1, k, n, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        //temp vectpr
        vector<int> v;
        findCombinations(1, k, n, v);
        return ans;
    }
};