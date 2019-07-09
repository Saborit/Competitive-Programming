package algo.roughset.missing;

import algo.roughset.RoughSet;
import java.io.FileNotFoundException;
import java.io.IOException;
import weka.core.Instances;

/**
 *
 * @author Saborit
 */
public abstract class MissingRoughSet extends RoughSet{

    public MissingRoughSet(String file, int attrIndex) throws FileNotFoundException, IOException {
        super(file, attrIndex);
    }
    
    public MissingRoughSet(String file) throws FileNotFoundException, IOException {
        super(file);
    }

    public Instances noMissValues(){
        boolean flag; 
        Instances ans = new Instances(data.relationName(), getAttributes(), cantInst); //No se
        
        for(int i=0; i < cantInst; i++){
            flag = true;
            
            for(int j=0; j < cantAttr; j++){
                if( Double.isNaN(data.get(i).value(j)) ){
                    flag = false;
                    break;
                }
            }  
        }
        return ans;
    }

}
