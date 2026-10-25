class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                index=max(index,count);
            }else{
                count=0;
            }
        }
        return index;
    }
};