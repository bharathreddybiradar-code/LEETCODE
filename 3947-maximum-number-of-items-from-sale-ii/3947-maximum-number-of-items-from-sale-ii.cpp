class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int maxi = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, items[i][0]);
            mini = min(mini, items[i][1]);
        }

        vector<int> freq(maxi + 1, 0);

        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
        }

        for (int i = 1; i <= maxi; i++) {
            for (int j = 2 * i; j <= maxi; j += i) {
                freq[i] += freq[j];
            }
        }

        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long rem = budget;

        for (int i = 0; i < n; i++) {

            int factor = items[i][0];
            int price = items[i][1];

            if (price >= 2LL * mini) {
                break;
            }

            int count = freq[factor] - 1;

            long long take = min((long long)count, rem / price);

            ans += take * 2;
            rem -= take * price;
        }

        ans += rem / mini;

        return (int)ans;
    }
};