class Solution {
public:
    string count_sort(string &s){
        vector<int>V(26,0);
        string str="";
        for(int i=0; i<s.length(); i++){
            V[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            while(V[i]--){
                str += i+'a';
            }
        }
        return str;
    }
    bool isAnagram(string s, string t) {
        return count_sort(s)==count_sort(t);
    }
};