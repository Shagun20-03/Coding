class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=potions.size();
        int m=spells.size();
        vector<int> pairs(m, 0);
        
        sort(potions.begin(), potions.end());
        
        for(int i=0;i<m;i++){
            int l=0, r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                long long product=(long long)spells[i]*(long long)potions[mid];
                if(product>=success){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            pairs[i]=n-l;
        }
        return pairs;
    }
};