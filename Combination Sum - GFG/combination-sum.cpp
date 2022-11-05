//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    private:
    void findCombination(int i, vector<int>& A, int B, vector<vector<int>> &ans, vector<int> &v){
        int n=A.size();
        //sort(A.begin(), A.end());
        if(i==n){
            if(B==0){
                ans.push_back(v);
            }
            return;
        }
        
        if(A[i]<=B){
            v.push_back(A[i]);
            findCombination(i, A, B-A[i], ans, v);
            v.pop_back();
        }
        findCombination(i+1, A, B, ans, v);
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> v;
        //int n=A.size();
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        
        findCombination(0, A, B, ans, v);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends