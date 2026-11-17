class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        
        for(int i=0;i<s.length();i++){
        string a="";
        for(int j=i;j<s.length();j++){
        if(a.find(s[j])!=-1){
            break;
        }
        a+=s[j];
        maxi=max(maxi,(int)a.length());
        }
        }
        return maxi;
    }
};