package cibercafe;

/**
 *
 * @author teamSix
 */
public class ExistingUserException extends Exception{
    public String getMessage(){
        return "El usuario ya existe";     
    } 
}
