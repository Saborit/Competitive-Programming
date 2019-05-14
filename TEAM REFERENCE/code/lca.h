/* Lowest Common Ancestor
 *  - Version simple para calcular distancias
 *  
 *  Prec: O(cn*log(cn)) 
 *  Query: O(log(cn)) 
 * 
 *  Tested: http://coj.uci.cu/24h/problem.xhtml?pid=1239  
 * */

struct lca_tree{
    int cn;
    int L[MX], P[MX][20];
    bool mk[MX];
    int64 dist[MX];
    vector<par> G[MX];
    
    void add_edge(int a, int b, int c){
        G[a].pb({b, c});    
        G[b].pb({a, c});    
    }
    
    void dfs(int nod){
        mk[nod] = true;
        
        for(auto i: G[nod]) if( !mk[i.nwn] ){
            P[i.nwn][0] = nod;
            L[i.nwn] = L[nod] + 1;
            dist[i.nwn] = dist[nod] + i.cost;
                
            dfs(i.nwn);    
        }    
            
    }
    
    void build(){
        dist[1] = 0ll, L[1] = 1;
        
        dfs(1);
        
        for(int j=1, l=log2(cn); j<=l; j++)
            for(int i=1; i<=cn; i++)
                P[i][j] = P[ P[i][j-1] ][j-1];        
    }
    
    int query(int a, int b){
        if( L[b] > L[a] )
            swap(a, b);
        for(int i=log2(L[a]); i>=0; i--)
            if( P[a][i] && L[ P[a][i] ] >= L[b] ) 
                a = P[a][i];    
        if( a==b )
            return a;
            
        for(int i=log2(L[a]); i>=0; i--)
            if( P[a][i] && P[a][i] != P[b][i] )
                a = P[a][i], b = P[b][i];
        return P[a][0];
    }
    
    int64 shortest_path(int a, int b){
        return dist[a] + dist[b] - 2ll * dist[query(a, b)];
    }        
};
