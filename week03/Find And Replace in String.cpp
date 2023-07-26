class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>>indices_map;
        for(int i=0; i<indices.size(); i++){
            indices_map.push_back({indices[i],i});
        }
        sort(indices_map.rbegin(), indices_map.rend());

        for(auto n: indices_map){
            cout<<sources[n.second].size()<<" ";
            if(s.substr(n.first, sources[n.second].size())==sources[n.second]){
               s=s.substr(0, n.first)+targets[n.second]+s.substr(n.first+sources[n.second].size());
            }
        }
        return s;
    }
};