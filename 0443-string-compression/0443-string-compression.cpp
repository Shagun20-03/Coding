class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, res=0;
        
        while(i<chars.size()){
            int grouplength=1;
            while(i+grouplength<chars.size() && chars[i+grouplength]==chars[i]){
                grouplength++;
            }
            chars[res++]=chars[i];
            if(grouplength>1){
                for(char c:to_string(grouplength)){
                    chars[res++]=c;
                }
            }
            i+=grouplength;
        }
        return res;
    }
};