class Solution {
public:
    int countPrimes(int n) {
        //n tak k no m prime cnt kro
        vector<bool>isprime(n,true);//sb no ko prime manlo
        if(n<=2)return 0;//agr n 2 ya usse km h toh koi prime ni
        isprime[0]=false;//o prime hota h
        isprime[1]=false;//1prime hota h
        int limit =sqrt(n);//srf sqrt(n) tk chck krna kafi h
        for(int i=2;i<=limit;i++){//2 s phle sqrt(n) chlaynge
          if(isprime[i]){//agr i abhi bhi prime h
            for(int j=i*i;j<n;j+=i){//i ke multipliers ko mrk krdo
                 isprime[j]=false;//ulta mrk krte h hmesha // ye trick h ki hmeshe neeche s chalu krnge ya to false mark krnge
            }
          }
        }
        int cnt=0;// prime cnt krne k liy variable h
        for(int i=2;i<n;i++){//2 s n-1 tk chck kro
            if(isprime[i])//agr prime h
             cnt++;//cnt bda do
        }
        return cnt;// no of cnt return krdo
    }

};
