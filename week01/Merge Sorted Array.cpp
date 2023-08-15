class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums3;
        int i,j;
        for(i=0; i<m; i++){
            nums3.push_back(nums1[i]);
        }
        nums1.clear();
        i=0;
        j=0;
        while(n>0 && m>0){
            if(nums3[i]<=nums2[j]){
                nums1.push_back(nums3[i]);
                m--;
                i++;
            }
            else{
                nums1.push_back(nums2[j]);
                n--;
                j++;
            }
        }
        while(m){
            nums1.push_back(nums3[i]);
            i++;
            m--;
        }
        while(n){
            nums1.push_back(nums2[j]);
            j++;
            n--;
        }

    }
};