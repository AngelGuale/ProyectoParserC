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


void menuPrincipal();
int contarPalabras();
/*
 * prueba1.txt
 * 
 */
int main(int argc, char** argv) { 
    menuPrincipal();
    system("PAUSE");      
}

void menuPrincipal(){
    printf("\t\t\tBIENVENIDOS AL CONTADOR DE PALABRAS O-PE\n\n\n" ); 
    printf("Menu Principal\n\n");
    printf("[1]Contar palabras de un archivo\n");
    printf("[2]Contar palabras por caracteres\n");
    int op,i;
    printf("Escoja una opcion:  ");
    scanf("%d",&op);
    switch(op){
        case 1:           
            i = contarPalabras();
            printf("El total de palabras es: %d\n",i);
            break;
        case 2:
            printf("jajaja");
            break;
        default:
            printf("opcion invalida\n");
            break;
    } 
}

int contarPalabras(){ 
    FILE * fichero;
    char* nombreArchivo=malloc(sizeof(char*));   
    printf("Ingrese el nombre del archivo:");
    scanf("%s",nombreArchivo);
    fichero= fopen (nombreArchivo,"r");
    printf("%s\n", nombreArchivo);
    char c;    
    char buffer[500];  
    fseek(fichero, 0, SEEK_END); // seek to end of file
    int size = ftell(fichero); // get current file pointer
    fseek(fichero, 0, SEEK_SET); // seek back to beginning of file
    //printf("%d",size);
    int totalPalabras=0;
    int i=0;
    if (fichero==NULL){
        return 0;
    }else{        
        while(!feof(fichero)){
            fscanf(fichero,"%[^'\0']",buffer);       
            //printf("%s",buffer );
        }
            char* ptr=buffer;          
            while(ptr[i] && i<500){
                c= ptr[i];
                i++;
                if(isspace(c)){
                    totalPalabras++;
                }else{
                    printf("");
                }
           }
    }
    return totalPalabras;
}
