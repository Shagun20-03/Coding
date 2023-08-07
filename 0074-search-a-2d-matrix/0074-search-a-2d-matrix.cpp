class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int begin=0, end=rows*cols-1;
        
        while(begin<=end){
            int mid=(begin+end)/2;
            int mid_val=matrix[mid/cols][mid%cols];
            
            if(mid_val==target){
                return true;
            }
            else if(mid_val<target){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};