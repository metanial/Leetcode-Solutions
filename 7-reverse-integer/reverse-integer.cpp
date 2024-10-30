class Solution {
public:
    int reverse(int x) {
        int out = 0, temp;
        while(x != 0) {
            temp = x%10;
            x=x/10;
            if((out > INT_MAX/10) || (out < INT_MIN/10)) {
                return 0;
            }
            out = (out * 10) + temp;
        }
        return out;
    }
};