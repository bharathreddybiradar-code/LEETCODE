class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cottt=0;
      int ele;
      for(int i=0;i<nums.size();i++){
        if(cottt==0){
            cottt=1;
            ele=nums[i];
        }
        else if(nums[i]==ele){
            cottt++;
        }else{
            cottt--;
        }
      }
int cot=0;
for(int i=0;i<nums.size();i++){
    if(ele==nums[i]){
        cot++;
    }
}
if(cot>(nums.size()/2)){
    return ele;
}
return -1;
    }
};