class Solution {
public:
    bool isPalindrome(string s) {
       int ft=0;
       int lt=s.length()-1;
       while(ft<lt){
                if(!isalnum(s[ft])){
                    ft++;
                }
                else if(!isalnum(s[lt])){
                    lt--;
                }else{
                    if(tolower(s[ft])!=tolower(s[lt])){
                        return false;
                    }
                    ft++;
                    lt--;
                }
       }
       return true; 
    }
};