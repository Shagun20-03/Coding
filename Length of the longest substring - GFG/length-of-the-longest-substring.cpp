//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int>freq(256, -1);
        int left=0, right=0;
        int n=S.length();
        int len=0;
        
        for(int i=0;i<n;i++){
            if(freq[S[right]]!=-1) {   //repeating character
                left=max(freq[S[right]]+1, left);   ////jump of left pointer by index of repeated char by +1
            }                                       //so that we can check for other substrings present in the string andfind max length from them
            freq[S[right]]=right;
            len=max(len, right-left+1);
            right++;
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends