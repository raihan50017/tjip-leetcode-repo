class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int dx,dy,gcd,max_point=0;
        for(int i=0; i<points.size();i++){
            map<pair<int,int>, int>same_line;
            for(int j=0; j<points.size();j++){
                if(j==i){
                    continue;
                }
                dx = points[i][0]-points[j][0];
                dy = points[i][1]-points[j][1];
                gcd = __gcd(dx,dy);
                dx /= gcd;
                dy /= gcd;
                same_line[{dy,dx}]++;
            }
            for(auto n: same_line){
                if(n.second>max_point){
                    max_point = n.second;
                }
            }
        }
        return max_point+1;
    }
};