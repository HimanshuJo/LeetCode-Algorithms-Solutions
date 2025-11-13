/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/?envType=daily-question&envId=2025-11-12
*/

class Solution {
public:

    int gcd_int(int a, int b) {
        return b == 0 ? a : gcd_int(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g_all = 0;
        int cnt1 = 0;
        for (int x : nums) {
            g_all = gcd_int(g_all, x);
            if (x == 1) ++cnt1;
        }
        if (g_all > 1) return -1;

        if (cnt1 > 0) {
            return n - cnt1;
        }
        int bestL = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            if (g == 1) { bestL = 1; break; }
            for (int j = i + 1; j < n; ++j) {
                g = gcd_int(g, nums[j]);
                if (g == 1) {
                    bestL = min(bestL, j - i + 1);
                    break;
                }
            }
        }
        return n + bestL - 2;
    }
};