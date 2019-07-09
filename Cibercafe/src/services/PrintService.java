package services;

import users.User;

/**
 *
 * @author teamSix
 *  
 */

public class PrintService extends Service{
    private boolean quality;
    private String text;
 
    public PrintService(int maquina, int hora, String text, boolean calidad){
        super(maquina, hora);
        
        this.text = text;
        this.quality = calidad; 
    }    

    @Override
    public double calcPrice(User user) {
        double price = 1.5  + (user.isGolden() ? 0 : (quality ? 2 : 1));
        
        double cantPalabras = 0;
        String[] splited = text.split(" ");
        
        for(int i=0; i < splited.length; i++)
            cantPalabras += !splited[i].equals("") && splited[i] != null ? 1 : 0;
        
        return cantPalabras * price;            
    }    

    @Override
    public String toString() {
        return "Impresión: tipo = " + (quality ? "láser" : "punto");
    }
}
