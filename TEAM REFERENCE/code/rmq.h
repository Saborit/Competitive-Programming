/* Range Min-Max Query (template)
 * 
 * - El constructor acepta el areglo base, el numero de elementos, 
 * y una funcion asociativa(min, max, gcd, ...) 
 * 
 * - En la mayoria de los casos hay que programar nuestras funciones  
 * 
 * */

template<class any>
struct rmq{
     int N;
     function<any(any, any)> f;
     vector< vector<any> > T;
     
     rmq(any *A, int sz, any (*fun)(any, any)){
         N = sz;
         f = *fun;
         T.resize(sz + 5, vector<any>(20, 0) );
         
         for(int i=1; i<=N; i++)
             T[i][0] = A[i];
             
         for(int j=1, l=log2(N); j<=l; j++){
             N -= 1<<(j-1); 
             for(int i=1; i<=N; i++)
                 T[i][j] = f(T[i][j-1], T[i + (1<<(j-1))][j-1]);
         }    
         N = sz;    
     }
     
     any query(int a, int b){
         int l = log2(b-a+1);
         return f(T[a][l], T[b-(1<<l)+1][l]);
     }  
};

inline int _min(int a, int b){ return min(a, b); }
inline int _max(int a, int b){ return max(a, b); }
