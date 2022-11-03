//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        // Your code goes here
        long long int res=0;
        sort(a, a+n);
        sort(b, b+n);
        
        int i=0, j=n-1;
        while(i<n && j>=0){
            //multiplying min of a and max of b by minimising the max and maximising the min
            res+=(a[i++]*b[j--]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends