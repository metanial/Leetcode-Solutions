class Solution {
public:
    // function to find max index within range
    int maxIndex(vector<int>& nums, int low, int high) {
        int currMaxIndex = low;
        for(int i = low+1; i <= high; i++) {
            if(nums[i] >= nums[currMaxIndex]) currMaxIndex = i;
        }
        return currMaxIndex;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0 || k == 0) return {};
        vector<int> maxWindow;
        int currMaxIndex = maxIndex(nums, 0, k-1);
        maxWindow.push_back(nums[currMaxIndex]);

        for(int i = k; i < size; i++) {
            if(nums[i] >= nums[currMaxIndex]) {
                currMaxIndex = i;
            } else if(i-k == currMaxIndex) {
                currMaxIndex = maxIndex(nums, i-k+1, i);
            }
            maxWindow.push_back(nums[currMaxIndex]);
        }
        return maxWindow;

    }
};