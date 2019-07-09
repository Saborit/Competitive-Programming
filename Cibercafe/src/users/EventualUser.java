package users;

import java.io.Serializable;
import services.BurnService;
import services.Service;

public class EventualUser extends User implements Serializable{

    public EventualUser(String nombre, String creditCard, int maquina) {
        super(nombre, creditCard, maquina);
    }

    @Override
    public void addService(Service serv) throws NotPermitedServiceException{
        if( serv instanceof BurnService)
            throw new NotPermitedServiceException();
        else 
            services.add(serv);
    }
    
    @Override
    public boolean isGolden() {
        return false;
    }

    @Override
    public boolean isSilver() {
        return false;
    }
    
}
