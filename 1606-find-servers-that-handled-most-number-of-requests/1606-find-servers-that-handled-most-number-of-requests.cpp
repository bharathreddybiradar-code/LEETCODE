class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        vector<int> count(k, 0);

        priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> busy;

        for(int i = 0; i < k; i++) {
            free.insert(i);
        }

        for(int i = 0; i < arrival.size(); i++) {

            while(!busy.empty() && busy.top().first <= arrival[i]) {
                free.insert(busy.top().second);
                busy.pop();
            }

            if(free.empty()) {
                continue;
            }

            int start = i % k;

            auto it = free.lower_bound(start);

            if(it == free.end()) {
                it = free.begin();
            }

            int server = *it;

            count[server]++;

            busy.push({(long long)arrival[i] + load[i], server});

            free.erase(it);
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};