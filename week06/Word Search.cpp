class Solution {
private:
    constexpr static int dir[] = {+1,0,-1,0,+1};
    int p,q;
    bool search(int x, int y, int pos, vector<vector<char>>& board, string word, vector<vector<bool>>&visited){
        if(pos>=word.size()){
            return true;
        }
        if(x<0||y<0||x>=p||y>=q||visited[x][y]){
            return false;
        }
        visited[x][y]=true;
        bool status = false;
        for(int i=0; i<4; i++){
            int nx = x+dir[i];
            int ny = y+dir[i+1];
            if(word[pos]==board[x][y]){
                status |= search(nx,ny,pos+1,board,word,visited);
            }
        }
        visited[x][y]=false;
        return status;
    }
    bool search(int x, int y, vector<vector<char>>& board, string word){
        p=board.size();
        q=board[0].size();
        vector<vector<bool>>visited(p+1,vector<bool>(q+1, false));
        return search(x,y,0,board,word,visited);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(search(i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};