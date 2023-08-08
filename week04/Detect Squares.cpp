class DetectSquares {
private:
    int counts[1001][1001]={};
    vector<pair<int,int>>points;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        counts[point[0]][point[1]]++;
        points.push_back({point[0],point[1]});
    }
    
    int count(vector<int> point) {
        int num_square = 0;
        for(pair<int,int> p: points){
            if(abs(p.first-point[0])==abs(p.second-point[1])&&abs(p.first-point[0])>0){
                num_square += counts[p.first][point[1]] * counts[point[0]][p.second];
            }
        }
        return num_square;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */