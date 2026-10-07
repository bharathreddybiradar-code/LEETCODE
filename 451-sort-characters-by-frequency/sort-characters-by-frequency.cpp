class Solution {
public:
    string frequencySort(string s) {
          int count[128] = {0};

        for(int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        string answer="";

        for(int f = s.size(); f >= 1; f--) {
            for(int i = 0; i < 128; i++) {

                if(count[i] == f) {

                    for(int j=0;j<count[i];j++){
                    answer.push_back(i);
                }
            }
        }
        }
        return answer;
    }
};