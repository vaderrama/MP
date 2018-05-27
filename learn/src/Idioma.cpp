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

Idioma::reservarMemoria(int n){

    if(_conjunto != NULL)
    delete [] _conjunto;
    
    _conjunto = new Bigrama [n];

}

Idioma::liberarMemoria(){

    if(_conjunto != NULL)
    delete [] _conjunto;

}

Idioma::copiar(const Idioma& otro){

// FALTA 

}

Idioma::Idioma(){

    _nBigramas = 0;
    
}

Idioma::Idioma(int nbg){

    liberarMemoria();
    _nBigramas = nbg;
    reservarMemoria(nbg);

}

Idioma::Idioma(const Idioma& orig){

    copiar(orig);

}

Idioma::~Idioma(){

    if(_conjunto != NULL){
    
        delete [] _conjunto;
    
    }

}

Idioma::operator =(const Idioma& orig){

    if(&orig != this){
    
        delete [] this ->_conjunto;
        this ->_nBigramas = orig._nBigramas;
        this ->_idioma = orig._idioma;
        this ->_conjunto = new Bigrama* [this ->_nBigramas + 1];
        
        for(int i = 0 ; i <= _nBigramas ; i++)
            this ->_conjunto[i] = orig._conjunto[i];
    
    }
    
    return *this;

}

Idioma::getIdioma() const{

    return _idioma;

}

Idioma::setIdioma(const std::string& id){

    _idioma = id;

}

Idioma::getPosicion(int p) const{

    return _conjunto[p];

}

Idioma::setPosicion(int p, const Bigrama& bg){

    _conjunto[p] = bg;

}

Idioma::findBigrama(const std::string& bg) const{

    int pos = 0;
    
    for (int i = 0 ; i < _nBigramas ; ++i){
	
        if(getPosicion(i) == bg){
            
            pos = i;
            
	}
        
    }

	return pos;

}

Idioma::distancia(const Idioma& otro) const{

    // NO ENTIENDO QUE POLLAS HAY QUE HACER AQUI
    

}

Idioma::ordenar(){

    // ALVARO TIENE QUE COGER EL ORDENAR DEL OTRO PROYECTO

}

Idioma::salvarAFichero(const char* fichero) const{

    ofstream f;
    bool ok = false;
    f.open(fichero);
    
    
    if(f){
    
        f << _idioma << endl;
        f << _nBigramas << endl;
        /*
        for (int i = 0; i<_nBigramas; i++) {
            f<<_conjunto[i];
            
        }
         */
        f << _conjunto << endl;
        ok = true;
        f.close();
    
    }else{
    
        cerr << "Imposible crear el fichero." << endl;
        ok = false;
    }
    
    return ok;
}

Idioma::cargarDeFichero(const char* fichero){

    ifstream f;
    bool ok = false;
    f.open(fichero);
    
    if(f){
        
        
        fichero >> _idioma;
        fichero >> _nBigramas;
        fichero >> _conjunto;

        f.close();
        ok = true;
    
    }else{
    
        cerr << "Imposible abrir el fichero de datos." << endl;
        ok = false;
    
    }
    
    return ok;

}

friend std::ostream& operator<<(std::ostream& os , const Idioma& i){

    int contador = 0;
    
    if ( _idioma!=NULL){
        os << _idioma<<endl;
        
        if(_conjunto[0] != NULL){
            while ( _conjunto[contador] != NULL ){
                os << _conjunto[contador];
                contador++;
            }
            os << endl;
        }
        
    }
    
    return os;
}
    

}

friend std::istream& operator>>(std::istream& os , Idioma& i){
    
    string idio;
    int nbigr;
    Bigrama* conj;
    
    is >> idio;
    is >> nbigr;
    is >> conj;
    
    
    _idioma = idio;
    _nBigramas = nbigr;
    _conjunto = conj;
    


}



std::ostream& operator<<(std::ostream& os , const Idioma& i){

    int contador = 0;
    
    if ( i.getIdioma()!=NULL){
        os << i.getIdioma()<<endl;
        
        if(i.getPosicion(0) != NULL){
            while ( i.getPosicion(contador) != NULL ){
                os << i.getPosicion(contador);
                contador++;
            }
            os << endl;
    }
        
}

return os;
}


std::istream& operator>>(std::istream& is , Idioma& i){
    
    string idio;
    int nbigr;
    Bigrama* conj;
    
    is >> idio;
    is >> nbigr;
    is >> conj;
    
    
    i.setIdioma(idio);
    // setNBigramas ??
    i.setPosicion(nbigr,conj);
    

}
