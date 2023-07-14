//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int maxReach=arr[0];
        int jump=1; //min 1 jump can b made at any value of arr[0]
        int step=arr[0];
        //base vcase
        if(n==1)
        return 0;
        else if(arr[0]==0)  //we cannot go furthwer as step taken is 0 so return -1
        return -1;
        else{
            //already one jump of 1 has been taken
            for(int i=1;i<n;i++){
                if(i==n-1){
                    return jump;
                } //reached last point
                maxReach=max(maxReach, i+arr[i]);   //i+a[i] means i distance have already been covered and next jump is value a[i]
                step--; //1 step have been taken
                if(step==0){
                    jump++;
                    if(i>=maxReach) //i aage badh gya h uske wahan jaane ka [possible nhi h wo maxreach tak hi jaa sakta jo i se kam h
                    return -1;
                    step=maxReach-i;
                }
            }
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends