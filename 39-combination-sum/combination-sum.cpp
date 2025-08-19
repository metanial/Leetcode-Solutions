class Solution {
public:
    void solve(vector<int>& candidates, int& target, vector<vector<int>>& combinations, int currIdx, int lastIdx, vector<int> currList, int currListSum) {
        if(currListSum == target) {
            combinations.push_back(currList);
            return;
        } else if(currListSum > target) {
            return;
        }

        for(int i=currIdx; i<=lastIdx; i++) {
            currList.push_back(candidates[i]);
            currListSum += candidates[i];
            solve(candidates, target, combinations, i, lastIdx, currList, currListSum);
            currList.pop_back();
            currListSum -= candidates[i];
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int lastIdx = candidates.size()-1;
        vector<vector<int>> combinations;
        solve(candidates, target, combinations, 0, lastIdx, {}, 0);
        return combinations;
    }
};