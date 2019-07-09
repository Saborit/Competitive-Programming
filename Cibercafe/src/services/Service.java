package services;

import java.io.Serializable;
import users.User;

/**
 *   Variables:
   machine -> maquina que solicita el servicio
   initHour -> hora a la que inicia el servicio
 * 
 */

public abstract class Service implements Serializable{
    protected int machine;
    protected int initHour;

    public Service(int maquina, int hora){
        this.machine = maquina;
        this.initHour = hora;
    }
    
    public abstract double calcPrice(User solicitante);    
}
