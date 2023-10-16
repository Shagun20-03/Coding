//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isSubsetSum(int arr[],int N,int sum){
        // code here 
        bool t[N+1][sum+1];
        //filling 1st col- sum=0 can be for empty subset so true
        for(int i=0;i<=N;i++)
            t[i][0]=1;
        //filling 1st row- there can't be any element with value 0 and sum>0 so false
        for(int j=0;j<=sum;j++)
            t[0][j]=0;
        
        t[0][0]=1; //sum value =0 and arr value =0 is possible so true
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {//element can be included as its value is less than sum
                if(arr[i-1]<=j)
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j]; //take or not take
                else
                    t[i][j]=t[i-1][j];//element not included
            }
        }
        return t[N][sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        //sum is odd we cannot partition it into equal sum
        if(sum%2!=0)
        return 0;
        //if half of the sum is present then rest of the half will also have the same sum
        int m=sum/2;
        return isSubsetSum(arr, N, m);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends