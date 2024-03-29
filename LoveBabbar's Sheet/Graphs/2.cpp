#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>vis(V,0);
        queue<int>q;

                q.push(0);
                vis[0]=1;
                while(!q.empty()){
                    int node = q.front();
                    ans.push_back(node);
                    for(auto it:adj[node]){
                        
                        if(vis[it]==0){
                            q.push(it);
                            vis[it]=1;
                        }
                        
                    }
                    q.pop();
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

	int tc;
	cin>>tc;
	while(tc--){
		int V,E;
		cin>>V>>E;
		vector<int>adj[V];
		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector<int>ans = obj.bfsOfGraph(V,adj);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}