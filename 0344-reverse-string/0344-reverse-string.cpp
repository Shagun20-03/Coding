class Solution {
public:
    void reverseString(vector<char>& s) {
        
        //reverse(s.begin(), s.end());
        //2nd approach- two pointer
        int i=0, j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
};