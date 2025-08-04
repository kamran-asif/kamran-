class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0,maxlen=0;
        unordered_map<int,int>basket;
        for(int end=0;end<fruits.size();end++){
            basket[fruits[end]]++;
            while(basket.size()>2){
                basket[fruits[start]]--;
                if(basket[fruits[start]]==0){
                    basket.erase(fruits[start]);                }
                    start++;
            }
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
    }
};