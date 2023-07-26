class Solution {
public:
    static bool compare(int &a, int &b){
        string sa = to_string(a);
        string sb = to_string(b);
        return (sa+sb)<(sb+sa);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend(), compare);
        if(nums[0]==0){
            return "0";
        }
        string largest = "";
        for(auto n:nums){
            largest += to_string(n);
        }
        return largest;
    }
};