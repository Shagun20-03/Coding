class Solution {
    private:
    bool isValid(string s, string t){
        int n=s.size();
        int m=t.size();
        //if characters length is not equal we cannot make edits
        if(n!=m)
            return false;
        int diff=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])
                diff++; //increase difference of characters
        }
        if(diff>2)
            return false;
        else
            return true;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n=queries.size();
        int m=dictionary.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if while traversing any query is equal with any dict.
                if(isValid(queries[i], dictionary[j]))
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};