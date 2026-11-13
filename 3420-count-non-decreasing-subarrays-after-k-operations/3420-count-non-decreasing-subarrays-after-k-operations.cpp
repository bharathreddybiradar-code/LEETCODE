
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cost = 0;
        int j = n - 1;

        deque<pair<int,int>> dq;

        for(int i = n - 1; i >= 0; i--) {

            int cnt = 1;

            while(!dq.empty() && dq.back().first < nums[i]) {
                cost += 1LL * (nums[i] - dq.back().first) * dq.back().second;
                cnt += dq.back().second;
                dq.pop_back();
            }

            dq.push_back({nums[i], cnt});

            while(cost > k) {
                cost -= dq.front().first - nums[j];
                dq.front().second--;

                if(dq.front().second == 0) {
                    dq.pop_front();
                }

                j--;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
