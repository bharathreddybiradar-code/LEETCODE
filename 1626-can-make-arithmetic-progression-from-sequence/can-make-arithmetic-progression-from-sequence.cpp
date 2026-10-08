class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int artdif=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;               
                }
            }
        }
        artdif=arr[1]-arr[0];
for(int i=1;i<arr.size()-1;i++){
    count=arr[i+1]-arr[i];

if(count!=artdif){
    return false;
}
}
    return true;
    }
};