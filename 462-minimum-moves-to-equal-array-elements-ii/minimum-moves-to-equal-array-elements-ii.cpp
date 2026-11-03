class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int val = INT_MAX;
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        int mid = n / 2;
        return calculate(nums, mid);
        
    }
    int calculate(vector<int>& nums, int index){
        int n = nums.size();
        int i=index;
        int j=index;
        int count = 0;
        while(i>=0){
            count += nums[index]-nums[i];
            i--;
        }
        while(j<=n-1){
            count += nums[j]-nums[index];
            j++;
        }
        return count;
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left>=right){
            return;
        }
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right){
        int n1 =mid-left+1;
        int n2 =right-mid;
        vector<int> L(n1),R(n2);
        for (int i=0;i<n1;i++)
            L[i] = nums[left+i];
        for (int j=0;j<n2;j++)
            R[j]=nums[mid+1+j];
        int i=0;
        int j=0;
        int k=left;
        while(i<n1 && j<n2) {
            if(L[i]<=R[j]) {
                nums[k]=L[i];
                i++;
            }
            else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }
        while(j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
};