class Solution {
public:
    //checking whether the buses can finish totalTrips of trips in givenTime
    bool timeEnough(vector<int>& time, long long givenTime, int totalTrips){
        long long actualTrips=0;
        for(int t:time){
            actualTrips+=givenTime/t;   //no of trips that can be made
        }
        return actualTrips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        //For the right boundary, we can set it as the totalTrips multiplied by the maximum time required by one bus
        long long left=1, right=1LL* *max_element(time.begin(), time.end())* totalTrips;
        while(left<right){
            long long mid=(left+right)/2;
            if(timeEnough(time, mid, totalTrips)){  //trip can be made with time
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};