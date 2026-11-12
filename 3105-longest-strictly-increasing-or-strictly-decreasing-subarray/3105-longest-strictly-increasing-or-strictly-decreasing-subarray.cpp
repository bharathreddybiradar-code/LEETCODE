class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incre=1;
        int decre=1;
        int answer=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                incre++;
                decre=1;
            }
            else if(nums[i]<nums[i-1]){
                decre++;
                incre=1;
            }else{
                incre=1;
                decre=1;
            }
            answer=max(answer,max(incre,decre));
        }
        return answer;
    }
};