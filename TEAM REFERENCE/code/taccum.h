/* Tabla Acumulativa
 * 
 * Se define el rectangulo dentro de una matriz, 
 * de la forma:
 * 
 * o--c--o
 * |     |
 * a     b
 * |     |
 * o--d--o  
 * */
 
struct accumulative{
    int N;
    int A[MX][MX], acum[MX][MX];
    
    void build(){
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                acum[i][j] = acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1], 
                acum[i][j] += A[i][j] > 0;
    }
    
    int query(int a, int b, int c, int d){
        return acum[d][b] - acum[c-1][b] - acum[d][a-1] + acum[c-1][a-1];    
    }    
};
