/*  Aho-Corasick
 * 
 * - Implementacion con arreglo de vectores
 * 
 * - T es el Trie, ac[i] guarda los ids de las cadenas que 
 *   terminan en el nodo i, y F es un arreglo de punteros 
 *   enteros al nodo del sufijo propio mas largo que es tambien 
 *   sufijo de un patron.    
 * 
 * - match() devuelve un vector de pares donde cada par guarda el 
 *   1-indice del patron segun el orden en que fueron agregados 
 *   al trie y la ultima posicion de una ocurrencia. 
 * 
 * - cn es la cantidad de nodos y sz es la cantidad de cadenas 
 *   almacenadas
 * 
 * - Se puede guardar tambien el largo de las cadenas en un arreglo 
 *   aparte para deducir el comienzo de las ocurrencias.
 *   
 * - Tested on: Croatia 2006 severina 
 * 
 * */

#define SIGMA 26

struct aho_corasick{
     int cn, sz;
     int F[MX];
     vector<int> T[MX], ac[MX];
     
     aho_corasick(){
        cn = 1, sz = 0;
        T[0] = vector<int>(SIGMA, -1);
     }
     
     void add(char S[]){
         int nod = 0;
         int N = strlen(S);
         sz++;
         
         for(int i=0; i < N; i++){
             int c = S[i] - 'a';
             
             if( T[nod][c] == -1 ){
                 T[++cn] = vector<int>(SIGMA, -1);
                 T[nod][c] = cn; 
             }
             nod = T[nod][c];
         }
         ac[nod].pb(sz);
     }
     
     void build(){
         queue<int> Q;
         for(int c=0; c < SIGMA; c++) if( T[0][c] != -1 )
             Q.push(T[0][c]);
             
         for(; !Q.empty(); Q.pop() ){
             int nod = Q.front();
             
             for(int c=0; c < SIGMA; c++) if( T[nod][c] != -1 ){
                 int st = F[nod];
                 
                 while( st > 0 && T[st][c] == -1 ) st = F[st];
                 
                 if( T[st][c] != -1 ) 
                     st = T[st][c];
                 F[ T[nod][c] ] = st;
                 
                 for(auto i: ac[st]) ac[ T[nod][c] ].pb(i);
                 
                 Q.push(T[nod][c]);        
             }    
         }       
     }
     
     vector< pair<int, int> > match(char A[]){
         int N = strlen(A);
         vector< pair<int, int> > ans;
          
         for(int i=0, st=0; i < N; i++){
             int c = A[i] - 'a';
             
             while( st > 0 && T[st][c] == -1 ) st = F[st];
             
             if( T[st][c] != -1 ){
                 st = T[st][c];
                 
                 for(auto feat: ac[st])  ans.pb({feat, i});                 
             }        
         }
         
         return ans;    
     }
};
