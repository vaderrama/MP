/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   learn.cpp
 * Author: alvarosanpal
 *
 * Created on 20 de mayo de 2018, 12:41
 */

#include <cstdlib>
#include <iostream>
#include "ContadorBigramas.h"
#include "Idioma.h"
#include "Bigrama.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
    ContadorBigramas contador = new ContadorBigramas(valid);
    Idioma idioma;
    char* out;
    
    if (argc < 3){//No hay suficientes parámetros
    
        cerr << "Error en la llamada.\n learn <-c|-a> <fich1.txt> <fich2.txt> ..." <<endl;
        return 1;
    
    }
    
    if (argc == 3){ //Argumentos mínimos necesarios.
    
        if (argv[1] == "-c"){ //Crear un nuevo archivo de salida.
        
            contador.calcularFrecuenciasBigramas(argv[2]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            idioma.salvarAFichero(out); //No se crear el fichero salida.
        
        }else if (argv[1] == "-a"){ //Añadir a un archivo existente.
        
            contador.calcularFrecuenciasBigramas(argv[2]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            idioma.salvarAFichero(out);
        
        }else{ //Entrada no válida.
        
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;
        
        }
        
        if (argc == 4){ //Como comprobar si es el parametro -l , -f u otro archivo.
        
            
        
        }
    
    }
    return 0;
}

