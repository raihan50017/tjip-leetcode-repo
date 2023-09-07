class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dic(wordDict.begin(),wordDict.end());
        vector<bool>break_pos(s.size()+1,false);
        break_pos[0]=true;
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(break_pos[j]){
                    string word = s.substr(j, i-j);
                    if(dic.find(word)!=dic.end()){
                        break_pos[i]=true;
                    }
                }
            }
        }
        return break_pos[s.size()];
    }
};