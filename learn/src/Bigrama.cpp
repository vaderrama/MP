/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Bigrama.h"
#include <cstring>
#include <fstream>

using namespace std;


Bigrama::Bigrama(){
	_frecuencia = 0;
}

const char* Bigrama::getBigrama() const{

    return _bigrama;

}

int Bigrama::getFrecuencia() const{

    return _frecuencia;

}



void Bigrama::setBigrama(const char cadena[]){

    if (strlen(cadena) <= 2)
        strcpy(_bigrama, cadena);
    
}

void Bigrama::setFrecuencia(int frec){

    _frecuencia = frec;

}

bool Bigrama::operator >(const Bigrama& b){
    bool ok = false;
    int aux;
    aux = strcmp ( _bigrama,b.getBigrama());
    
    if ( aux > 0 ) {
        ok = true;
    }else
        ok = false;
    
    return ok ;
  

}
/*
friend std::ostream& operator<<(std::ostream& os , const Bigrama& bigrama){

    if ( bigrama._bigrama!=NULL){
        os << bigrama._bigrama<<endl;
        
        if(bigrama._frecuencia> 0)
            os << bigrama._frecuencia<<endl;
        
    }


return os;
}

friend std::istream& operator>>(std::istream& is , Bigrama& bigrama){

    char aux[3];
    float frec;
    is >> aux;
    is >> frec;
    _bigrama = aux;;
    _frecuencia = frec;
    
}
*/
std::ostream& operator<<(std::ostream& os , const Bigrama& bigrama){

    if ( bigrama._bigrama!=NULL){
    os << bigrama._bigrama<<endl;
    
        if(bigrama._frecuencia > 0)
            os << bigrama._frecuencia<<endl;
    
    }

    
    return os;
}

std::istream& operator>>(std::istream &is, Bigrama &bigrama){
    
    char aux[3];
    float frec;
    is >> aux ;
    is >> frec;
    
    for(int i = 0 ; i<4 ; i++){
        bigrama._bigrama[i] = aux[i];   
    }
    
    bigrama._frecuencia=frec;
    

}
