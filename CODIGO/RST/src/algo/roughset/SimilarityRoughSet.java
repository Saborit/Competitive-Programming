package algo.roughset;

import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author Saborit
 */
public class SimilarityRoughSet extends RoughSet{
    private double delta;
            
    public SimilarityRoughSet(String file, int attrIndex) throws FileNotFoundException, IOException {
        super(file, attrIndex);
        
        delta = 1e-9;
    }
    
    public SimilarityRoughSet(String file, double delta) throws FileNotFoundException, IOException {
        super(file);
        
        this.delta = delta;
    }
    
    public SimilarityRoughSet(String file, int attrIndex, double delta) throws FileNotFoundException, IOException {
        super(file, attrIndex);
        
        this.delta = delta;
    }

    @Override
    protected boolean relation(double value1, double value2) {
        return Math.abs(value1 - value2) > delta;
    }
    
    public double getDelta() {
        return delta;
    }

    public void setDelta(double delta) {
        this.delta = delta;
    }

}
