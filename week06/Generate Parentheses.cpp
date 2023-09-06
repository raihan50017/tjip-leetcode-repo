class Solution {
private:
    vector<string>results;
    string cnd;
    void generate(int open, int close, int n){
        if(open==close&&open==n){
            results.push_back(cnd);
            return;
        }
        if(open<n){
            cnd.push_back('(');
            generate(open+1,close,n);
            cnd.pop_back();
        }
        if(open>close){
            cnd.push_back(')');
            generate(open,close+1,n);
            cnd.pop_back();
        }
    }
    void generate(int n){
        cnd.clear();
        results.clear();
        generate(0,0,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        generate(n);
        return results;
    }
};