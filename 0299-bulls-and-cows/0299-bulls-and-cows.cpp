class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        //int nums[10]={0};
        
        for(int i=0;i<secret.length();i++){
            // int s=secret[i]-'0';
            // int g=guess[i]-'0';
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(s[i], g[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};