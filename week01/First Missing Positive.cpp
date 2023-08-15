class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long int trackArray[100000]={0}, i, count=0;
        for(i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<=nums.size()){
                tracqqkArray[nums[i]-1] = -nums[i];
                count++;
            }
        }
        for(i=0; i<count; i++){
            if(trackArray[i]==0){
                return i+1;
            }
        }
        return i+1;
    }
};