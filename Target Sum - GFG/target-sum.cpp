//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int isSubsetSum(vector<int>& A, int N, int sum2){
        // code he
        int t[N+1][sum2+1];
        
        //filling 1st col- sum=0 can be for empty subset so true
        //filling 1st row- there can't be any element with value 0 and sum>0 so false

        for(int i=0;i<=N;i++) {
            for(int j=0;j<=sum2;j++) {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        //t[0][0]=1; //sum value =0 and arr value =0 is possible so true
        
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=sum2;j++)
            {//element can be included as its value is less than sum
                if(A[i-1]<=j)
                    t[i][j]=t[i-1][j-A[i-1]] + t[i-1][j]; //take or not take
                else
                    t[i][j]=t[i-1][j];//element not included
            }
        }
        return t[N][sum2];
    }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int N=A.size();
        int sum=0;
        target=abs(target);
        
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int sum2=(target+sum)/2;
        //if sum of array will be less than target sum how will be able to find the target sum
        if(sum<target || (sum+target)%2 != 0)
            return 0;
            
        return isSubsetSum(A, N, sum2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends