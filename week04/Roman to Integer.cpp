class Solution {
public:
    int romanToInt(string s) {
           unordered_map<char,int> roman;
           int value, l;
           roman['I']=1;
           roman['V']=5;
           roman['X']=10;
           roman['L']=50;
           roman['C']=100;
           roman['D']=500;
           roman['M']=1000;
           l = s.size();
           value = roman[s[l-1]];
           l--;
           while(l--){
               if(roman[s[l]]<roman[s[l+1]]){
                  value -= roman[s[l]];
              }
              else{
                  value += roman[s[l]];
              }
             
           }
           return value;
    }
}; 