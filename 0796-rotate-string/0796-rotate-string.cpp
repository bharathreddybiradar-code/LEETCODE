class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.length()!=goal.length()){
        return false;
       } 
       string temp=s+s;
       for(int i=0;i<temp.length()-goal.length()+1;i++){
        if((temp.substr(i,goal.length()))==goal){
            return true;
        }
       }
       return {};
    }
};