typedef long long ll;

const ll m=1e9+7;
const ll m2=1e9+9;

const ll p= 31;
const ll p2=37;
// its good to take primes for the values of p and m it reduces the chances of collison 

vector<ll>prod(3e3+10,1); // here i am storing p^i
vector<ll>prod2(3e3+10,1);// here i am storing p2^i for diff consant p


void construct(){
    for(int i=1;i<=3e3+5;i++){
        prod[i]=(prod[i-1]*p)%m;
        prod2[i]=(prod2[i-1]*p2)%m2;


    }
}

class Solution {
   
public:
   
    int distinctEchoSubstrings(string text) {
         construct();


        string s=text;
        ll n=s.size();


    vector<ll>hash(n+2,0);//here i am storing the prefix hash for the 1st set of constants p and m
    vector<ll>hash2(n+2,0); //here i am storing the prefix hash for the 2nd set of constants p2 and m2


    for(int i=0;i<n;i++){
        hash[i+1]=(hash[i]%m+((s[i]-'a'+1)*prod[i])%m)%m;

        hash2[i+1]=(hash2[i]%m2+((s[i]-'a'+1)*prod2[i])%m2)%m2;

    }
    int ans=0;
    set<pair<ll,ll>>st;

    for(int len=2;len<=n;len+=2){
        for(int i=1;i<=n;i++){
            if(i+len-1<=n){ll rh1= ((hash[i+len-1]-hash[i+len/2-1]+m)%m*prod[n-i-len/2]%m)%m;

            ll lh1=(((hash[i+len/2-1]-hash[i-1]+m) %m)* (prod[n-i]%m)%m);

            ll rh2=(((hash2[i+len-1]-hash2[i+len/2-1]+m2)%m2)*(prod2[n-i-len/2]%m2))%m2;

            ll lh2=((hash2[i+len/2-1]-hash2[i-1]+m2) %m2* prod2[n-i]%m2)%m2;

            
            if(make_pair(rh1,rh2)==make_pair(lh1,lh2)){st.insert({rh1,rh2});}
            
            
            }
        }
        
    }



return st.size();

        
    }
};