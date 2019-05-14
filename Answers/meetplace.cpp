/*  */
 #include<bits/stdc++.h>
 using namespace std;

 int cn, a, b, q;
 int L[1001], P[1001][20];
 vector<int>G[1001];
 queue<int>Q;

 int lc_ancestor(int a, int b){
    if(L[a] < L[b])
       swap(a, b);

    for(int i=log2(L[a]); i>=0; i--)
        if(L[P[a][i]] >= L[b])
           a = P[a][i];
    if(a==b)
       return a;

    for(int i=log2(L[a]); i>=0; i--)
        if(P[a][i]!=P[b][i] && P[a][i])
           a = P[a][i], b = P[b][i];

    return P[a][0];
 }

 main(){
     freopen("meetplace.in", "r", stdin);
     //freopen(".out", "w", stdout);

     scanf("%d%d", &cn, &q);
     for(int i=2; i<=cn; i++){
        scanf("%d", &P[i][0]);
        G[P[i][0]].push_back(i);
     }

     for(Q.push(1), L[1] = 1; !Q.empty(); Q.pop()){
         int nod = Q.front();

        for(int i=0; i < G[nod].size(); i++){
            int nwn = G[nod][i];
            L[nwn] = L[nod] + 1;
            Q.push(nwn);
        }
     }

     for(int j=1; j<=log2(cn); j++)
         for(int i=1; i<=cn; i++)
             P[i][j] = P[P[i][j-1]][j-1];

     for(int i=1; i<=cn; i++){
         for(int j=0; j<=log2(cn); j++){
             cout<<P[i][j]<<" ";
         }cout<<endl;
     }

     while(q--){
          scanf("%d%d", &a, &b);
          printf("%d\n", lc_ancestor(a, b));
     }



    return 0;
 }
