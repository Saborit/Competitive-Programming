/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package utils;

import java.io.File;
import javax.swing.filechooser.FileFilter;

/**
 *
 * @author luis
 */
public class CCFFileFilter extends FileFilter{
    @Override
    public boolean accept(File file) {
        return file.isDirectory() || file.getName().endsWith(".ccf");
    }

    @Override
    public String getDescription() {
        return "Archivos CCF";
    }    
}
