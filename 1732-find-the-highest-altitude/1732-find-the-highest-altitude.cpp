class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int net_gain[n+1];
        net_gain[0]=0;
        
        for(int i=0;i<gain.size();i++){
            net_gain[i+1]=gain[i]+net_gain[i];
        }
        return *max_element(net_gain, net_gain+n+1);
    }
};