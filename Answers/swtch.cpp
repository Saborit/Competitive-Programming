/* Cambiando Luces [LongFan, 2008] */
 #include<bits/stdc++.h>
 using namespace std;

 int n, q, duty, best, a, b;
 bool L[501];

 main(){
     //freopen("swtch.in", "r", stdin);
     //freopen(".out", "w", stdout);

     scanf("%d%d", &n, &q);
     while(q--){
         scanf("%d%d%d", &duty, &a, &b);
         if(!duty){
            for(int i=a; i<=b; i++)
                L[i] ^= 1;
         }
         else{
            best = 0;
            for(int i=a; i<=b; i++)
                best += L[i];
            printf("%d\n", best);
         }
     }


    return 0;
 }
