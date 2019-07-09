package algo.sets;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 *
 * @author zero
 * @param <T> Tipo de los elementos por los que esta formado el conjunto 
 */
public class Set<T extends Comparable<T>> implements Comparable<Set<T>> {
    private List<T> elements;

    public Set() {
        elements = new ArrayList<>();
    }
    
    public Set(List<T> elements) {
        this.elements = elements;
        
        Collections.sort(elements);
    }
    
    public Set<T> union(Set<T> other) {
        Set<T> ans = new Set<>();
        
        for(T x: this.elements)
            ans.elements.add(x);
        
        for(T x: other.elements)
            ans.elements.add(x);
        
        Collections.sort(ans.elements);
        
        return ans;
    } 
    
    public Set<T> intersection(Set<T> other){
        Set<T> ans = new Set<>();
        
        int k=0;
        for(T x: this.elements){
            while( k < other.elements.size() && other.elements.get(k).compareTo(x) < 0 )
                k++;
            
            if( k < other.elements.size() && other.elements.get(k).compareTo(x) == 0 )
                ans.elements.add(x);
        }
        
        return ans;
    }
    
    public Set<T> difference(Set<T> small){
        Set<T> ans = new Set<>();
        
        int k=0;
        for(T x: this.elements){
            while( k < small.elements.size() && small.elements.get(k).compareTo(x) < 0 ){
                k++;
            }
            
            if( (k < small.elements.size() && small.elements.get(k).compareTo(x) != 0)
                    || k == small.elements.size() )
                ans.elements.add(x);
        }
        return ans;
    }

    @Override
    public int compareTo(Set<T> other) {
        List<T> a = this.elements;
        List<T> b = other.elements;
        
        if( a.size() > b.size() ){
            List<T> tmp = b;
            b = a; a = tmp;
        }
        
        for(int i=0; i < Math.min(a.size(), b.size()); i++){
            int cmp = a.get(i).compareTo(b.get(i));
            
            if( cmp < 0 ) return -1;
            else if(cmp > 0 ) return 1;  
        }
        
        if( a.size() < b.size() ) return -1;
        else if( a.size() > b.size() ) return 1;
        
        return 0;
    }

    public List<T> getElements() {
        return elements;
    }

    public int size() {
       return elements.size();
    }

    public static Set<Integer> cannonical(int cantElem){
        Set<Integer> ans = new Set<>();
        
        for(int i=0; i < cantElem; i++)
            ans.getElements().add(i);
        
        return ans; 
    } 
    
}
