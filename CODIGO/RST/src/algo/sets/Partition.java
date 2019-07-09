package algo.sets;

import algo.exception.BadParameterException;
import java.util.List;

/**
 *
 * @author zero
 */
public class Partition {
    private final int[] SET, R, sz;
    
    public Partition(int cantInst) {
        SET = new int[cantInst];
        R   = new int[cantInst];
        sz   = new int[cantInst];
        
        for(int i=0; i < cantInst; i++){
            SET[i] = i;
            R[i] = sz[i] = 1;
        }
    }
    
    /**
     * Encuentra la clase de equivalencia a la que pertenece una instancia
     * @param inst Indice de la instancia
     * @return El indice de la instancia que representa a la clase de equivalencia
     * @throws algo.exception.BadParameterException
     */
    public int findSet(int inst) throws BadParameterException{
        if( !(0<=inst && inst < SET.length) )
            throw new BadParameterException();
        
        if( SET[inst] != inst )
            return SET[inst] = findSet(SET[inst]);
        return inst;
    }
    
    /**
     * Adiciona un relacion entre dos instancias, haciendolas pertenecer a una 
     * misma clase de equivalencia.
     * 
     * @param inst1 Indice de una instancia
     * @param inst2 Indice de una instancia
     * @return Verdadero si las instancias ya eran de la misma clase, falso en 
     *         caso contrario. 
     * @throws algo.exception.BadParameterException 
     */
    public boolean addRelation(int inst1, int inst2) throws BadParameterException{
        int setnod = findSet(inst1);
        int setnwn = findSet(inst2);
        
        if( setnod != setnwn ){
            if( R[setnod] > R[setnwn] ){
                SET[setnwn] = setnod;
                R[setnod]++;
                sz[setnod] += sz[setnwn];
            }
            else{
                SET[setnod] = setnwn;
                R[setnwn]++;
                sz[setnwn] += sz[setnod];
            }
            return false;
        }
        else return true;
    }
    
    /**
     * Calcula si cada elemento del universo pertenece o no a una clase de 
     * equivalencia que es subconjunto de un conjunto dado. 
     * 
     * @param set Conjunto, subconjunto del universo
     * @return Un arreglo binario donde la posicion esta en true si el elemento 
     *      pertenece a dicha clase de equivalencia.
     * @throws algo.exception.BadParameterException
     */
    public boolean[] isInSubsetClass(List<Integer> set) throws BadParameterException{
        int[] count = new int[SET.length];
        boolean[] ans = new boolean[SET.length];
        
        for(Integer x: set){ 
            int setnod = findSet(x);
            
            count[setnod]++;
            
            if( count[setnod] == sz[setnod] )
                ans[setnod] = true;
        }
        
        for(int i=0; i < SET.length; i++) 
            ans[i] = ans[findSet(i)];
        
        return ans;
    }
    
    /**
     * Calcula si cada elemento del universo pertenece o no a una clase de 
     * equivalencia cuya interseccion con un conjunto dado, no es vacia. 
     * 
     * @param set Conjunto, subconjunto del universo
     * @return Un arreglo binario donde la posicion esta en true si el elemento 
     * pertenece a dicha clase de equivalencia.
     * @throws algo.exception.BadParameterException
     */
    public boolean[] isInIntersectionClass(List<Integer> set) throws BadParameterException{
        boolean[] ans = new boolean[SET.length];
        
        for(Integer x: set)
            ans[findSet(x)] = true;
        
        for(int i=0; i < SET.length; i++)
            ans[i] = ans[findSet(i)];
        
        return ans;
    }
            
    public int sizeOfClass(int x) throws BadParameterException{
        return sz[findSet(x)];
    }
    
    /**
     * Calcula la interseccion entre la clase de equivalencia de un elemento 
     *      y el conjunto.
     * @param elem Elemento perteneciente a la clase de equivalencia
     * @param set Conjunto de numeros enteros  
     * @return El conjunto interseccion
     * @throws BadParameterException 
     */
    public Set<Integer> intersectClassWith(int elem, Set<Integer> set) throws BadParameterException {
        Set<Integer> ans = new Set<>();
        int setElem = findSet(elem);
        
        for(Integer x: set.getElements())
            if( findSet(x) == setElem )
                ans.getElements().add(x);
        
        return ans;
    }
}
