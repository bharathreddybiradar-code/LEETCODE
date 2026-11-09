class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long val=1;
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            val=val*(rowIndex+1-i);
            val=val/i;
            ans.push_back(val);
        }
        return ans;
    }
};