/* 
 * File:   main.c
 * Author: xngel
 *
 * Created on 25 de junio de 2015, 05:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

/*
 * prueba1.txt
 * 
 */
int main(int argc, char** argv) { 
    FILE * fichero;
    printf("%s", "Ingrese el nombre del archivo: ");
    char* nombreArchivo=malloc(sizeof(char*));
    char buffer[500];
    char c;
    gets(nombreArchivo);
    fichero= fopen (nombreArchivo,"r");
    printf("%s\n", nombreArchivo);
    fseek(fichero, 0, SEEK_END); // seek to end of file
    int size = ftell(fichero); // get current file pointer
    fseek(fichero, 0, SEEK_SET); // seek back to beginning of file
    printf("%d",size);
    int totalPalabras=0;
    int i=0;
    if (fichero==NULL){
        return 0;
    }else{        
        while(!feof(fichero)){
            fscanf(fichero,"%[^'\0']",buffer);       
            printf("%s",buffer );
        }
            char* ptr=buffer;          
            while(ptr[i] && i<500){
                c= ptr[i];
                i++;
                if(isspace(c)){
                    printf("%s", "ESPACIO");
                    totalPalabras++;
                }else{
                    printf("\nEste es ptr:\n%s\n", ptr );
                }

           }
         
    }
    printf("%d",totalPalabras);
    system("PAUSE");      
}
