class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0)
                    dp[i][j]=INT_MAX-1;
                if(j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1;i<2;i++){   //when size of coins array is 1 but it can be taken infinite no of time
            for(int j=1;j<=amount;j++){
                if(j % coins[0]==0){
                    dp[i][j]=j/coins[0];     //that element can give sum value
                }else{
                    dp[i][j]=INT_MAX-1; //if not divisiible then infinite is taken
                }
            }
        }
        
        //main code for other row and col
	    for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
               if(coins[i-1]<=j)    //if sum is greater than present coin value
                dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);   //take the one which is min
                else
                dp[i][j]=dp[i-1][j];  //not pick
            }
        }
        if(dp[n][amount]==INT_MAX-1)
            return -1;
        else return dp[n][amount];
    }
};