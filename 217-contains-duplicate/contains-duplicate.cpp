class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        set<int> seen;

        for(int i=0; i<size; i++) {
            if(seen.find(nums[i]) != seen.end()) return true;
            seen.insert(nums[i]);
        }
        return false;
    }
};