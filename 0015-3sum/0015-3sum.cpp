class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n=nums.size();
        //moves for a
        //taking n-2 as third last element so that if it is a next element n-1 is b and n is c
        for(int i=0;i<n-2;i++) {
            //skip duplicate elements for a 
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                                    //a+b+c should be 0 so here we want sum as b+c=0-a
                int lo=i+1, hi=n-1, sum=0-nums[i];
                while(lo<hi){
                    //b+c=-a
                    //lo+hi=i
                    if(nums[lo]+nums[hi]==sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);    //a
                        temp.push_back(nums[lo]);   //b
                        temp.push_back(nums[hi]);   //c
                        res.push_back(temp);
                        //skip duplicate elements for b and c
                        while(lo<hi && nums[lo]==nums[lo+1])
                            lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])
                            hi--;
                        //for next number other than duplicates
                        lo++; hi--;
                    }
                    //when sum is lesser than -a we will increase the left pointer
                    else if(nums[lo]+nums[hi]<sum) lo++;
                    else hi--;
                }
            }
        }
        return res;
    }
};