class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, cheaper = prices[0];
        for(int i=1; i<prices.size(); i++){
                if(prices[i]<cheaper){
                    cheaper = prices[i];
                }
                else{
                    if(prices[i]-cheaper>max){
                        max=prices[i]-cheaper;
                    }
                }
            }
        return max;
        }
};