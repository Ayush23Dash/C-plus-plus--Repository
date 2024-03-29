#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int top=0,right=c-1,bottom=r-1,left=0;
        int dir=0;
        while(ans.size()!=(r*c))
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
                top++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            else if(dir==3)
            {
                for(int i=bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;

        vector<vector<int>> matrix(r);
        for(int i=0;i<r;i++)
        {
            matrix[i].assign(c,0);
            for(int j=0;j<c;j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int>ans = ob.spirallyTraverse(matrix,r,c);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    }

return 0;
}