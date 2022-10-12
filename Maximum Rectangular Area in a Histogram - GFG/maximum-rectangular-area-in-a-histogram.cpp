//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> st;
        long long maxA=0;
        for(int i=0;i<=n;i++)
        {  //we will take n also which do not have any height for next element to arr last element
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i]))
            {  //if top of stack is greater than curr element it means we have found nsr
                  long long height=arr[st.top()];                         
                  st.pop();                                     
                  long long width;
                  if(st.empty()) //there is no element in the stack that is lesser than crr element
                  width=i;
                  else
                  width=i-st.top()-1;
                  maxA=max(maxA, width*height);
            }
            st.push(i); //if curr element is freater than stack top 
        }
        return maxA;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends