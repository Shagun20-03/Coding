class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        if(s1==s2)
            return true;
        
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                int j;
                for(j=i+2;j<n;j+=2){
                    if(s1[j]==s2[i])
                        break;
                }
                if(j<n){
                    swap(s1[i], s1[j]);
                }
            }
        }
        return s1==s2;
    }
};