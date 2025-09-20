class Solution {
public:
    int findNthDigit(int n) {
    
    long long digits = 1; // abhi kis digit lngth k blck dkh rhe h (1->1..9,2->10..99,...)
    
    long long count = 9;                  //crrnt blck mein ktne nmbrs h(1-dgit:9,2-dgit:90,...)
   
    long long start = 1; //crrnt blck k phla nmbr(1, phr 10,phr 100, ...)
    long long nn = n;

           // jb tk nn crrent blck k ttl dgt se bda h,us blck ko skip krte jao
    while (nn > digits * count) {
        nn -= digits * count; // puri blck ki dgt hta do
        digits++;  // agle blck (dgt lngth +1) mein jao
        count *= 10;                    // agle blck m nmbr 10x hnge
        start *= 10;   // agle blck ka phla nmbr updte karo
    }

    
    long long number = start + (nn - 1) / digits;    // ab nn us blck ke andr k 1 bsd index h
    string s = to_string(number);
    int indexInNumber = (int)((nn - 1) % digits);//nmbr k andar ka 0 basd psition jhan desired digit h
    return s[indexInNumber] - '0';
}


    
};