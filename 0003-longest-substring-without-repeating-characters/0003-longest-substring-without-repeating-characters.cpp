class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // map<char, int> mp;
        // mp[256]={0};
        vector<int> mp(256, -1);
        int left=0, right=0;
        int n=s.length();
        int len=0;
        
        for(int i=0;i<n;i++)
        {
            //repeating element
            if(mp[s[right]]!=-1)
            {
                //jump of left pointer by index of repeated char by +1
                left=max(mp[s[right]]+1, left);
            }
            mp[s[right]]=right;
            len=max(len, right-left+1);
            right++;
        }
        return len;
    }
};