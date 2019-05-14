/*  */
 #include<bits/stdc++.h>
 using namespace std;

 int A[100005], n, k, st, ed, p;

 bool check(int p){
    int last = 1, c = 1;

    for(int i=2; i<=n; i++){
        if(A[i] >= A[last] + p){
           c++;
           last = i;
//           cout<<"Here in "<<last<<endl;
        }
    }
    return c>=k;
 }


 main(){
     freopen("aggr.in", "r", stdin);
     freopen("aggr.out", "w", stdout);

     scanf("%d%d", &n, &k);
     for(int i=1; i<=n; i++)
         scanf("%d", &A[i]);

     sort(A+1, A+n+1);

     for(st = 0, ed = 1e9; st<=ed; ){
         p = (st + ed)/2;
         if(check(p) && check(p+1)){
            st = p + 1;
            continue;
         }
         if(!check(p) && !check(p+1)){
            ed = p - 1;
            continue;
         }
         if(check(p) && !check(p+1)){
            break;
         }
     }
     cout<<p<<endl;

 return 0;
 }
