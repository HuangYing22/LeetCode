class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        //int res=INT_MAX;
        int res;
        vector<vector<int>> pathT = triangle;
        int n = triangle.size();
        int i,j;
        for(i=1;i<n;i++) {
            pathT[i][0] += pathT[i-1][0];
            pathT[i][i] += pathT[i-1][i-1];
        }
        //cout<<"loop1"<<endl;
        for(i=2;i<n;i++) {
            //for (j=1;j<n-1;j++) {
            for(j=1;j<i;j++) {
                if(pathT[i-1][j-1] < pathT[i-1][j]) {
                    pathT[i][j] += pathT[i-1][j-1];
                } else {
                    pathT[i][j] += pathT[i-1][j];
                }
            }
        }
        //cout<<"loop2"<<endl;
        res = pathT[n-1][0];
        for(i=0;i<n;i++) {
            if(pathT[n-1][i]<res) {
                res = pathT[n-1][i];
            }
        }
        //cout<<"loop3"<<endl;
        return res;
    }
};
