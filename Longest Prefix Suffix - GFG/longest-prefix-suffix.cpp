//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    // A is the LPS
	    vector<int>LPS(s.size(), 0);
	    int j=0, i=1;
	    
	    while(i<s.size()) {
	        if(s[i]==s[j]) {
	            LPS[i]=j+1;
	            j++;
	            i++;
	        }
	        else {
	            if(j==0)
	                i++;
	            else
	            //we will go to shorter prefix
	                j=LPS[j-1];
	        }
	    }
	    return LPS.back();
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends