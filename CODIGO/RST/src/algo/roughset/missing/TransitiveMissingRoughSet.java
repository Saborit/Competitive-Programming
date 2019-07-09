/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package algo.roughset.missing;

import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author Saborit
 */
public class TransitiveMissingRoughSet extends MissingRoughSet{

    public TransitiveMissingRoughSet(String file, int attrIndex) throws FileNotFoundException, IOException {
        super(file, attrIndex);
    }

    @Override
    protected boolean relation(double value1, double value2) {
        
    }
    
}
