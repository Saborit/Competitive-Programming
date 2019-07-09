package algo;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import weka.core.Instance;
import weka.core.Instances;

/**
 *
 * @author zero
 */
public class RoughSet {
    protected final double EPS = 1e-9;
    
    protected int cantAttr, cantInst;
    protected Instances data;
    
    public RoughSet(String file, int attrIndex) throws FileNotFoundException, IOException {
        BufferedReader bReader = new BufferedReader(new FileReader(file));
        data = new Instances(bReader);
        
        data.setClassIndex(attrIndex);
        
        cantAttr = data.numAttributes();
        cantInst = data.numInstances();
    }
    
    /**
     * Calcula el conjunto de elementos diferentes en dos instancias.
     * @param inst1 Instancia del sistema de decision 
     * @param inst2 Instancia del sistema de decision
     * @return
     * @throws ParameterException 
     */
    public List<Integer> conjSeparacion(int inst1, int inst2) throws ParameterException{
        if( !(0<=inst1 && inst1 < cantInst && 0<=inst2 && inst2 < cantInst) )
            throw new ParameterException();
        
        List<Integer> ans = new LinkedList<>();
        Instance a = data.get(inst1);
        Instance b = data.get(inst2);
        
        for(int i=0; i < cantAttr; i++)
            if( Math.abs(a.value(i) - b.value(i)) > EPS )
                ans.add(i);
            
        return ans;
    }
    
    /**
     * Calcula la Matriz de Separacion
     * @return 
     */
    public List<Integer>[][] matrizSeparacion(){
        List<Integer>[][] ans = (List<Integer>[][])new List[cantInst][cantInst];
        
        for(int i=0; i < cantInst; i++){
            for(int j=0; j < cantInst; j++){
                if( i<=j ){
                    try{
                        ans[i][j] = conjSeparacion(i, j);
                    }
                    catch(ParameterException pe){}
                }
                else{
                    ans[i][j] = ans[j][i];
                }
            }
        }
        
        return ans;
    } 
    
//    protected relacion
}
