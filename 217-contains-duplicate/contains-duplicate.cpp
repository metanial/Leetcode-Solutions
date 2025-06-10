class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size(); set<int> seen;
        for(int i=0; i<size; i++) seen.insert(nums[i]);
        return seen.size() != size;
    }
};