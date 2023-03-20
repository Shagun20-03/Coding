class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        for(int i=0;i<flowerbed.size();i++){
            //check if the current plot is empty
            if(flowerbed[i]==0){
                //check if the left and right plots are empty
                bool emptyLeftPlot=(i==0)||(flowerbed[i-1]==0);
                bool emptyRightPlot=(i==flowerbed.size()-1) || (flowerbed[i+1]==0);
                //if both the plots are empty, we can plant a flower here
                if(emptyLeftPlot && emptyRightPlot){
                    flowerbed[i]=1;
                    cnt++;
                    if(cnt>=n){
                        return true;
                    }
                }
            }
        }
        return cnt>=n;
    }
};