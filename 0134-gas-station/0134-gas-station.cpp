class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int current=0;
     int total_fuel=0,total_cost=0;
     int start=0;
     int n=gas.size();
     for(int i=0;i<n;i++){
           total_fuel+=gas[i];

     } 
     for(int i=0;i<cost.size();i++){
        total_cost+=cost[i];
     }  
     if(total_cost>total_fuel)
     return -1;
    
    for(int i=0;i<n;i++){
    current+=(gas[i]-cost[i]);
    if(current<0){
    start=i+1;
    current=0;
        }
            }
    return start;
    }
};