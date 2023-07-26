class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()){
            return -1;
        }
         if(needle.size()==1){
           for(int k=0; k<haystack.size();k++){
               if(haystack[k]==needle[0]){
                   return k;
               }
           }
        }
        vector<int>lps;
        int i,j;
        i=1;j=0;
        lps.push_back(0);
        while(i<needle.size()){
            if(needle[i]==needle[j]){
                lps.push_back(j+1);
                i++;
                j++;
            }
            else if(j==0){
                lps.push_back(0);
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
        i=0;j=0;
        while(i<=haystack.size()){
            if(j==needle.size()){
                return i-j;
            }
            else if(needle[j]==haystack[i]){
                i++;
                j++;
            }
            else if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
        return -1;
    }
};