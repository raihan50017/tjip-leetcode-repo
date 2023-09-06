class Solution {
private:
    vector<vector<int>>results;
    void generateSubSet(vector<int> &nums, vector<int> &cand, int pos){
        if(pos>=nums.size()){
            results.push_back(cand);
            return;
        }
        generateSubSet(nums,cand,pos+1);
        cand.push_back(nums[pos]);
        generateSubSet(nums,cand,pos+1);
        cand.pop_back();
    }
    void generateSubSet(vector<int> &nums){
        results.clear();
        vector<int>cand;
        generateSubSet(nums,cand,0);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        generateSubSet(nums);
        return results;
    }
};