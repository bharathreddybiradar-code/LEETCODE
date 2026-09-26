class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<0){
            return 0;
        }
        int original=num;
        int sum=0;
        for(int i=1;i<=num;i++){
            if(num%i==0 && i!=num){
              cout<<i;
              sum+=i;
            }
        }
        if(sum==original){
            return true;
        }else{
            return false;
        }
    }
};