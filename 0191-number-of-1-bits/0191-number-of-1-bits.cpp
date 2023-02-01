class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            //by doing tis we arereducing one 1 and increasing the no of decreasing count to know how many 1 is there
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};