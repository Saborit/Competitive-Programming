package rst;

import algo.exception.BadParameterException;
import algo.roughset.ClassicRoughSet;
import algo.sets.Partition;
import algo.roughset.RoughSet;
import algo.sets.Set;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import visual.MainFrame;

/**
 *
 * @author zero
 */
public class RST {
    public RoughSet rs;
    
    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException, BadParameterException {        
        new MainFrame().setVisible(true);
//        RoughSet rs = new ClassicRoughSet("/home/zero/gripe1.arff", 3);
//        System.out.println(Arrays.toString(rs.getData().get(0).toDoubleArray()));
//        ArrayList<Integer> attr = new ArrayList<>();
//        attr.add(0);
//        attr.add(2);
//        
//        ArrayList<Integer> inst = new ArrayList<>();
//        inst.add(0);
//        inst.add(1);
//        inst.add(3);
//        
//        
//        System.out.println(rs.lowerAprox(new Set<>(attr), new Set<>(inst)).getElements());
//        System.out.println(rs.upperAprox(new Set<>(attr), new Set<>(inst)).getElements());
//        System.out.println(rs.boundary(new Set<>(attr), new Set<>(inst)).getElements());
//        
//        System.out.println(rs.presicionAprox(new Set<>(attr), new Set<>(inst)));
//        System.out.println(rs.calidadAprox(new Set<>(attr), new Set<>(inst)));
//        
//        System.out.println(rs.pertenencia(1, new Set<>(attr), new Set<>(inst)));
//        
//        List<Integer>[][] matrix = rs.matrizSeparacion();
//        
//        for(int i=0; i < matrix.length; i++){
//            for(int j=0; j < matrix[0].length; j++){
//                System.out.print(matrix[i][j].size() + " ");
//            }System.out.println();
//        }
        
//        Partition P = new Partition(9);
//        P.addRelation(1, 2);
//        P.addRelation(3, 2);
//        P.addRelation(4, 8);
//        P.addRelation(5, 7);
//        
//        List<Integer> l = new ArrayList<>();
//        l.add(1);
//        l.add(2);
//        l.add(3);
////        l.add(4);
////        l.add(8);
//        
//        System.out.println(Arrays.toString(P.isInIntersectionClass(l)));
////        System.out.println(Arrays.toString(P.isInSubsetClass(l)));
    
//    List<Integer> A = new ArrayList<>();
//    A.add(1);
//    A.add(3);
//    A.add(4);
//    A.add(6);
//    A.add(2);
//    A.add(5);
//    A.add(-4);
//    
//    List<Integer> B = new ArrayList<>();
//    B.add(1);
//    B.add(3);
//    B.add(4);
//    B.add(6);
//    B.add(2);
//    B.add(7);
//    B.add(0);
//    B.add(-4);
//    B.add(5);
    
//    System.out.println(new Set<Integer>(A).compareTo(new Set<>(B)));; 
    
//        System.out.println(new Set<>(B).difference(new Set<>(A)).getElements());
    
    }
    
}
