package users;

import java.io.Serializable;
import services.Service;

/*

Categorias:
 - bronceada -> 'b'
 - plateada  -> 'p'
 - dorada    -> 'd'

*/

public class AsociatedUser extends User implements Serializable{
    private int years;
    private char category;
    
    public AsociatedUser(String nombre, String creditCard, char category, int maq, int years) {
        super(nombre, creditCard, maq);
        
        this.years = years;
        this.category = category;
    }
    
    @Override
    public boolean isGolden() {
        return category == 'd';
    }

    @Override
    public boolean isSilver() {
        return category == 'p';
    }

    @Override
    public void addService(Service serv) throws NotPermitedServiceException{
        services.add(serv);
    }
    
    public char getCategory(){ return category; }
    public int getYears() { return years; }
    
    public void setCategory(char cat){ category = cat; }   
}
