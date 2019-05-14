/* Suffix Array
 * 
 * - Las posiciones de cada sufijo i en el orden del suffix array 
 *   se guardan en la fila P[i][k-1]
 * - Prec: O(N * log^2(N))
 * - lcp: O(log(N))
 * 
 * Tested on: hackerrank.com/challenges/string-similarity/problem
**/

struct suffix{
    int a, b, p;
    
    bool operator < (const suffix &p)const{
        return a==p.a ? b < p.b : a < p.a;    
    }
    bool operator == (const suffix &p)const{
        return a==p.a && b == p.b;    
    }     
};

struct suffix_array{
    int ls, k, del;
    vector<vector<int> > P; 
    suffix L[MX];
    
    suffix_array():
        P(MX, vector<int>(20, 0))
    {}
    
    void build(char *S){
        ls = strlen(S);
        
        for(int i=0; i < ls; i++)
            P[i][0] = S[i] - 'a';
           
        for(k=del=1; (del>>1) < ls; k++, del<<=1) {
            for(int i=0; i < ls; i++){
                L[i].a = P[i][k-1];
                L[i].b = (i + del < ls) ? P[i+del][k-1] : -1;
                L[i].p = i;
            }
            sort(L, L+ls);
            
            for(int i=0; i < ls; i++)
                P[ L[i].p ][k] = (i && L[i]==L[i-1]) ? P[ L[i-1].p ][k]: i;
        }   
    }
    
    int lcp(int x, int y){
        if( x==y ) return ls-x;
        
        int ans = 0;
        
        for(int i=k-1; i>=0 && x < ls && y < ls; i--){
            if( P[x][i] == P[y][i] ) 
                x += (1<<i), y += (1<<i), ans+=(1<<i);    
        }   
        return ans; 
    }
};
