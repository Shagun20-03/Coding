class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        for(int num:nums){
            hashset.insert(num);
        }
        
        int longeststreak=0;
        for(int num: nums)
        {
            if(!hashset.count(num-1))
            {
                int currentnum=num;
                int currentStreak=1;
                
                while(hashset.count(currentnum+1)){
                    currentnum+=1;
                    currentStreak+=1;
                }
                longeststreak=max(currentStreak, longeststreak);
            }
        }
        return longeststreak;
    }
};