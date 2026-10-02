class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
               int start=0;

               while(start<=i && num[start]=='0'){
                start++;
               }
               return num.substr(start,i-start+1);
            }
        }
        return "";
    }
};