class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = 1, r = 1000000, res = f(nums, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(nums, cost, x), y2 = f(nums, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }
     long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
};