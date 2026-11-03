class Solution {
public:
    int minMoves(vector<int>& nums) {
  int maxi=0;
  for(int i=0;i<nums.size();i++){
    if(maxi<nums[i]){
        maxi=nums[i];
    }
  }
    int moves=0;
    for(int i=0;i<nums.size();i++){
        moves+=maxi-nums[i];
    }
  return moves;
    }
};