class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int match_len = 0;
        while(strs[0][match_len]==strs[strs.size()-1][match_len] && match_len<strs[0].size() && match_len<strs[strs.size()-1].size()){
            match_len++;
        }
        return strs[0].substr(0, match_len);
    }
};