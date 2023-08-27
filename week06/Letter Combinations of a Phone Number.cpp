class Solution {
private:
    vector<string>results;
    unordered_map<char,string>d_to_ch;
    void populate(){
        d_to_ch['2']="abc";
        d_to_ch['3']="def";
        d_to_ch['4']="ghi";
        d_to_ch['5']="jkl";
        d_to_ch['6']="mno";
        d_to_ch['7']="pqrs";
        d_to_ch['8']="tuv";
        d_to_ch['9']="wxyz";
    }

    void generate(int pos, string digits, string &cnd){
        if(!digits.empty() && cnd.size()==digits.size()){
            results.push_back(cnd);
            return;
        }
        string &mapping = d_to_ch[digits[pos]];
        for(auto ch: mapping){
            cnd.push_back(ch);
            generate(pos+1,digits,cnd);
            cnd.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        results.clear();
        string cnd = "";
        populate();
        generate(0,digits,cnd);
        return results;
    }
};