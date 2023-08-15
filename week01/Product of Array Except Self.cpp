class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result;
        int prefix[nums.size()], suffix[nums.size()];
        prefix[0]=1;
        suffix[nums.size()-1]=1;
        for(int i=1; i<nums.size(); i++){
            prefix[i] = nums[i-1]*prefix[i-1];
        }
        for(int i=nums.size()-2; i>=0; i--){
            suffix[i]=nums[i+1]*suffix[i+1];
        }
        for(int i=0; i<nums.size(); i++){
            result.push_back(suffix[i]*prefix[i]);
        }
        return result;
    }
};