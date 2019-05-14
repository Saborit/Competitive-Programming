/* Maximo Flujo */
 #include <bits/stdc++.h>
 using namespace std;

 int cn, q, sol;
 int L[50010], P[50010][22], C[50010], acum[50010];
 bool mk[50010];
 vector<int> G[50010];

 void dfs(int nod){
    mk[nod] = 1;

    for(int i=0; i < G[nod].size(); i++){
        int nwn = G[nod][i];
        if(mk[nwn])
           continue;

        L[nwn] = L[nod] + 1;
        P[nwn][0] = nod;
        dfs(nwn);
    }
 }

 int dfs_graph(int nod){
    mk[nod] = 1;

    acum[nod] = C[nod];
    for(int i=0; i < G[nod].size(); i++){
       int nwn = G[nod][i];
       if(mk[nwn])
          continue;
       acum[nod] += dfs_graph(nwn);
    }
    sol = max(sol, acum[nod]);
    return acum[nod];
 }

 int lca(int a, int b){
      if(L[a] < L[b])
         swap(a, b);

      for(int i=log2(L[a]); i>=0; i--)
          if(L[P[a][i]]>=L[b])
             a = P[a][i];
      if(a==b)
         return a;

      for(int i=log2(L[a]); i>=0; i--)
          if(P[a][i]!=P[b][i] && P[a][i])
             a = P[a][i], b = P[b][i];

      return P[a][0];
 }

 main(){
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);

    scanf("%d%d", &cn, &q);
    for(int i=1, a, b; i < cn; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    L[1] = 1;
    dfs(1);

    for(int j=1; j<=log2(cn); j++)
        for(int i=1; i<=cn; i++)
            P[i][j] = P[P[i][j-1]][j-1];

    int a, b;
    while(q--){
        scanf("%d%d", &a, &b);
        C[a]++, C[b]++;
        int c = lca(a, b);
        C[c]--;
        if(P[c][0])
           C[P[c][0]]--;

    }


    fill(mk, mk+cn+1, 0);
    dfs_graph(1);


    printf("%d\n", sol);

   return 0;
 }
/*
for(int i=1; i<=cn; i++){
        for(int j=0; j<=log2(cn); j++){
            cout<<" "<<P[i][j];
        }cout<<endl;
    }
*/
