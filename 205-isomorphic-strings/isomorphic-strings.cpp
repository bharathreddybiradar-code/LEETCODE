class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map1[256]={0};
        int map2[256]={0};
        for(int i=0;i<s.length();i++){
            if(map1[s[i]]!=0){
                if(map1[s[i]]!=t[i]){
                    return false;
                }
            }else{
                map1[s[i]]=t[i];
            }
            if(map2[t[i]]!=0){
                if(map2[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                map2[t[i]]=s[i];
            }
        }
        return true;
    }
};