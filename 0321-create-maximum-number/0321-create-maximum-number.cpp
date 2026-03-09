class Solution {
public:
//
vector<int>maxsubsequence(const vector<int>&nums,int k){
    vector<int>stack;
    int drop=nums.size()-k;
    for(int x:nums){

        while(!stack.empty()&&drop>0&&stack.back()<x){
            stack.pop_back();
            drop--;
        }
        stack.push_back(x);
    }
    stack.resize(k);
    return stack;
}
vector<int>mergemax(const vector<int>&a,const vector<int>&b){
    vector<int>ans;
    int i=0,j=0,m=a.size(),n=b.size();
    while(i<m||j<n){
        if(lexicographical_compare(a.begin()+i,a.end(),b.begin()+j,b.end())){
            ans.push_back(b[j++]);

        }else{
            ans.push_back(a[i++]);
        }
    }
    return ans;
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        vector<int>best;
        for(int i=max(0,k-n);i<=min(k,m);i++){
            vector<int>subseq1=maxsubsequence(nums1,i);
            vector<int>subseq2=maxsubsequence(nums2,k-i);
            vector<int>candidate=mergemax(subseq1,subseq2);
            if(candidate>best){
                best=candidate;
            }
        }
        return best;
    }
};
