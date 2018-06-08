/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ContadorBigramas.h"
#include "Idioma.h"
#include <cstring>
#include <iostream>
#include <fstream>

//Echale un ojo a todas las funciones del archivo, pero concretamente a:
//addBigrama() , ToIdioma() , FromIdioma () , CalculaFrecuenciaBigrama()



void ContadorBigramas::reservarMemoria(int n){
    
    liberarMemoria();
    
    _bigramas = new int*[n];
    
    for (int i = 0 ; i < n ; i++)
        _bigramas[i] = new int[n];

}

void ContadorBigramas::liberarMemoria(){

    if(_bigramas != NULL){
    
        for (int i = 0 ; i < getSize() ; i++)
            delete[] this->_bigramas[i];
        
        delete[] _bigramas;
    
    }
    
}

void ContadorBigramas::copiar(const ContadorBigramas& otro){

    liberarMemoria();
    _caracteresValidos = otro._caracteresValidos;
    reservarMemoria(otro.getSize());
    
    for (int i = 0 ; i <= getSize() ; i++){
    
        for (int j = 0 ; j <= getSize() ; j++){
        
            _bigramas[i][j] = otro._bigramas[i][j];
        
        }
    
    }
    
}

ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos){

    _caracteresValidos = caracteresValidos;
    _bigramas = NULL;
    reservarMemoria(_caracteresValidos.length());
    
    for (int i = 0 ; i < _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j < _caracteresValidos.length() ; j++){
        
         _bigramas [i][j] = 0;
        
        }
    
    }
    

}

ContadorBigramas::ContadorBigramas(const ContadorBigramas& orig){

    _caracteresValidos = orig._caracteresValidos;
    reservarMemoria(_caracteresValidos.length());
    
    for (int i = 0 ; i <= _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j <= _caracteresValidos.length() ; j++){
        
        _bigramas [i][j] = orig._bigramas[i][j];
        
        }
    
    }

}

ContadorBigramas::~ContadorBigramas(){

    liberarMemoria();

}

int ContadorBigramas::getSize() const{

    return _caracteresValidos.length();

}

int ContadorBigramas::getBigramasActivos() const{

    int contador = 0;
    for (int i = 0 ; i <= _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j <= _caracteresValidos.length() ; j++){
        
            if (_bigramas[i][j] > 0)
                contador++;
        
        }
    
    }
    return contador;
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia){
    // CREO QUE ESTA BIEN , PERO HAY QUE REVISARLO
    
    bool ok = false;
    //Variables para guardar las posiciones de la cadena en la matriz
    int pos1 = -1 , pos2 = -1;
    
    //Recorremos la cadena de caracteres para asignar las posiciones
    for (int i = 0 ; i < _caracteresValidos.length() ; i++){
    
        if(_caracteresValidos[i] == cadena[0])
            pos1 = i;
        if(_caracteresValidos[i] == cadena[1])
            pos2 = i;
    
    }
    
    if (pos1 == -1 || pos2 == -1){
        cout << "El bigrama proporcionado no es valido." << endl;
    }
    
    //Una vez obtenidas las posiciones, las buscamos en la matriz y modificamos
    //su valor en esa posicion
    for (int i = 0 ; i < _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j < _caracteresValidos.length() ; j++){
        
            if (i == pos1 && j == pos2){
                
                if (frecuencia == 0){
                    _bigramas[i][j]++;
                    ok = true;
                }else{
                    _bigramas[i][j] += frecuencia;
                    ok = true;
                
                }
            
            }
        
        }
    
    }
    
    return ok;

}

ContadorBigramas& ContadorBigramas::operator =(const ContadorBigramas& orig){

    copiar(orig);

}

ContadorBigramas& ContadorBigramas::operator +=(const ContadorBigramas& rhs){
    
    
    for (int i = 0 ; i < _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j < _caracteresValidos.length() ; j++){
        
            if (rhs._bigramas[i][j] > 0){
            
                _bigramas[i][j] = _bigramas[i][j] + rhs._bigramas[i][j];
            
            }
        
        }
    
    }

    return *this;

}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero){
    
//Al recibir el numero de bigramas del fichero, reservar meoria en _conjunto,
//y luego con un while ir rellenando los bigramas con el setbigrama y el
//setfrecuencia, comprobando que recorra el numero de bigramas y comprobando
//que no ha llegado a fin de fichero (cuando llega a fin de fichero, fichero es null
    
    bool ok = false;
    char cadena[2];//COMPROBAR VALIDEZ DE ESE *
    ifstream fentrada;
    fentrada.open(nfichero);
    
    if (nfichero) {

        fentrada >> cadena;//Preguntar si asi o metiendo los dos valores por separado
        fentrada >> cadena[1];
     
       
        
        while(nfichero != NULL){//Si no funciona con fentrada probar con nfichero ¨// ULTIMA ACTU ; CAMBIO FENTRADA POR NFICHERO 
            cout << cadena[0] << endl;
            addBigrama(cadena , 0);//NO SE COMO PASARLE EL PRIMER ARGUMENTO CORRECTAMENTE.
            fentrada >> cadena[0];
            fentrada >> cadena[1];
        
        }
        
        ok = true;
        
    }else{
        
        cerr<< "Error en la lectura del fichero\n";
        fentrada.close();
        
    }
    
    return ok;

}

Idioma ContadorBigramas::toIdioma() const{
    
    //Primero hay que crear un objeto de tipo Idioma, para lo que necesitamos
    //conocer el numero de  bigramas que hay, una vez teniendo el numero, y el
    //idioma (por defecto unknown) habrá que llamar al constructor de Idioma,
    //y despues ir pasandole los bigramas y las frecuencias.
    //Pero vaya, que todo esto me lo imagino porque "tengolacabezafritaynomeenterodena".
    
    int posicion = 0;
    int numeroBigramas = 0;
    char cadena[2];
    Bigrama bigrama;
    
    /*
    for (int i = 0 ; i < _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j < _caracteresValidos.length() ; j++){
        
            if (_bigramas[i][j] > 0){
            
                numeroBigramas++;
            
            }
        
        }
    
    }
    */
    
    numeroBigramas = getBigramasActivos();
    
    Idioma objIdioma(numeroBigramas);//Creo objeto idioma con numeroBigramas.
    
    objIdioma.setIdioma("unknown");
    
    for (int i = 0 ; i < _caracteresValidos.length() ; i++){
    
        for (int j = 0 ; j < _caracteresValidos.length() ; j++){
        
            if (_bigramas[i][j] > 0){//si la frecuencia es > 0:
                
                cadena[0] = _caracteresValidos[i];
                cadena[1] = _caracteresValidos[j];
                
                bigrama.setBigrama(cadena);//MISMO PROBLEMA CON EL PRIMER ARGUMENTOO.
                bigrama.setFrecuencia(_bigramas[i][j]);//meto el valor de la matriz.
                
                objIdioma.setPosicion(posicion , bigrama);
                posicion++;//Contador para meter los bigramas en orden.
            
            }
        
        }
    
    }
    
    return objIdioma;
    
}

void ContadorBigramas::fromIdioma(const Idioma& i){

    //Supongo que el mismo procedimiento que lo anterior pero viseversapremoh
    //Recorres el conjunto de bigramas del idioma, y con cada bigrama vas
    //haciendo un "addBigrama(bigrama , frecuencia)"
    
    bool ok;
    
    for (int j = 0 ; j < i.getSize() ; j++){
    
        ok = addBigrama(i.getPosicion(j).getBigrama() , i.getPosicion(j).getFrecuencia());//NO ENCUENTRA LA FUNCION?????????
        
        if (!ok){
        
            cerr << "Error al incluir el bigrama en la matriz." << endl;
        
        }
    
    }
    
    
    
    //Echale un ojo a este método porque me resulta rariiiiisssssssimo que
    //sea solo un for, aunque creo que asi basta.
    //Recorro con el for el _conjunto del objeto idioma, y en cada posicion
    //cojo el bigrama y llamo al addBigrama que comprueba su validez y lo mete en la matriz.
    

}
