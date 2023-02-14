class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i=a.length()-1; //pointer i for adding from right of string a 
        int j=b.length()-1; //pointer j for adding from right of string b
        int carry=0;    //we have to consider carry
        
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';   //by subtracting with 0 we are converting in integer to                                                         perform operations
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            if(sum>1){
                carry=1;
            }
            else{
                carry=0;
            }
            res+=to_string(sum%2);  // just moduling the sum so, we can get remainder and add it into our result
            
        }
        if(carry!=0){
            res+=to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};