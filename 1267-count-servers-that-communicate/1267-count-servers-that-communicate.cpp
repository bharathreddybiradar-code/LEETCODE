class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    bool found = false;

                    for(int k = 0; k < n; k++) {
                        if(k != j && grid[i][k] == 1) {
                            found = true;
                            break;
                        }
                    }

                    for(int k = 0; k < m; k++) {
                        if(k != i && grid[k][j] == 1) {
                            found = true;
                            break;
                        }
                    }

                    if(found == true) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};