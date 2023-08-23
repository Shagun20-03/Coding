//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int t[M+1][V+1];
        // Your code goes here
        //initilization
        // first row and column initialized
        for(int i=0;i<M+1;i++)  //for size of coin array
        {
            for(int j=0;j<V+1;j++)  //for sum of coins
            {
                if(j==0) t[i][j]=0;
                if(i==0) t[i][j]=INT_MAX-1; //INT_MAX is taken if we want max_sum=1 and coin size is 0 so we have to take infinity as the ans
            }
        }
	    
	    //2nd row intialization
	    for(int i=1;i<2;i++)    // i is size
        {
            for(int j=1;j<V+1;j++)  //j is sum 
            {
                if(j % coins[0]==0) //that element can give sum value
                    t[i][j]=j/coins[0];
                else
                    t[i][j]=INT_MAX-1;
            }
        }
	    //main code for other row and col
	    for(int i=2;i<M+1;i++)
        {
            for(int j=1;j<V+1;j++)
            {
               if(j>=coins[i-1])    //if sum is greater than present coin value
                t[i][j]=min(t[i-1][j], 1+t[i][j-coins[i-1]]);   //take the one which is min
                else
                t[i][j]=t[i-1][j];  //not pick
            }
        }
        if(t[M][V]==INT_MAX-1)
            return -1;
        else return t[M][V];
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends