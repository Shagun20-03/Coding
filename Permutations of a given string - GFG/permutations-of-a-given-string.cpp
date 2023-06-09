//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
     private:
    void permutation(string S, int ind, vector<string> &ans){
        //base case
        if(ind==S.size()-1){
            ans.push_back(S);
            return;
        }
        for(int i=ind; i<S.size();i++){
            //swap
            swap(S[ind], S[i]);
            permutation(S, ind+1, ans); //recursion
            //backtrack
            swap(S[i], S[ind]);
        }
        return;
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		     vector<string> ans;
		    permutation(S, 0, ans);
		    
		    //to sort answer in lexicographic order
		    sort(ans.begin(), ans.end());
		    //to remove duplicate element
		    ans.erase(unique(ans.begin(), ans.end()), ans.end());
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends