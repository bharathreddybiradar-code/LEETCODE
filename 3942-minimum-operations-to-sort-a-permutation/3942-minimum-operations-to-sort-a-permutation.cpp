class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero = i;
                break;
            }
        }

        int ans = INT_MAX;

        bool inc = true;
        bool dec = true;

        for(int i = 1; i < n; i++) {
            int a = (zero + i) % n;
            int b = (zero - i + n) % n;

            if(nums[a] != i) inc = false;
            if(nums[b] != i) dec = false;
        }

        if(inc) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if(dec) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};