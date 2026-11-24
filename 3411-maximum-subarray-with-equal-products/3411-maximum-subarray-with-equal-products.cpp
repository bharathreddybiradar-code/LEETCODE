class Solution {
public:
    int maxLength(vector<int>& nums) {
      int ans=0;
      for(int i=0;i<nums.size();i++){
        long long f=0;
        long long s=1;
        long long pro=1;

    for(int j=i;j<nums.size();j++){
         if(pro > LLONG_MAX / nums[j]) {
                    break;
                }
       
       pro*=nums[j];

       f=gcd(f,nums[j]);
   
       s=lcm(s,nums[j]);
      

      if(pro==f*s){
        ans=max(ans,j-i+1);
      }
    }
      }
      return ans;
    }
};