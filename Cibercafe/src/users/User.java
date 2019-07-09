package users;

import java.io.Serializable;
import services.Service;
import java.util.ArrayList;
import java.util.List;

public abstract class User implements Serializable{
    protected String name, creditCard;
    protected int machine;
    protected List<Service> services;
    
    public User(String name, String creditCard, int machine){
        this.name = name;
        this.creditCard = creditCard;
        this.machine = machine;
        services = new ArrayList<>();
    }
    
    public abstract void addService(Service serv) throws NotPermitedServiceException;
    public abstract boolean isGolden();
    public abstract boolean isSilver();
    
    @Override
    public String toString(){
        return name; 
    }
    
    @Override
    public boolean equals(Object obj) {
        User usuario = (User)obj;
        return usuario.getCreditCard().equals(this.creditCard) 
            || usuario.getName().equals(this.name);
    }

    public void setMaq(int maq) {
        this.machine = maq;
    }
    
    public int getMaq(){ return machine; } 
    public List<Service> getServices(){ return services; }
    public String getName(){ return name; }
    public String getCreditCard(){ return creditCard; }
            
}
