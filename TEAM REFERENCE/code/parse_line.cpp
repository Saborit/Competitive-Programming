/*
 * Lee una linea y la divide en enteros, guardandolos en el arreglo A 
 * 
 * */

int A[5];
char S[100000];
char *in;

cin.getline(S, 99, '\n')
        
cant = 0;
for( in=strtok(S, " "); in; in=strtok(NULL, " ") )
    A[cant++] = atoi(in);
