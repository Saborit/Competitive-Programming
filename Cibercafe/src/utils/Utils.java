/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package utils;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Point;
import java.util.List;

/**
 *
 * @author luis
 */
public class Utils {
    public static boolean areAllDigits(String str){
        if(str == null || str.equals(""))
            return false;
        for(int i=0; i < str.length(); i++)
            if( '9' < str.charAt(i) || str.charAt(i) < '0' )
                return false;
        return true;
    } 
    
    public static boolean isNonNegativeInteger(String str){
        try {
            int i = Integer.parseInt(str);
            return i >= 0;
        }
        catch(NumberFormatException nfe) {
            return false; 
        }        
    } 

    public static String[] getArrayOfStrings(List list) {
        String[] newList = new String[list.size()];
         
        for(int i=0; i < list.size(); i++)
            newList[i] = list.get(i).toString();
        
        return newList;
    }
    
    public static Object[] getArrayOfObjects(List list) {
        Object[] newList = new Object[list.size()];
         
        for(int i=0; i < list.size(); i++)
            newList[i] = list.get(i);
        
        return newList;
    }
    
    public static Point innerPosition(Component comp, int xplus, int yplus){
        Point pt = comp.getLocation();
        return new Point(pt.x + xplus, pt.y + yplus);
    }
    
    public static Point innerPosition(Component comp){
        return innerPosition(comp, 50, 50);
    }
    
    public static Point innerPosition(Component parent, Component child){
        Dimension pLoc = parent.getSize();
        Dimension chLoc = child.getSize();
        
        int x = (pLoc.width - chLoc.width)/2; 
        int y = (pLoc.height - chLoc.height)/2;
        
        return innerPosition(parent, x, y);
    } 

    public static boolean isByte(String text) {
        try {
            Byte.parseByte(text);
            return true;
        }
        catch(NumberFormatException nfe) {
            return false; 
        }
    }
    
}
