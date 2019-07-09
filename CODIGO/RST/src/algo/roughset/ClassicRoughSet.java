package algo.roughset;

import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author  zero
 */
public class ClassicRoughSet extends RoughSet{
    protected final double EPS = 1e-9;
    
    public ClassicRoughSet(String file, int attrIndex) throws FileNotFoundException, IOException {
        super(file, attrIndex);
    }
    
    public ClassicRoughSet(String file) throws FileNotFoundException, IOException {
        super(file);
    }
    
    @Override
    protected boolean relation(double value1, double value2) {
        return Math.abs(value1 - value2) > EPS;
    }
    
}
