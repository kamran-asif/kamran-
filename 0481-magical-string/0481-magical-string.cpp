const int mx = 100005;
int s[mx]; 
struct precompute {
    precompute() {
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;
        int i = 2;
        int j = 3;
        while(j < mx){
            if(s[i] == 2){
                if(s[j - 1] == 2){
                    s[j++] = 1;
                    s[j++] = 1;
                }
                else{
                    s[j++] = 2;
                    s[j++] = 2;
                }
            }
            else{
                if(s[j - 1] == 2){
                    s[j++] = 1;
                }
                else{
                    s[j++] = 2;
                }
            }
            i++;
        }
    }
};

static precompute begin;

class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;
        int count = 0;
        for(int i = 0; i < n; i++){
            count += s[i] == 1;
        }
        return count;
    }
};