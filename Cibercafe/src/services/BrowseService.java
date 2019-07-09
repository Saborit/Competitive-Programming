package services;

import users.User;
import users.AsociatedUser;

/**
 *   Variables:
 *   kbytes -> kbytes descargados
   finalHour -> hora de finalizacion 
 */
public class BrowseService extends Service{
    private long kbytes;
    private int finalHour;
    
    public BrowseService(int maquina, int kb, int ihora, int fhora){
        super(maquina, ihora);
        
        this.finalHour = fhora;
        this.kbytes = kb;
    }   

    @Override
    public double calcPrice(User user) {
        double price = finalHour - initHour;
        
        if( user instanceof AsociatedUser )
            return price + 2 * kbytes;
        else
            return 1.5 * price + 2 * kbytes;
    }

    @Override
    public String toString() {
        return "Navegación: " + kbytes + " kbytes / " + "hfinal = " + finalHour;
    }
}
