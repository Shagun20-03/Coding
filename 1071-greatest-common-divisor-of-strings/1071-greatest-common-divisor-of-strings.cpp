class Solution {
public:
//     bool gcd(char ch1, char ch2){
//         if(ch2=='')
//             return ch1;
//         return gcd(ch2, ch1%ch2);
//     }
    
    string gcdOfStrings(string str1, string str2) {
//         string ans="";
//         int n=str1.length(), m=str2.length();
//         int size=max(n, m);
         
//          for(int i=0;i<size;i++) {
//              if(str2[i]=='\0')
//                  return str1;
//              else if(gcd(str1[i], str2[i])) {
//                     ans=ans+str1[i];
//              }
//              else{
//                  continue;
//              }
//          }
//         return ans;
        if(str1+str2==str2+str1)
            return str1.substr(0, gcd(str1.length(), str2.length()));
        else
            return "";
    }
};