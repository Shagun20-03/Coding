//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      bool isLeapYear( int y ) {    //checking for year is leap yr or not
        return !( y % 400 ) || ( y % 100 && !( y % 4 ));
    }
    int calcDays( int d, int m, int y ) {
        //no of days in months-> jan, feb, march.....
        const int DM[]{ 0, 31, 28 + isLeapYear( y ),
            31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };   
            
        while ( --y )
            d += 365 + isLeapYear( y ); //adding year+date days
        return accumulate( DM, DM + m, d ); //finally adding months+above added days
    }
    int noOfDays(int d1, int m1, int y1, int d2, int m2, int y2) {
        // code here
        // int days=0;
        
        // if(m1%2!=0){    //odd months
        //     days=(y2-y1)*365+(m2-m1+31)+(d2-d1);
        // }
        // else{
        //     if(m1==2 && (y2-y1)!=4){  //even months
        //         days=(y2-y1)*365+(m2-m1+28)+(d2-d1);
        //     }
        //     else if(m1==2 && (y2-y1)==4){
        //         days=(y2-y1)*365+(m2-m1+29)+(d2-d1);
        //     }
        //     else{
        //         days=(y2-y1)*365+(m2-m1+30)+(d2-d1);
        //     }
        // }
        // return days;
        
        return abs( calcDays( d2, m2, y2 ) - calcDays( d1, m1, y1 ));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d1,d2,m1,m2,y1,y2;
        
        cin>>d1>>m1>>y1;
        cin>>d2>>m2>>y2;

        Solution ob;
        cout << ob.noOfDays(d1,m1,y1,d2,m2,y2) << endl;
    }
    return 0;
}
// } Driver Code Ends