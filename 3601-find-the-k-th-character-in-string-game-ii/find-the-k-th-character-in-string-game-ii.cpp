class Solution {
public:
    char ans(long long k, vector<int>& operations) {
        if(k<1) return 'a';
        long long logk = static_cast<int>(log2(k));
        k = k - pow(2, logk);
        char answer = ans(k, operations) + operations[logk];
        return answer != 'z' + 1 ? answer : 'a';
    }
    char kthCharacter(long long k, vector<int>& operations) {
        return ans(k-1, operations);
    }
};