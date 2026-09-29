class Solution {
public:
    int fib(int n) {
     if(n==0){
        return 0;
     }
     if(n==1){
        return 1;
     }
     int a=0;
     int b=1;
     int fibo=0;
     while(n>1){
          fibo=a+b;
        a=b;
        b=fibo;
        n--;
     }
     return fibo;
     }
};