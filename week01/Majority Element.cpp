class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int candidate = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==candidate){
                vote++;
            }
            else if(vote==0){
                candidate = nums[i];
            }
            else{
                vote--;
            }
        } 
        return candidate;
    }
};