class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>M;
        vector<vector<string>>V;
        for(auto &s: strs){
            string tmp_string = s;
            sort(s.be gin(), s.end());
            auto &temp_vec = M[s];
            temp_vec.push_back(tmp_string);
        }
        for(auto vec: M){
            V.push_back(vec.second);
        }
        return V;
    }
};