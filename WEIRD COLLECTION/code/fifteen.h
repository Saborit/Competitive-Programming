/* Fifteen Puzzle 
 * 
 * Aqui las posiciones son codificadas como permutaciones 
 * desde 1 hasta n**2-1 y INF, donde INF es la casilla vacia
 * 
 * Dadas dos posiciones, se puede llegar de una a otra si 
 * ambas tienen la misma paridad 
 * 
 * */

/* Para N>=1000 usar otro metodo */
int inversions(vector<int>& P){
   int64 ans = 0ll; 
   for(int i=0; i < (int)P.size(); i++)
        for(int j=i+1; j < (int)P.size(); j++)
            if( P[i] > P[j] ) ans++;
            
    return ans;        
}

bool are_reachable(vector<int>& A, vector<int>& B){
    assert( A.size() == B.size() );
    
    return inversions(A) + inversions(B) % 2 == 0;      
}

