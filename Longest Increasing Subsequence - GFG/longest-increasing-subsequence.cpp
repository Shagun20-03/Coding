//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int lis[n]; //to store the length 
       for(int i=0;i<n;i++){
           lis[i]=1;
       }
       
       //computation in bottom up manner
       //i is starting from 1 because there can be an array with only 1 element
       for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
               if(a[i]>a[j] && lis[i]<lis[j]+1){
                   lis[i]=lis[j]+1;
               }
           }
       }
       return *max_element(lis,lis+n);  //return max length value
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends