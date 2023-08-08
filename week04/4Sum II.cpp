class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mapping;
        int tuples=0;
        for(auto k:nums1){
            for(auto n:nums2){
                mapping[k+n]++;
            }
        }
        for(auto k:nums3){
            for(auto n:nums4){
                tuples += mapping[-(k+n)];
            }
        }
        return tuples;
    }
};