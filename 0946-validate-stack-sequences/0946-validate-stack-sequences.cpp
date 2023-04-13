class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;
        
        int j=0;
        for(auto x:pushed){
            st.push(x);
            while(!st.empty() && j<n && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        if(j==n)
            return true;
        return false;
    }
};