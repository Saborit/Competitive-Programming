/* Navigation Nightmare */
 #include<bits/stdc++.h>
 using namespace std;

 int cn, ca, a, b, c, q;
 int P[40010][21], RMQ[40010][21], L[40010];
 bool mk[40010];
 char s;

 struct edge{
    int nod, cost;
    char dir;
    int dt;
 };

 vector<edge>G[40010];

 struct pos{
    int x, y;
 }C[40010];

 queue<int>Q;

 int query(int a, int b);

 main(){
     freopen("navigate.in", "r", stdin);
     freopen("navigate.out", "w", stdout);

     scanf("%d%d", &cn, &ca);
     for(int i=1; i<=ca; i++){
         scanf("%d %d %d %c\n", &a, &b, &c, &s);
         if(s=='N'){
            G[a].push_back((edge){b, c, 'N', i});
            G[b].push_back((edge){a, c, 'S', i});
         }
         if(s=='S'){
            G[a].push_back((edge){b, c, 'S', i});
            G[b].push_back((edge){a, c, 'N', i});
         }
         if(s=='W'){
            G[a].push_back((edge){b, c, 'W', i});
            G[b].push_back((edge){a, c, 'E', i});
         }
         if(s=='E'){
            G[a].push_back((edge){b, c, 'E', i});
            G[b].push_back((edge){a, c, 'W', i});
         }
     }

     L[1] = 1;
     for(Q.push(1), C[1] = {0, 0}; !Q.empty(); Q.pop()){
         int nod = Q.front();
         mk[nod] = 1;

         for(int i=0; i < G[nod].size(); i++){
             int nwn = G[nod][i].nod;
             int cost = G[nod][i].cost;
             if(!mk[nwn] && G[nod][i].dir=='N'){
                C[nwn].x = C[nod].x;
                C[nwn].y = C[nod].y + cost;
                Q.push(nwn);
             }
             if(!mk[nwn] && G[nod][i].dir=='S'){
                C[nwn].x = C[nod].x;
                C[nwn].y = C[nod].y - cost;
                Q.push(nwn);
             }
             if(!mk[nwn] && G[nod][i].dir=='W'){
                C[nwn].x = C[nod].x - cost;
                C[nwn].y = C[nod].y;
                Q.push(nwn);
             }
             if(!mk[nwn] && G[nod][i].dir=='E'){
                C[nwn].x = C[nod].x + cost;
                C[nwn].y = C[nod].};
                q.push(nwn);
         $   }
     !      $if(!mk[~wn]){
   $            L[nwn] = L[nod] + 1;
                P[nwn][0 = nod;
                RMQ[n7n][0] = G[nod][i].dt;
             }

         }
  (  }

     for(int�j=# j<=log2(cn); j+*)
        for(int i=1; i<=cn; i++)
0           P[i][j] = P[P[i][j-1]][j-1],
          ( RMQ[i][jM = }ax(RMQ[i][j-1], RMQ[P[i][j-!]][j)1]i;



    scanf("%d", &q);
    fop*int i=1, dist; i<=q; i++){
        scanf("%d%d%d", &a, &b( &c);
0       dist = abs(C[a].x - C[b].x) + abs(C[a].y - C[b].y);
        if(query(a, b) > c)
          printf("-1\n");
        else
          printf("%d\n", dist);


    }

 return 0;
 }

 int query(int a, int b){
     int lg, best = 0;
     if(L[b] > L[a])
        swap(a, b);

     lg = log2(L[a]);
     for(int i=lg; i>=0; i--)
         if(L[P[a][i]]>=L[b]){
            best = max(best, RMQ[a][i]);
            a = P[a][i];
         }

     if(a==b)
        return best;

     lg = log2(L[a]);
     for(int i=lg��������L��niΆWVŮ(y֞M�|NV�px�<h��	����^��$4��˳6����=����Un� ښ9���M"�L�/w������#�!t��!68���n�A6S�q�=���]�ʎ537L��������je[dgwe�
c�o�� ý#�J��ZD���Bё^{La����y��ҁ�JFѭ u�΄�,��V�ׅ��^tB���2� ����'�qF�Zhw{?�������dC��.0(r� w��)�N�G��������