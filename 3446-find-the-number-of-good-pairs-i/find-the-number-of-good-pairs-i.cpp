class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size(), good = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(nums1[i] % (nums2[j] * k) == 0) {
                    good++;
                }
            }
        }
        return good;
    }
};