/* Knight's Tour 
 * 
 * Regla de Warnsdorf para obtener un recorrido completo del caballo 
 * sobre el tablero de ajedrez de talla N*N
 * 
 * - Devuelve una matriz 1-indexada con las casillas numeradas de 
 *   1 a N^2 segun el recorrido obtenido. Este recorrido no es unico.  
 * 
 * */

#define POSSIBLE (X > 0 && X<=N && Y > 0 && Y<=N) 
typedef vector<vector<int>> matrix;

const int dx[] = {-1, -2, -2, -1,  1, 2,  2,  1}; 
const int dy[] = {-2, -1,  1,  2,  2, 1, -1, -2}; 

matrix warnsdorf(int N){
    matrix ans(N+1, vector<int>(N+1, 0));    
    matrix C(N+1, vector<int>(N+1, 0));
    
    int x, y, X, Y, min_moves, min_x, min_y;
    
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
        for(int k=0; k < 8; k++){
            X = i + dx[k];
            Y = j + dy[k];
            
            if( POSSIBLE ) C[i][j]++;
    }
    
    x = 1, y = 1;
    for(int i=1; i<=N * N; i++){
        ans[x][y] = i;
        min_moves = INF;
        
        for(int j=0; j < 8; j++){
            X = x + dx[j];    
            Y = y + dy[j];   
            
            if( !POSSIBLE ) continue;
            
            C[X][Y]--;
            
            if( !ans[X][Y] && min_moves > C[X][Y] )
                min_x = X, min_y = Y, min_moves = C[X][Y];   
        }
        
        x = min_x, y = min_y;     
    }
    return ans;           
}
