class Solution {
public:
    string removeOuterParentheses(string s) {
        int len = s.size();
        int count = 0;
        for(int i=0; i<len; i++) {
            if(s[i]=='(') count++;
            else count--;

            if(count == 1 && s[i] == '(') {
                s.erase(s.begin()+i);
                i--;
                len--;
            }
            else if(count == 0 && s[i] == ')') {
                s.erase(s.begin()+i);
                i--;
                len--;
            }
            
        }
        return s;
    }
};