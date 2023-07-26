class Solution {
public:
    bool isOpening(char ch, unordered_map<char,char> &brackets){
        for(auto m: brackets){
            if(m.second==ch){
                return true;
            }
        }
        return false;
    }
    bool isValid(string s) {
        unordered_map<char,char>brackets({{')','('},{'}','{'},{']','['}});
        stack<char>stk;
        for(auto &ch:s){
            if(isOpening(ch,brackets)){
                stk.push(ch);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if(brackets[ch]!=stk.top()){
                    return false;
                }
                stk.pop();
            }
        }
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};