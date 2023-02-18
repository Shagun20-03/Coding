//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        for(int i=1;i<N;i++){
            //1st columm
            Matrix[i][0]+=max(Matrix[i-1][0], Matrix[i-1][1]);
            
            //for rest of cells N-1 because last col we will take in seperate case
            for(int j=1;j<N-1;j++){
                Matrix[i][j]+=max(Matrix[i-1][j-1], max(Matrix[i-1][j], Matrix[i-1][j+1]));
            }
            //for last col
            Matrix[i][N-1]+=max(Matrix[i-1][N-2], Matrix[i-1][N-1]);
        }
        int res=INT_MIN;
        for(int j=0;j<N;j++){
            res=max(res, Matrix[N-1][j]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends