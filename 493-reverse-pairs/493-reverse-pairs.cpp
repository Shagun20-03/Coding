typedef long long LL;
class Solution {
    public:
    int Merge(vector<int> & nums, int low, int mid, int high){
        int total=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && (long) nums[i]>(long) 2 * nums[j]){
                j++;
            }
            total+=(j-(mid+1));
        }
        vector<int> v;
        int left=low, right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
                v.push_back(nums[left++]);
            else
                v.push_back(nums[right++]);
        }
        while(left<=mid){
            v.push_back(nums[left++]);
        }
        while(right<=high){
            v.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=v[i-low];
        }
        return total;
    }
    
    int MergeSort(vector<int>& nums, int low, int high){
        if(low>=high){
            return 0;
        }
        int mid=(low+high)/2;
        int count=0;
        count+=MergeSort(nums, low, mid);
        count+=MergeSort(nums, mid+1, high);
        count+=Merge(nums, low, mid, high);
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return MergeSort(nums,0,n-1);
    }
};