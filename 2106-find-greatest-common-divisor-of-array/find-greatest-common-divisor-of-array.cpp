class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min_val){
                min_val = nums[i];
            }
            if(nums[i] > max_val){
                max_val = nums[i];
            }
        }     
        int gcd = min_val;
        while(gcd > 0){
            if(min_val % gcd == 0 && max_val % gcd == 0){
                return gcd;
            }
            gcd--;
        }
        return 1;
    }
};