class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(needle.find(haystack)!=string::npos)
        //     return needle.find(haystack);
        // return -1;
        int m=needle.length();
        int n=haystack.length();
        
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<m;j++){
                if(needle[j]!=haystack[i+j]){
                    break;
                }
                if(j==m-1)
                    return i;
            }
        }
        return -1;
    }
};