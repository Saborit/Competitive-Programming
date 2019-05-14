/* 
    Kahn's Algorithm

    -  Seudocodigo:
       enqueue vertices with zero incoming degree into a (priority) queue Q;
       while (Q is not empty) {
          vertex u = Q.dequeue(); 
          put vertex u into a topological sort list;
          remove this vertex u and all outgoing edges from this vertex;
        
          if such removal causes vertex v to have zero incoming degree
          Q.enqueue(v); 
      }
    - delta guarda el grado de entrada de los nodos
      llenarlo en la entrada
    - Si al final ans no contiene todos los nodos del grafo, el grafo
     tiene un ciclo 
    - Si se una una cola de prioridad el orden de los nodos es el menor
      lexicograficamente. 

    Tested: http://usaco.org/index.php?page=viewproblem2&cpid=838
*/
 
 vector<int> kahn(vector<int>& delta){
     vector<int> ans;
     
     for(int i=1; i<=cn; i++){
        if( !delta[i] )
           Q.push(i);

        off[i] = false;
     }

     for(; !Q.empty(); ){
        int nod = Q.top();
        Q.pop(); 
        ans.push_back(nod);
        
        off[nod] = true;
        for(auto i: G[nod]){
             delta[i.nwn]--;
            
            if( !delta[i.nwn] && !off[i.nwn] )
                Q.push(i.nwn);    
        }
    }

    return ans;
 }

