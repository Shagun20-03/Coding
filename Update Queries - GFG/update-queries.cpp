//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<int> ans(N, 0);
            vector<vector<int>>p(N, vector<int>(31, 0));     //to update queries from l(prefix array)
        
            for(int i=0;i<Q;i++){
                int l=U[i][0]-1;    //we are taking for 0-based index(in ques it is given for 1-based)
                int r=U[i][1]-1;
                int x=U[i][2];
                
                for(int j=0;j<31;j++){
                    if(((1<<j)&x)>0)    //if given operation value exists
                    {
                        p[l][j]++;  //increasing prefix sum value by 1
                        if(r+1<N)
                        p[r+1][j]--;    //r ke right side wale ko negative kr rhe so that prefix sum hokar right value de
                    }
                }
            }
            for(int i=1;i<N;i++){
                for(int j=0;j<31;j++){
                    p[i][j]+=p[i-1][j];
                }
            }
            for(int i=0;i<N;i++){
                int temp=0;
                for(int j=0;j<31;j++){
                    if(p[i][j]>0){
                        temp+=(1<<j);
                    }
                }
                ans[i]=temp;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends