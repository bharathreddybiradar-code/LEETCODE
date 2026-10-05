class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int k=0;
       int arr[2000];
for(int i=0;i<nums1.size();i++){
    arr[k] = nums1[i];
    k++;
}
for(int j=0;j<nums2.size();j++){
    arr[k] = nums2[j];
    k++;
}

for(int i=0;i<k-1;i++){
    for(int j=i+1;j<k;j++){
        if(arr[i]>arr[j]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}

if(k%2==1){
    return arr[k/2];
}else{
    return ((arr[k/2-1])+(arr[k/2]))/2.0;
}
    }
};