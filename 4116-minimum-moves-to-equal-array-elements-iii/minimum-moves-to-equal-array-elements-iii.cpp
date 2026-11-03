class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        int index = 0;
        int first = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>=first){
                index = i;
                first = nums[i];
            }
        }
        int minc = 0;
        for(int num: nums){
            minc += nums[index]-num;
        }

        return minc;
        
    }
};