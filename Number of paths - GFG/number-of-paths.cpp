//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long  numberOfPaths(int M, int N)
    {
        // Code Here
        const int mod = 1000000007;
         
        int n = M + N - 2;
        int r = M - 1;
        long long res = 1;
       
        for (int i = 1; i <= r; i++) { //nCr= n*(n-1)..r/r!
          res=(res*(n-i+1))%mod;
          res=(res* modInverse(i, mod)) % mod;
        }
        return res;
    }
    
    private:
    long modInverse(int a, int m) {
        return modPow(a, m-2, m);
    }
    long long modPow(long long base, int exp, int mod){
        long long result=1;
        
        while(exp>0){
            if(exp%2==1){
                result=(result*base)%mod;
            }
            base=(base*base)%mod;
            exp /= 2;
        }
        return result;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends