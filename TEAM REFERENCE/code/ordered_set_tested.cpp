/* 
   Set con Order Statics  en la STL 

   Para usarlo como multiset se guardan los elementos como un par {element, id}
   y asi diferenciarlos. Luego para hacer referencia a un elemento se busca el 
   par {element, 0}

   Tested: https://codeforces.com/contest/459/problem/D
*/
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 
//Declaracion 
 typedef tree<
    pair<int, int>,
    null_type,
    less< pair<int, int> >,
    rb_tree_tag,
    tree_order_statistics_node_update>
 ordered_set;
 
 int t = 0;
 ordered_set Set;
 
//Insertar
 Set.insert( {T[i], ++t} );
//Eliminar uno 
 Set.erase( Set.lower_bound({T[i], 0}) );
//Cantidad de menores que p
 Set.order_of_key( {p, 0} )
//Cantidad de mayores o iguales que p  
 Set.size() - Set.order_of_key( {p, 0} );
//Cantidad de mayores que p  
 Set.size() - Set.order_of_key( {p + 1, 0} );
//Devuelve un iterador al elemeto en la posicion p (comenzando por cero)
 Set.find_by_order(p)
