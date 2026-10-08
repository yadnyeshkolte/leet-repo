class Solution {
public:
    double myPow(double x, int n) {
        if(x==0.0f){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(x==1){
            return x;
        }
        double val = 1;
        if(n>0){
            return powerto(x, n, val);
        }
        else{
            return npowerto(x, n, val);
        }
    }
    double powerto(double x, int n, double val){
        if(n==0){
            return val;
        }
        if(n%2==0){
            return powerto(x*x, n/2, val);
        }
        else{
            return powerto(x*x, n/2, val*x);
        }
    }
    double npowerto(double x, int n, double val){
        if(n==0){
            return val;
        }
        if(n%2==0){
            return npowerto(x*x, n/2, val);
        }
        else{
            return npowerto(x*x, n/2, val/x);
        }
    }
};