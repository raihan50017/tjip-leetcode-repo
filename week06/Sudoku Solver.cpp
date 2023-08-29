class Solution {
private:
    bool isvalid(int i, int j, int num, vector<vector<char>>& board){
        for(int k=0; k<board.size(); k++){
            if(board[i][k]-'0'==num){
               return false;
            }
            if(board[k][j]-'0'==num){
               return false;
            }
        }
        int x_pos=(i/3)*3;
        int y_pos=(j/3)*3;
        for(int k=x_pos; k<x_pos+3; k++){
            for(int l=y_pos; l<y_pos+3; l++){
                if(board[k][l]-'0'==num){
                    return false;
                }
            }
        }
        return true;
    }
     bool solve(vector<vector<char>>& board){
         for(int i=0; i<board.size(); i++){
             for(int j=0; j<board[0].size(); j++){
                 if(board[i][j]=='.'){
                     for(int k=1; k<=board.size(); k++){
                         if(isvalid(i,j,k,board)){
                            board[i][j]=k+'0';
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                         }
                     }
                     return false;
                 }
             }
         }
         return true;
     }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};