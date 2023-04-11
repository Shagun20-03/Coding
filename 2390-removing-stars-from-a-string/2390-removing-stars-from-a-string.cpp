class Solution {
public:
    string removeStars(string s) {
        stack<int>st;
        int n=s.length();
        string ans="";
        
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};