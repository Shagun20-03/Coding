//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        //binary search
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(A[mid]==key)
            return mid;
            
            //if 1st part of array is sorted we are checking our target there
            if(A[l]<=A[mid])
            {
                if(key>=A[l] && key<A[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            //if 1st part is not sorted we will check for the key element in the 2nd part
            else
            {
                if(key>A[mid] && key<=A[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends