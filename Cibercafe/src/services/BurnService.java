package services;

import users.User;

/**
 *
 * @author teamSix
 */

//Solo para asociados

public class BurnService extends Service{
    private byte speed;
    private long mbytes;
    
    public BurnService(int maquina, int hora, byte vel, long mbs){
        super(maquina, hora);
        
        this.speed = vel;
        this.mbytes = mbs;
    }    
    
    @Override
    public double calcPrice(User user) {
        double price  = mbytes / 700.0;
        
        if( user.isGolden() || user.isSilver() )
                return price;
        
        return price + speed / 16.0;
    }
    
    @Override
    public String toString() {
        return "Quemado: vel = " + speed + " / " + mbytes + "mb";
    }

}
