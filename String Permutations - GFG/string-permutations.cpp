//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void permute(int begin, string S, vector<string> &ans){
        if(begin>=S.length()){
            ans.push_back(S);
            return;
        }
        for(int i=begin;i<S.size();i++){
            swap(S[begin], S[i]);
            permute(begin+1, S, ans);
            swap(S[i], S[begin]);
        }
    }
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        permute(0, S, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends