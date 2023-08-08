class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,set<int>>x2y;
        for(auto point: points){
            int x = point[0];
            int y = point[1];
            x2y[x].insert(y);
        }
        int minArea = INT_MAX/2;
        for(auto it = x2y.begin(); it!=x2y.end(); it++){
            for(auto jt = next(it); jt!=x2y.end(); jt++){
                if(it->second.size()<2 || jt->second.size()<2){
                    continue;
                }
                vector<int>ys;
                set_intersection(begin(it->second),end(it->second),begin(jt->second),end(jt->second),back_inserter(ys));
                for(int k=1; k<ys.size(); k++){
                     minArea = min(minArea,abs(it->first - jt->first)*(ys[k]-ys[k-1]));
                }
            }
        }
        return minArea == INT_MAX/2?0:minArea;
    }
};