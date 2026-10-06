class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=0;
       int c[200];
        for(int i=0;i<m;i++){
            c[k]=nums1[i];
            k++;
        }

        for(int i=0;i<n;i++){
            c[k]=nums2[i];
            k++;
        }
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(c[i]>c[j]){
                    int temp=c[i];
                    c[i]=c[j];
                    c[j]=temp;
                }
            }
        }

            for(int i=0;i<k;i++){
                nums1[i]=c[i];
            }
    }
};