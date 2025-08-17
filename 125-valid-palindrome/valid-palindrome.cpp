class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.size()-1;
        while(low <= high) {
            // if lowChar is not alphabet, check next char (low++)
            if((s[low] < 'A' || s[low] > 'Z') && 
               (s[low] < 'a' || s[low] > 'z') && 
               (s[low] < '0' || s[low] > '9')) {
                low++;
            }
            // if highChar is not alphabet, check prev char (high--)
            else if((s[high] < 'A' || s[high] > 'Z') && 
                    (s[high] < 'a' || s[high] > 'z') &&
                    (s[high] < '0' || s[high] > '9')) {
                high--;
            }

            // if both are same, increase low and reduce high
            else if(tolower(s[high]) == tolower(s[low])) {
                low++; high--;
            } 
            // else if both are unequal, return false
            else {
                return false;
            }
        }
        // finally return true
        return true;
    }
};