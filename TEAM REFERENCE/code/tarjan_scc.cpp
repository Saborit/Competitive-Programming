/* Tarjan's SCC Algorithm
 * - inc guarda si el nodo esta actualmente en la componente 
 *   fuertemente conexa. El dt de un nodo solo actualiza a otro si 
 *   esta destro de la pila.  
**/ 

 void tarjan_scc(int nod){
     dt[nod] = low[nod] = ++t;
     K.push(nod);
     inc[nod] = true;

     for(auto nwn: G[nod]){
         if( !dt[nwn] ){
             tarjan_scc(nwn);
             low[nod] = min(low[nod], low[nwn]);
         }
         else if( inc[nwn] )
             low[nod] = min(low[nod], dt[nwn]);
     }

     if( dt[nod] == low[nod] ){
         while( K.top() != nod ){
             SET[K.top()] = nod;
             inc[K.top()] = false;
             K.pop();
         }
         SET[K.top()] = nod;
         inc[K.top()] = false;
         K.pop();
     }
 }
