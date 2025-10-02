class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
     int full=numBottles;
     int empty=0;
     int totaldrink=0;
     while(full>0){
        totaldrink+=full;
        empty+=full;
        full=0;
        if(empty>=numExchange){
            full=1;
            empty-=numExchange;
            numExchange++;

        }
     }  
     return totaldrink; 
    }
};