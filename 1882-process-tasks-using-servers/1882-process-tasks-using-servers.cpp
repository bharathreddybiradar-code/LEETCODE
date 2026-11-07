class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> freeServers;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busyServers;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < m; i++) {
            time = max(time, (long long)i);

            // Make completed servers free
            while(!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                auto [endTime, weight, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({weight, index});
            }

            // Wait if no server is free
            if(freeServers.empty()) {
                time = get<0>(busyServers.top());

                while(!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                    auto [endTime, weight, index] = busyServers.top();
                    busyServers.pop();

                    freeServers.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans.push_back(index);

            // Store server with its finishing time
            busyServers.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};