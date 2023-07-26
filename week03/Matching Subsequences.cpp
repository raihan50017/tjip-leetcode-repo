class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int match=0,up_index,i;
        unordered_map<char,vector<int>>index_map;
        for(i=0; i<s.size(); i++){
            index_map[s[i]].push_back(i);
        }
        for(auto &str:words){
            up_index=-1;
            for(i=0; i<str.size();i++){
                if(upper_bound(index_map[str[i]].begin(),index_map[str[i]].end(),up_index)!=index_map[str[i]].end()){
                    up_index = index_map[str[i]][upper_bound(index_map[str[i]].begin(),index_map[str[i]].end(),up_index)-index_map[str[i]].begin()]; 
                }  
                else{
                    break;
                }                
            }
            if(i==str.size()){
                match++;
            }

        }
        return match;
    }
};