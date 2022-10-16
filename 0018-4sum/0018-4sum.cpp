class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.empty())
        return ans;

        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            // int target_3=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                long long target_2=(long long) target-nums[j]-nums[i];
                // long long target_2=(long long) target_3-nums[j];
                int left=j+1;
                int right=n-1;
                while(left<right)
                {
                    int two_sum=nums[left]+nums[right];
                    if(two_sum<target_2)
                    left++;
                    else if(two_sum>target_2)
                    right--;
                    else{
                        vector<int> quadruplet(4, 0);
                        quadruplet[0]=nums[i];
                        quadruplet[1]=nums[j];
                        quadruplet[2]=nums[left];
                        quadruplet[3]=nums[right];
                        ans.push_back(quadruplet);

                        //processing duplicates of left
                        while(left<right && nums[left]==quadruplet[2])
                        left++;
                        while(right>left && nums[right]==quadruplet[3])
                        right--;
                    }
                }
                //processing the duplicates of j
                while(j+1<n && nums[j+1]==nums[j])
                j++;
            }
            //processing the duplicates of i
            while(i+1<n && nums[i+1]==nums[i])
            i++;
        }
        return ans;
    }
};