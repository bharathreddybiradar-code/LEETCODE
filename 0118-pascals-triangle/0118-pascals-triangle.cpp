class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++) {
            long long val = 1;
            vector<int> ansrow;

            ansrow.push_back(1);

            for(int col = 1; col < i; col++) {
                val = val * (i - col);
                val = val / col;
                ansrow.push_back(val);
            }

            ans.push_back(ansrow);
        }

        return ans;
    }
};