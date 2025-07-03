class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
     //edge cases
     if(numerator==0)return "0";   
      string res;
      //sign handle krte h
      if((numerator<0)^(denominator<0))res+='-';
      //absolute value long long m cnvrt krlo overflow s bchte hue
      long long n=llabs((long long)numerator);
      long long d=llabs((long long)denominator);
      //integer part
      res+=to_string(n/d);
      long long rem=n%d;
      if(rem==0)return res;//agar exact divide hua
      //decimal part shuru
      res+='.';
      //remainder k index track krne k liy map
      unordered_map<long long,int>rempos;
      string frac;
      while(rem!=0){
        //agar ye remainder phle aaya tha,to cycle mil gya
        if(rempos.count(rem)){
            int pos=rempos[rem];
            frac.insert(pos,"(");
            frac+=')';
            break;
        }
        rempos[rem]=frac.size();
        rem*=10;
        frac+=char('0'+(rem/d));//quotient digit
        rem%=d;
      }
      res+=frac;
      return res;
    }
};