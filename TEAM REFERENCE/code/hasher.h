/**
 * Hash para Strings
 * 
 * - Llamar a init() dentro del main 
 * - Preproc: O(n)
 * - compare(int a, int b, int len) devuelve true 
 *   si S[a+len-1] == S[b+len-1] en O(1)
 * - hashing(int a, int b) devuelve el hashing relativo de 
 *   la subcadena S[a..b] en O(1). Dos hashings de este tipo
 *   pero pertenecientes a dos cadenas diferentes, pueden 
 *   compararse si la basede ambos es la misma.   
 * 
 * Tested: http://coj.uci.cu/24h/problem.xhtml?pid=1624 
 ***/

const unt64 p = 31ull;
unt64 P[MX]; 

void init(){
    P[0] = 1ull;
    
    for(int i=1; i < MX; i++)
        P[i] = P[i-1] * p;
}

struct hasher{
    int l;
    unt64 H[MX];

    hasher(){}
    hasher(string &S){
        l = S.size();
      
        for(int i=0; i < l; i++){
            H[i] = (unt64)(S[i] - 'a' + 1) * P[i];
         
            H[i] += i ? H[i-1] : 0ull;
        }
    }
    /* not tested yet */
    bool compare(int a, int b, int len){
        if(b < a) swap(a, b);
       
        unt64 h1 = H[a + len - 1]; if(a) h1 -= H[a-1];
        unt64 h2 = H[b + len - 1]; if(b) h2 -= H[b-1];

        if( h1 * P[b - a] == h2 )    
            return true;
        else
            return false;
    }

    unt64 hashing(int a, int b){
        if( a > b ) return 0ull;
        return (H[b] + ( a ? (1ull<<64) - H[a-1] : 0ull)) * P[MX-1-a];
    }
 };
 
