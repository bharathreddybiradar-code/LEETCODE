class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sq=0;
        for(int i=0;i<nums.size();i++){
            if(nums.size()%(i+1)==0){
                sq+=nums[i]*nums[i];
            }
        }
        return sq;
    }
};