class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        // Finding pivot
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        // Edge case : if pivot does not exist
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find successor and swap
        for(int i=n-1; i>pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Reverse the subarray
        reverse(nums.begin()+pivot+1, nums.end());
    }
};