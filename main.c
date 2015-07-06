/* 
 * File:   main.c
 * Author: xngel, roberto
 *
 * Created on 25 de junio de 2015, 05:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


void menuPrincipal();
int contarPalabras(char* textoArchivo, int numMayorQue);
void cargarArchivo(char* nombreArchivo, char* textoArchivo);
void voltearTexto(char* textoArchivo, char* textoModificado);
void sinEspacios(char* textoArchivo, char* textoModificado);
void grabarArchivo(char* nombreArchivo, char* textoArchivo);

/*
* prueba1.txt
*
*/
int main(int argc, char** argv) {
	menuPrincipal();
	system("PAUSE");
}

void menuPrincipal(){
	char* nombreArchivo = malloc(sizeof(char*));
	char* textoArchivo[500];
	char* textoModificado[500];
	textoArchivo[0] = "&";
	printf("\t\tPROCESADOR DE TEXTO: PRIMER PROYECTO\n\n");
	printf("Autores:\n");
	printf("Angel Guale\n");
	printf("Ray Montiel\n");
	printf("Roberto Yoncon\n\n");
	printf("Menu Principal\n");
	while (textoArchivo[0] == "&"){
		printf("Ingrese el nombre del archivo:");
		scanf("%s", nombreArchivo);
		cargarArchivo(nombreArchivo, textoArchivo);
	}
	int op = 0, i, numMayorQue;
	char str[100];
	while (op >= 0){
		printf("[1]Contar palabras de un archivo\n");
		printf("[2]Contar palabras por caracteres\n");
		printf("[3]Voltear el texto\n");
		printf("[4]Quitar espacios\n");
		printf("[5]Salir\n");
		printf("Escoja una opcion:  ");
		scanf("%s", str);
		op = atoi(str);
		
		switch (op){
		case 1:
			i = contarPalabras(textoArchivo, 0);
			printf("El total de palabras es: %d\n", i);
			break;
		case 2:
			printf("Ingrese el numero minimo de caracteres que no desea contar: ");
			scanf("%d", &numMayorQue);
			i = contarPalabras(textoArchivo, numMayorQue);
			printf("El total de palabras mayores a %d caracteres es: %d\n", numMayorQue, i);
			break;
		case 3:
			printf("Escribiendo desde el final hasta el inicio.\n");
			voltearTexto(textoArchivo, textoModificado);
			printf("El texto volteado es:\n %s\n", textoModificado);
			break;
		case 4:
			printf("Escribiendo desde el final hasta el inicio.\n");
			sinEspacios(textoArchivo, textoModificado);
			printf("El texto volteado es:\n %s\n", textoModificado);
			break;
		case 5:
			printf("Saliendo...");
			op = -1;
			break;
		default:
			printf("opcion invalida\n");
			break;
		}
	}
}

int contarPalabras(char* textoArchivo, int numMayorQue){
	int totalPalabras = 0;
	int i = 0;
	int numLetra = 0;
	while(textoArchivo[i]!='\0'){
		if (textoArchivo[i] == ' ' && numLetra > 0){
			if (numLetra > numMayorQue)
				totalPalabras++;
			numLetra = 0;
		}
		else
			numLetra++;
		i++;
	}
	return totalPalabras;
}

void cargarArchivo(char* nombreArchivo, char* textoArchivo){
	FILE* fichero;
	fichero = fopen(nombreArchivo, "r");
	char c;
	if (fichero == NULL){
		printf("Archivo no encontrado. Intente de nuevo.\n");
		textoArchivo[0] = "&";
	}
	else{
		while (!feof(fichero)){
			fscanf(fichero, "%[^'\0']", textoArchivo);
		}
		fclose(fichero);
	}
}

void voltearTexto(char* textoArchivo, char* textoModificado){
	int i = 0;
	for (i = 0; i< strlen(textoArchivo); i++){
		textoModificado[strlen(textoArchivo) - i - 1] = textoArchivo[i];
	}
	textoModificado[strlen(textoArchivo)] = '\0';
	grabarArchivo("alreves.txt", textoModificado);

}

void sinEspacios(char* textoArchivo, char* textoModificado){
	int i = 0, j = 0;
	while (textoArchivo[i] != '\0'){
		if (textoArchivo[i] != ' '){
			textoModificado[j] = textoArchivo[i];
			j++;
		}
		i++;
	}
	textoModificado[j] = '\0';
	grabarArchivo("sinespacios.txt", textoModificado);
}

void grabarArchivo(char* nombreArchivo, char* textoArchivo){
	FILE* fichero;
	fichero = fopen(nombreArchivo, "wb");

	if (fichero == NULL){
		printf("Archivo no encontrado.\n");
		fclose(fichero);
		exit(1);
	}
	else{
		fprintf(fichero, "%s", textoArchivo);
		fclose(fichero);
	}
}