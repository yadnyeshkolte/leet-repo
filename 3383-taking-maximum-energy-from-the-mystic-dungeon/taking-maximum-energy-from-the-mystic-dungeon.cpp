class Solution {
public:
    vector<int> nums;
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        nums.assign(n, INT_MIN);
        int emax = INT_MIN;
        for(int i=0;i<n;i++){
            emax = max(emax, findSteps(energy, k, i));
        }
        return emax;
    }
    int findSteps(vector<int>& energy, int k, int start){
        if (start >= energy.size()) return 0;
        if (nums[start] != INT_MIN) {
            return nums[start];
        }
        nums[start] = energy[start] + findSteps(energy, k, start + k);
        
        return nums[start];
    }   
};