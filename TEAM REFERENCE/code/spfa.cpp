/* Shortest Path Faster Algorithm + Small-Label-First Optimization
 * 
 * Simple SPFA, excepto que al meter un nodo en la cola, 
 * si la distancia del frente de la cola es mayor que la 
 * de este nodo, en lugar de meterlo detras lo colocamos de primero  
 * 
 * Expected Complexity: O(E) 
 * 
 * Tested : [roadplane link]
 **/

bool in_queue[MX];
deque<int> Q;

void add_node(int nod){
    if( !in_queue[nod] ){
        if( dist[nod] < dist[Q.front()] )
            Q.push_front(nod);
        else 
            Q.push_back(nod);
        in_queue[nod] = true;
    }      
}

/* Inside the main */
  
for(int i=1; i<=cn; i++) dist[i] = INF;
dist[ni] = 0;
     
for(Q.push_back(ni); !Q.empty(); ){
    int nod = Q.front(); 
    Q.pop_front();
         
    in_queue[nod] = false;
         
    for(auto i: G[nod]){
        if( dist[i.nwn] > dist[nod] + i.cost ){
            dist[i.nwn] = dist[nod] + i.cost;
            add_node(i.nwn);
        }     
    }
}
 
