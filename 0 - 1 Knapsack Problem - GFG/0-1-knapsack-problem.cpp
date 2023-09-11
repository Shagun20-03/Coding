//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // int t[1001][1001];
    // Solution(){
    //      memset(t, -1, sizeof(t));    
    // }
   
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here using recursion
       //base condition
    //   if(W==0 || n==0)
    //     return 0;
    //   //if weight of current item is greater than max capacity of bag
    //   if(wt[n-1]>W)
    //     return knapSack(W, wt, val, n-1); //item not included and we will move to previous elements
       
    //   else //when item is added, not added
    //     return max(val[n-1]+knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
    
    //Solution-2
    //memoization approach-storing the precomputed value
          
        // if(n==0 || W==0) 
        //     return 0;
    
        // if(t[n][W]!=-1) 
        //     return t[n][W];
        
        // if(wt[n-1]>W) {
        //     t[n][W]=knapSack(W, wt, val, n-1);
        //     return t[n][W];
        // }
        // else if(wt[n-1]<=W){
        //     t[n][W]=max(val[n-1]+knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
        //     return t[n][W];
        // }
    
    //Solution-3 DP Approach
    vector<vector<int>> t(n+1, vector<int>(W+1));
    
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                //base case
                if(i==0 || j==0)
                {
                    t[i][j]=0;
                }
                //if current capacity is less than j is the max capacity
                else if(wt[i-1]<=j)
                {
                //now the weight will become max weight-current weight
                //value of the weight+taking, not taking that item
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
                }
                else
                {
                //we will not add the item
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends