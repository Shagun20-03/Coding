class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n=salary.size();
        double sum=0, avg=0;
        
        for(int i=1;i<n-1;i++){
            sum+=salary[i];
            avg=sum/(n-2);
        }
        return avg;
    }
};