class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto add = [&](int val) {
            if(low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            }
            else {
                high.insert(val);
                sumHigh += val;
            }

            if(low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(low.find(v));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }
            else if(low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.find(v));
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if(it != low.end()) {
                low.erase(it);
                sumLow -= val;
            }
            else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            if(low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(low.find(v));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }
            else if(low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.find(v));
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };

        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            return median * low.size() - sumLow
                 + sumHigh - median * high.size();
        };

        vector<long long> cost(n - x + 1);

        for(int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for(int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(k + 1,
                                    vector<long long>(n + 1, INF));

        for(int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for(int j = 1; j <= k; j++) {
            for(int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];

                if(i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }

        return dp[k][n];
    }
};