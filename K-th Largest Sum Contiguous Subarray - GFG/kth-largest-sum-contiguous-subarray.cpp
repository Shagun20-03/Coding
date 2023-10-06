//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        int sum[N+1];
        sum[0]=0;
        sum[1]=Arr[0];
        
        for(int i=2;i<=N;i++){
            sum[i]=sum[i-1]+Arr[i-1];
        }
        //priority queue of min heap
        priority_queue<int, vector<int>, greater<int>>pq;
        
        //loop to calc contiguous subarray sum position wise
        for(int i=1;i<=N;i++){
             // loop to traverse all positions that form contiguous subarray
             for(int j=i;j<=N;j++){
                 // calculates the contiguous subarry sum from j to i index
                 int x=sum[j]-sum[i-1];
                 
                 // if queue has less than k elements, then simply push it
                 if(pq.size()<K)
                    pq.push(x);
                    
                else{
                // if the min heap has equal to k elements then just check if the largest kth element is
                // smaller than x then insert else its of no use
                    if(pq.top()<x){
                        pq.pop();
                        pq.push(x);
                    }
                }
             }
        }
        return pq.top();    
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends