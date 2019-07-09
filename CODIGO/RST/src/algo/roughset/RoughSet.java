package algo.roughset;

import algo.exception.BadParameterException;
import algo.sets.Partition;
import algo.sets.Set;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import weka.core.Attribute;
import weka.core.Instance;
import weka.core.Instances;

/**
 *
 * @author zero
 */
public abstract class RoughSet {
    protected int cantAttr, cantInst;
    protected Instances data;
    
    protected abstract boolean relation(double value1, double value2);
    
    public RoughSet(String file) throws FileNotFoundException, IOException {
        BufferedReader bReader = new BufferedReader(new FileReader(file));
        data = new Instances(bReader);
        
        data.setClassIndex(data.numAttributes() - 1);
        
        cantAttr = data.numAttributes();
        cantInst = data.numInstances();
    }
    
    
    public RoughSet(String file, int attrIndex) throws FileNotFoundException, IOException {
        BufferedReader bReader = new BufferedReader(new FileReader(file));
        data = new Instances(bReader);
        
        data.setClassIndex(attrIndex);
        
        cantAttr = data.numAttributes();
        cantInst = data.numInstances();
    }
    
    public ArrayList<Attribute> getAttributes(){
        ArrayList<Attribute> ans = new ArrayList<>();
        
        for(int i=0; i < cantAttr; i++)
            ans.add(data.attribute(i));
        
        return ans;
    }
    
    public Instances instancesSubset(Set<Integer> set){
        Instances ans = new Instances(data.relationName(), getAttributes(), cantInst); //No se
        
        for(Integer i: set.getElements())
            ans.add(data.get(i));
        
        return ans;
    }
    
    /**
     * Calcula el conjunto de elementos diferentes en dos instancias.
     * @param inst1 Instancia del sistema de decision 
     * @param inst2 Instancia del sistema de decision
     * @return
     * @throws BadParameterException 
     */
    public Set<Integer> conjSeparacion(int inst1, int inst2) throws BadParameterException{
        if( !(0<=inst1 && inst1 < cantInst && 0<=inst2 && inst2 < cantInst) )
            throw new BadParameterException();
        
        List<Integer> ans = new ArrayList<>();
        Instance a = data.get(inst1);
        Instance b = data.get(inst2);
        
        for(int i=0; i < cantAttr; i++)
            if( relation(a.value(i), b.value(i)) )
                ans.add(i);
            
        return new Set<>(ans);
    }
    
    /**
     * Calcula la Matriz de Separacion
     * @return 
     */
    public Set<Integer>[][] matrizSeparacion(){
        Set<Integer>[][] ans = (Set<Integer>[][])new Set[cantInst][cantInst];
        
        for(int i=0; i < cantInst; i++) for(int j=0; j < cantInst; j++){
            if( i<=j ){
                try{
                    ans[i][j] = conjSeparacion(i, j);
                }
                catch(BadParameterException pe){}
            }
            else ans[i][j] = ans[j][i];
        }
        
        return ans;
    } 
    
    private Partition createEquivalenceClasses(Set<Integer> conjAtrr){
        Partition partition = new Partition(cantInst);
        
        for(int i=0; i < cantInst; i++) for(int j=0; j < i; j++){
            boolean flag = true;
            
            for(Integer attr: conjAtrr.getElements())
                if( relation(data.get(i).value(attr), data.get(j).value(attr)) )
                    flag = false;
            
            if( flag )
                try{
                    partition.addRelation(i, j);
                }catch(BadParameterException bpe){} 
        }
        return partition;
    }    
    
    /**
     * Calcula la aproximacion inferior de un subconjunto de instancias dentro del
     * conjunto aproximado
     * @param conjAtrr Subconjunto de atributos a tener en cuenta 
     * @param conjInst Sunconjunto de Instancias 
     * @return Conjunto de Indices del subconjunto de instancias que representa la 
     * aproximacion
     * @throws algo.exception.BadParameterException
     */
    public Set<Integer> lowerAprox(Set<Integer> conjAtrr, Set<Integer> conjInst) throws BadParameterException{
        Set<Integer> ans = new Set<>();
        Partition partition = createEquivalenceClasses(conjAtrr);
        
        boolean[] subsetClass = partition.isInSubsetClass(conjInst.getElements());
        
        for(int i=0; i < cantInst; i++) if( subsetClass[i] )
            ans.getElements().add(i);
        
        return ans;
    }
    
    /**
     * Calcula la aproximacion superior de un subconjunto de instancias dentro del
     * conjunto aproximado
     * @param conjAtrr Subconjunto de atributos a tener en cuenta 
     * @param conjInst Sunconjunto de Instancias 
     * @return Conjunto de Indices del subconjunto de instancias que representa la 
     * aproximacion
     * @throws algo.exception.BadParameterException
     */
    public Set<Integer> upperAprox(Set<Integer> conjAtrr, Set<Integer> conjInst) throws BadParameterException{
        Set<Integer> ans = new Set<>();
        Partition partition = createEquivalenceClasses(conjAtrr);
        
        boolean[] interClass = partition.isInIntersectionClass(conjInst.getElements());
        
        for(int i=0; i < cantInst; i++) if( interClass[i] )
            ans.getElements().add(i);
        
        return ans;
    }
    
    /**
     * Calcula la region frontera de un subconjunto de instancias dentro del
     * conjunto aproximado
     * @param conjAttr Subconjunto de atributos a tener en cuenta 
     * @param conjInst Sunconjunto de Instancias 
     * @return Conjunto de Indices del subconjunto de instancias que representa la 
     * aproximacion
     * @throws algo.exception.BadParameterException
     */
    public Set<Integer> boundary(Set<Integer> conjAttr, Set<Integer> conjInst) throws BadParameterException{
        return upperAprox(conjAttr, conjInst).difference(lowerAprox(conjAttr, conjInst));
    } 
    
    public boolean isRough(Set<Integer> conjAttr, Set<Integer> conjInst) throws BadParameterException{
        return boundary(conjAttr, conjInst).size() == 0;
    }
    
    public double presicionAprox(Set<Integer> conjAttr, Set<Integer> conjInst) throws BadParameterException{
        return (double)(lowerAprox(conjAttr, conjInst).size())/
                upperAprox(conjAttr, conjInst).size();
    }
    
    public double calidadAprox(Set<Integer> conjAttr, Set<Integer> conjInst) throws BadParameterException{
        return (double)(lowerAprox(conjAttr, conjInst).size())/conjInst.size();
    }
    
    public double pertenencia(int inst, Set<Integer> conjAttr, Set<Integer> conjInst) throws BadParameterException{
        Partition partition = createEquivalenceClasses(conjAttr);
        
        return (double)(partition.intersectClassWith(inst, conjInst).size())/
                partition.sizeOfClass(inst);
    }

    public Instances getData() {
        return data;
    }
    
    
}
