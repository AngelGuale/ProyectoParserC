/* 
 * File:   main.c
 * Author: xngel
 *
 * Created on 25 de junio de 2015, 05:23 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

  
    FILE * fichero;
    printf("%s", "Ingrese el nombre del archivo: ");
    char* nombreArchivo=malloc(sizeof(char*));
    char buffer[500];
    gets(nombreArchivo);
    fichero= fopen (nombreArchivo,"r");
    printf("%s", nombreArchivo);
    int totalPalabras=0;
    if (fichero==NULL){
        return 0;
    }else{
        while(fgets(buffer, 300, fichero)!=NULL){
        
            printf("%s",buffer );
           char* ptr=buffer;
           while(ptr!='\0'){
               if(ptr==" "){
                   printf("%s", "ESPACIO");
               }else{
                   printf("%s %s","Este es ptr: \n", ptr );
               }
               ptr++;
           }
        }
    
    
    }
    return (EXIT_SUCCESS);
}


