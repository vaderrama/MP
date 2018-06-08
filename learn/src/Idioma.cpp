/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Idioma.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

void Idioma::reservarMemoria(int n){

    if(_conjunto != NULL)
    delete [] _conjunto;
    
    _conjunto = new Bigrama [n];

}

void Idioma::liberarMemoria(){

    if(_conjunto != NULL)
    delete [] _conjunto;

}

void Idioma::copiar(const Idioma& otro){

    liberarMemoria();
    _nBigramas = otro._nBigramas;
    reservarMemoria(otro._nBigramas);
    
    for (int i = 0 ; i < _nBigramas ; i++){
    
        _conjunto[i] = otro._conjunto[i];
    
    }

}

Idioma::Idioma(){
    
    _idioma = "unknown";
    _nBigramas = 0;
    
}

Idioma::Idioma(int nbg){
    
    _idioma = "unknown";
    liberarMemoria();
    _nBigramas = nbg;
    reservarMemoria(nbg);

}

Idioma::Idioma(const Idioma& orig){
    
    copiar(orig);

}

Idioma::~Idioma(){

    liberarMemoria();

}

Idioma& Idioma::operator =(const Idioma& orig){

    if(&orig != this){
    
        delete [] this ->_conjunto;
        this ->_nBigramas = orig._nBigramas;
        this ->_idioma = orig._idioma;
        this ->_conjunto = new Bigrama [this ->_nBigramas + 1];
        
        for(int i = 0 ; i <= _nBigramas ; i++)
            this ->_conjunto[i] = orig._conjunto[i];
    
    }
    
    return *this;

}

std::string Idioma::getIdioma() const{

    return _idioma;

}

void Idioma::setIdioma(const std::string& id){

    _idioma = id;

}

Bigrama Idioma::getPosicion(int p) const{

    return _conjunto[p];

}

void Idioma::setPosicion(int p, const Bigrama& bg){

    _conjunto[p] = bg;

}

inline int Idioma::findBigrama(const std::string& bg) const{

    int pos = 0;
    
    for (int i = 0 ; i < _nBigramas ; ++i){
	
        if(getPosicion(i).getBigrama() == bg){
            
            pos = i;
            
	}
        
    }

	return pos;

}

double Idioma::distancia(const Idioma& otro) const{

  

}
void Idioma::ordenar(){

    for (int i = 0 ; i < _nBigramas ; i++) {
        
        int max = i;
        
        for (int j = i+1 ; j < _nBigramas ; j++)
            
            if (_conjunto[j].getFrecuencia() > _conjunto[max].getFrecuencia())
                max = j;
        
        if (max != i) {
            Bigrama aux = _conjunto[max];
            _conjunto[max] = _conjunto[i];
            _conjunto[i] = aux;
        }
    }

}

bool Idioma::salvarAFichero(const char* fichero) const{

    ofstream f;
    
    f.open(fichero , ios::out | ios::app);
    
    bool ok = false;
    
    if(f){
    
        f << _idioma << endl;
        f << _nBigramas << endl;
        
        for (int i = 0; i<_nBigramas; i++) {
            
            f <<_conjunto[i];
            f << endl;
            
        }
         
        
        ok = true;
        f.close();
    
    }else{
    
        cerr << "Imposible crear el fichero." << endl;
        ok = false;
    }
    
    return ok;
}

bool Idioma::cargarDeFichero(const char* fichero){

    ifstream f;
    int contador=0;
    bool ok = false;
    f.open(fichero);
    
    if(f){
        
        
        f >> _idioma;
        f >> _nBigramas;
        while ( fichero != NULL ){
            f >> _conjunto[contador];
            contador++;
        }

        f.close();
        ok = true;
    
    }else{
    
        cerr << "Imposible abrir el fichero de datos." << endl;
        ok = false;
    
    }
    
    return ok;

}

std::ostream& operator<<(std::ostream& os , const Idioma& i){
    
int contador = 0;
    
    if ( i._idioma != "unknown"){
        os << i._idioma<<endl;
        
        if(i._conjunto != NULL){
            while ( i._conjunto[contador].getBigrama() != NULL ){ // CAMBIO GETBIGRAMA() 
                os << i._conjunto[contador].getBigrama();
                os << i._conjunto[contador].getFrecuencia();
                
                contador++;
            }
            os << endl;
        }
        
    }
    
    return os;
}


std::istream& operator>>(std::istream& is , Idioma& i){
    
   
    Bigrama* conj;
    int contador=0;
    
    is >> i._idioma;
    is >> i._nBigramas;
    
    do{
        is >> i._conjunto[contador];
        contador++;
    }while ( i._conjunto[contador].getBigrama() != NULL);
    
    
   
  
    
}
