class Solution {
public:
int largestrectanglearea(vector<int>&heights){
 int n=heights.size();
        stack<int>st;
        int maxarea=0;
        for(int i=0;i<=n;i++){
    
          int h=(i==n)?0:heights[i];//yha is quesn m h=kaise nikale ye bta rha smjha be baaki quesn m aisa ni h ki h nikalne ko bole
          while(!st.empty()&& h<heights[st.top()]){// bhai ye condn to cmmn h hr jgh use hota h smjha bhai yaad krlo
            int height=heights[st.top()];
            st.pop();
            int left=st.empty()?0:st.top()+1;//similar pattrn pr yha left nikalna pd rha baki m ni nikalne pdta h 
            int width=i-left;//
            maxarea=max(maxarea,height*width);
          }
          st.push(i);
        }
        return maxarea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {//extra h baaki m ye sb dlali ni krna pdta
    //base condn hai
            if(matrix.empty()||matrix[0].empty())return 0;
            int rows=matrix.size();
            int cols=matrix[0].size();
            vector<int>heights(cols,0);
            int maxrect=0;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(matrix[i][j]=='1'){
                        heights[j]+=1;

                    }else{
                        heights[j]=0;
                    }
                }
                maxrect=max(maxrect,largestrectanglearea(heights));//func call h
            }
          return maxrect;
    }
};