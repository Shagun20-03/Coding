class Solution {
public:
//checking if mid can be the max subarray sum
    bool check(int mid, vector<int>& weights, int n, int days){
        int cnt=0, sum=0;
        for(int i=0;i<n;i++){
            if(weights[i]>mid)
                return false;
            //increase sum of current sub array
            sum+=weights[i];
        //if sum is greater than mid inc count
            if(sum>mid){
                cnt++;
                sum=weights[i];
            }
        }
        cnt++;
        if(cnt<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max=*max_element(weights.begin(), weights.end());
        int start=max;
        int end=0;
        int n=weights.size();
        
        for(int i=0;i<n;i++){
            end+=weights[i];
        }
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            //if mid is solution then mid is answer
            if(check(mid, weights, n, days)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};