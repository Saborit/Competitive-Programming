/* Algoritmo de Euclides Extendido
 * 
 * Devuelve en un objeto de tipo gcd, tres valores x y d tal que para los
 * a y b dados, se cumple que ax + by = d
 * 
 * - Puede que el nombre de la estructura "gcd" no sea aceptado por algunos
 *   compiladores.  
 * - Tested on: https://open.kattis.com/problems/generalchineseremainder
 * */

struct gcd{ int64 x, y, d; };

gcd ext_euclid(int64 a, int64 b){
    if( !b ) return {1, 0, a};
    gcd d = ext_euclid(b, a%b);
    return {d.y, d.x -(a/b) * d.y, d.d};    
}
