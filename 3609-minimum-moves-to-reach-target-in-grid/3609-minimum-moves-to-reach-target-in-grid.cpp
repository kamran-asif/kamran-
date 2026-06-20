class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
      long long x=tx;
      long long y=ty;
      int moves=0;
      while(x>=sx&&y>=sy){
        if(x==sx&&y==sy){
            return moves;
        }
        if(x==y){
        if(sx==0&&sy<=y){
        x=0;
      }  else if(sy==0&&sx<=x){
       y=0;
      }else{
        return -1;
      }
      moves++;
      continue;

    }
    if(x>y){
        if(x>=2*y){
            if(x%2!=0)return -1;
            x/=2;
        }else{
            x-=y;
        }
        moves++;
    }else{
        if(y>=2*x){
            if(y%2!=0)return -1;
            y/=2;
        }else{y-=x;
    }
    moves++;}
    }
    return -1;
    }
};