class Solution {
private:
    int power(long long base, int pow){
        if(pow==0){
            return 1;
        }
        return pow&1==1?(base*power(base,pow-1))%1000000007:power((base*base)%1000000007,pow/2)%1000000007;
    }
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<=3){
            return primeFactors;
        }
        int n = primeFactors/3;
        if(primeFactors%3==0){
            return power(3,n);
        }
        if(primeFactors%3==1){
            return (((2*power(3,n-1))%1000000007)*2)%1000000007;
        }
        return (2*power(3,n))%1000000007;
    }
};