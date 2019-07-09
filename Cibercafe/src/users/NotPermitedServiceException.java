/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package users;

/**
 *
 * @author luis
 */
public class NotPermitedServiceException extends Exception {

    @Override
    public String getMessage() {
        return "El servicio no puede ser prestado a este usuario";
    }
        
}
