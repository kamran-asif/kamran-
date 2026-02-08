class Solution {
public://greedy+bfs style jaisa h
    int jump(vector<int>& nums) {
        int start=0,end=0,cnt=0;
//same jum1 ki trh bss yha end>n-1 h or strt=nums[i] end=nums[i+j] h
        while(end<nums.size()-1){
            int maxindex=0;
            for(int i=start;i<=end;i++){
                maxindex=max(maxindex,i+nums[i]);
            }
             start=end+1;
            end=maxindex;
            cnt++;
        }
        return cnt;
    }
};
