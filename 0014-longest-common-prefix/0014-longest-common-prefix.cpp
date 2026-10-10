class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<answer.length() && j<strs[i].length() && answer[j]==strs[i][j]){
                j++;
            }
        answer=answer.substr(0,j);
        if(answer==""){
         return "";
        }
        }
        return answer;
    }
};