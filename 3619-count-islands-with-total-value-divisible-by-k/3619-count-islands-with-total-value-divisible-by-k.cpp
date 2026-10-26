
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    long long sum = 0;
                    stack<pair<int,int>> st;
                    st.push({i, j});

                    while(!st.empty()) {
                        int r = st.top().first;
                        int c = st.top().second;
                        st.pop();

                        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
                            continue;

                        sum += grid[r][c];
                        grid[r][c] = 0;

                        st.push({r+1, c});
                        st.push({r-1, c});
                        st.push({r, c+1});
                        st.push({r, c-1});
                    }

                    if(sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};
