/* Odd-Size Magic Square 
 * 
 * La suma de los enteros en cada columna, fila o diagonal es
 * la misma (n**2 + 1) * n/2   
 * 
 * N - numero de filas/columnas (N es par)
 * 
 * Se implementa el metodo Siamese (De la Loubere)
 * 
 *  */
 
vector<vector<int>> magic_square(int N){
     vector<vector<int>> ans(N);
     for(auto& i: ans) 
         i = vector<int>(N);
     
     int i=0, j=N/2;
     for(int num=1; num<=N*N; num++){
         ans[i][j] = num;
         
         int ii = (i-1+N) % N; 
         int jj = (j+1+N) % N;
          
         if( ans[ii][jj] ) 
            i = (i+1) % N;
         else
            i = ii, j = jj;
     }     
     
     return ans;
}
