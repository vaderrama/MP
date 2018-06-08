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
#include <fstream>
#include <cstring>
#include "ContadorBigramas.h"
#include "Idioma.h"
#include "Bigrama.h"

using namespace std;


int main(int argc, char** argv) {

    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
    ContadorBigramas contador =  ContadorBigramas(valid);
    Idioma idioma;
    
    if (argc < 3){//No hay suficientes parámetros
    
        cerr << "Error en la llamada.\n learn <-c|-a> <fich1.txt> <fich2.txt> ..." <<endl;
        return 1;
    
    }
    
    if (argc == 3){
    
        if (argv[1] == "-c"){ //Crear un nuevo archivo de salida.
        
            contador.calcularFrecuenciasBigramas(argv[2]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
              
            idioma.salvarAFichero("out.bgr" );
            
        }else if (argv[1] == "-a"){ //Añadir a un archivo existente.
            
            contador.calcularFrecuenciasBigramas(argv[2]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();

            idioma.salvarAFichero("out.bgr" );
        
        }else{ //Entrada no válida.
        
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;
        
        }
        
    }//Fin 3 argc
        
    if (argc == 4){ //Hay dos ficheros, sino sería "argc = 5" minimo.
        
        if (argv[1] == "-c"){
                
            contador.calcularFrecuenciasBigramas(argv[2]);
            
            contador.calcularFrecuenciasBigramas(argv[3]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            idioma.salvarAFichero("out.bgr" );
                
                
        }else if (argv[1] == "-a"){
                
            contador.calcularFrecuenciasBigramas(argv[2]);
            
            contador.calcularFrecuenciasBigramas(argv[3]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            idioma.salvarAFichero("out.bgr" );
                
                
        }else{
             
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;  
        
        }
    
    }//Fin 4 argc
    
    if (argc == 5){
    
        if (argv[1] == "-c"){
            
            contador.calcularFrecuenciasBigramas(argv[4]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
                
                idioma.salvarAFichero("out.bgr");
            
            }
            
            if (argv[2] == "-f"){
            
                idioma.salvarAFichero(argv[3]);
            
            }
            
        }else if (argv[1] == "-a"){
            
            contador.calcularFrecuenciasBigramas(argv[4]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
                
                idioma.salvarAFichero("out.bgr");
            
            }
            
            if (argv[2] == "-f"){
            
                idioma.salvarAFichero(argv[3]);
            
            }
            
        }else{
             
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;  
        
        }
    
    }//Fin 5 argc
    
    if (argc == 6){ //Hay dos ficheros, sino sería "argc = 7" minimo.
    
        if (argv[1] == "-c"){
            
            contador.calcularFrecuenciasBigramas(argv[4]);
            
            contador.calcularFrecuenciasBigramas(argv[5]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
                
                idioma.salvarAFichero("out.bgr");
            
            }
            
            if (argv[2] == "-f"){
            
                idioma.salvarAFichero(argv[3]);
            
            }
            
        }else if (argv[1] == "-a"){
            
            contador.calcularFrecuenciasBigramas(argv[4]);
            
            contador.calcularFrecuenciasBigramas(argv[5]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
                
                idioma.salvarAFichero("out.bgr");
            
            }
            
            if (argv[2] == "-f"){
            
                idioma.salvarAFichero(argv[3]);
            
            }
            
        }else{
             
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;  
        
        }
    
    }//Fin 6 argc
    
    if (argc == 7){
    
        if (strcmp(argv[1],"-c") == 0 ){
            
            contador.calcularFrecuenciasBigramas(argv[6]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
            
            }
            
            if (argv[4] == "-f"){
            
                idioma.salvarAFichero(argv[5]);
            
            }
            
        }else if (strcmp(argv[1],"-l") == 0){
            
            contador.calcularFrecuenciasBigramas(argv[6]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
            
            }
            
            if (argv[4] == "-f"){
            
                idioma.salvarAFichero(argv[5]);
            
            }
            
        }else{
             
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;  
        
        }
    
    }//Fin 7 argc
    
    if (argc == 8){
    
        if (argv[1] == "-c"){
            
            contador.calcularFrecuenciasBigramas(argv[6]);
            
            contador.calcularFrecuenciasBigramas(argv[7]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
            
            }
            
            if (argv[4] == "-f"){
            
                idioma.salvarAFichero(argv[5]);
            
            }
            
        }else if (argv[1] == "-a"){
            
            contador.calcularFrecuenciasBigramas(argv[6]);
            
            contador.calcularFrecuenciasBigramas(argv[7]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
            
            }
            
            if (argv[4] == "-f"){
            
                idioma.salvarAFichero(argv[5]);
            
            }
            
        }else{
             
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;  
        
        }
    
    }//Fin 8 argc
    
    if (argc == 9){
    
        if (argv[1] == "-c"){
            
            contador.calcularFrecuenciasBigramas(argv[6]);
            
            contador.calcularFrecuenciasBigramas(argv[7]);
            
            contador.calcularFrecuenciasBigramas(argv[8]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
            
            }
            
            if (argv[4] == "-f"){
            
                idioma.salvarAFichero(argv[5]);
            
            }
            
        }else if (argv[1] == "-a"){
            
            contador.calcularFrecuenciasBigramas(argv[6]);
            
            contador.calcularFrecuenciasBigramas(argv[7]);
            
            contador.calcularFrecuenciasBigramas(argv[8]);
            
            idioma = contador.toIdioma();
            
            idioma.ordenar();
            
            if (argv[2] == "-l"){
            
                idioma.setIdioma(argv[3]);
            
            }
            
            if (argv[4] == "-f"){
            
                idioma.salvarAFichero(argv[5]);
            
            }
            
        }else{
             
            cerr << "No se ha proporcionado un primer parametro valido (-c|-a)." << endl;
            return 1;  
        
        }
    
    }
    
    return 0;
    
}//FIN DEL MAIN

