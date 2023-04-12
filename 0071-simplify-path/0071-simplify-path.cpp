class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        
        for(int i=0;i<path.length();i++)
        {
            if(path[i]=='/')
                continue;   //movw to next character of string
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp==".")
                continue;   //ignore and move forward
            else if(temp=="..")
            {
                if(!st.empty()) //if stack is not empty
                    st.pop();
            }
                else
                    st.push(temp);
        }
        //adding all the stack element to res
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        if(res.size()==0)
            return "/";
        return res;
    }
};