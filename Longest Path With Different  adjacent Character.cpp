class Solution {
public:
    int fans;
    int cal(vector<vector<int>> &adj,int u,map<int,int> &mp,char prev){
        
        if(adj[u].size()==0)
            return 1;
        
        int res=1;
        vector<int> child(adj[u].size(),0);
        vector<int> c(adj[u].size(),1);
        vector<int> v;
        
        for(int i=0;i<adj[u].size();i++){
            child[i]=cal(adj,adj[u][i],mp,mp[u]);
            if(mp[adj[u][i]]!=mp[u]){
                v.push_back(child[i]);
                c[i]+=child[i];
            }
        }
        
        sort(v.begin(),v.end(),greater<int>());
        if(v.size()>0){
            res+=v[0];
            if(v.size()>1){
                res+=v[1];
            }
        }
        
        fans=max(fans,res);
        int t=*max_element(c.begin(),c.end());
        fans=max(fans,t);
        cout<<t<<" ";
        return t;
    }
    int longestPath(vector<int>& parent, string s) {
        
        int n=parent.size();
        fans=0;
        vector<vector<int> > adj(n);
        map<int,int> mp;
        if(parent.size()==1){
            return 1;
        }
        
        for(int i=0;i<s.size();i++){
            mp[i]=s[i];
        }
        
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        
        cal(adj,0,mp,'-');
        return fans;
        
    }
};
