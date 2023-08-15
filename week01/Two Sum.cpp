class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int>two_sum_map;
        for(int i=0; i<nums.size(); i++){
            if(two_sum_map.count(target-nums[i])){
                  result.push_back(i);
                  result.push_back(two_sum_map[target-nums[i]]);
                  break;
            }
            else{
                  two_sum_map[nums[i]]=i;
                  cout<<nums[i];
            }
        }
        return result;
    }
};