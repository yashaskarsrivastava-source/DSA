class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // pointer for the position to write the next valid element

        for (int i = 0; i < nums.size(); i++) {
            // Allow the element if k < 2 (first two elements are always fine)
            // or if nums[i] is different from the element two positions back in the result
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};