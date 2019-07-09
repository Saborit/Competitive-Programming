/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package utils;

import java.util.ArrayList;
import java.util.List;
import users.User;

/**
 *
 * @author luis
 */
 
public class ListFilter  {
    public static Object[] filter(List list, String pattern){
        ArrayList ret = new ArrayList();
        pattern = pattern.toLowerCase();
        User tmp;
        
        for(Object obj: list){
            tmp = (User)obj;
            if( tmp.getName().toLowerCase().contains(pattern) || 
                tmp.getCreditCard().contains(pattern) )
                ret.add(obj);
        }
        Object[] ans = new Object[ret.size()];
        
        for(int i=0; i < ret.size(); i++)
            ans[i] = ret.get(i);
        return ans;
    }
}
