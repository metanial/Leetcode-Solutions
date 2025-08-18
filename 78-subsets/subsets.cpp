class Solution {
public:
    void solution(vector<int> nums, vector<vector<int>> &subsetList, int lastIdx, int idx, vector<int> currList) {
        if(idx == lastIdx) return;
        for(int i=idx+1; i<= lastIdx; i++) {
            currList.push_back(nums[i]);
            subsetList.push_back(currList);
            solution(nums, subsetList, lastIdx, i, currList);
            currList.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return {};
        if(size == 1) return {{}, {nums[0]}};

        vector<vector<int>> subsetList;
        subsetList.push_back({});
        solution(nums, subsetList, size-1, -1, {});
        return subsetList;
    }
};