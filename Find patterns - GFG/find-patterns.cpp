//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool isSubsequence(string &S, string &W, int index, vector<bool> &visited){
    int i=index, j=0;
    while(i<S.size() && j<W.size()){
        if(visited[i]==1){
            i++;
            continue;
        }
        if(S[i]==W[j]){
            visited[i]=1;
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(j==W.size())
    return true;
    //return true;
}
    int numberOfSubsequences(string S, string W){
        // code here 
        vector<bool> visited(S.size(), false);
        int ans=0;
        
        for(int i=0;i<S.size();i++){
            if(isSubsequence(S, W, i, visited)){
                ans++;
            }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends