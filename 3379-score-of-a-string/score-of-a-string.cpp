class Solution {
public:
    int scoreOfString(string s) {
        int size = s.size(), score = 0;
        for(int i =0; i<size-1; i++) {
            score += abs(s[i+1]-s[i]);
        }
        return score;
    }
};