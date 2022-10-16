class Solution {
    private:
    bool valid(int mid, vector<int>& nums){
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>(long)mid * (i+1))
                return false;
        }
        return true;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int n=nums.size();
        int left=0, right;
        int ans=0;
        for(int i=0;i<n;i++){
            right=max(nums[i],right);
        }
        while(left<=right){
            int mid=(left+right)/2;
            if(valid(mid, nums)){
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
};
//my try
//         vector<int> nums1(n);
//         int ans=0;
//          std::vector<int>::iterator it;
        
//         //copying the original vector
//         for(int i=0;i<nums.size();i++){
//             nums1.push_back(nums[i]);
//         }
        
//         sort(nums.begin(),nums.end(),greater<int>());
        
//         for(int i=0;i<n;i++)
//         {
//             int ele=nums[i];
//             it=std::find(nums1.begin(), nums1.end(), ele);
//                 if(it!=nums1.end()){
//             //if(nums1.find(nums[i])!=nums1.end()){
//                 nums1[i]--;
//                 nums1[i-1]++;
//             }
//         }
//         for(int i=0;i<n;i++){
//             ans=max(nums1[i],ans);
//         }
//         return ans;
//}
//};