//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    
    if(n==1)
        return 0;
    //profit from both transactions
    vector<int> profit1(n, 0), profit2(n, 0);
    int min_price=price[0];
    
    for(int i=1;i<n;i++) {
        min_price=min(min_price, price[i]);
        profit1[i]=max(profit1[i-1], price[i]-min_price);
    }
    
    int max_price=price[n-1];
    for(int i=n-2;i>=0;i--){
        max_price=max(max_price, price[i]);
        profit2[i]=max(profit2[i+1], max_price-price[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans, profit1[i]+profit2[i]);
    }
    return ans;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends