class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0, j;
        unordered_set<int>tracking_set;
        for(int i=0; i<nums.size(); i++){
            tracking_set.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(tracking_set.find(nums[i]-1)==tracking_set.end()){
                j=1;
                while(tracking_set.find(nums[i]+j)!=tracking_set.end()){
                    j++;
                }
                if(maxLength<j){
                    maxLength=j;
                }
            }
        }
        return maxLength;
    }
};