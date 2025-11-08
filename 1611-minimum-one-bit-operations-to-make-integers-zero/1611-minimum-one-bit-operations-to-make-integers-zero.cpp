class Solution {
public:
    int minimumOneBitOperations(int n) {
        int pos = 0;
        bool t = true;
        int c = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                if (t) {
                    pos += (1 << c) - 1;  // Faster than pow(2, c)
                } else {
                    pos -= (1 << c) - 1;
                }
                t = !t;
            }
            n >>= 1;
            c++;
        }

        return abs(pos);
    }
};