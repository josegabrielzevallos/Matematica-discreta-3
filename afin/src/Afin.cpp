 #include <iostream>
#include<cstdlib>
#include<ctime>
#include "Afin.h"
#include "funciones.h"

int Cripto::random(int n){

    srand(time(NULL));
    int r = mod(rand(), n-1) + 1;
    return r;

}

int Cripto::GenerarA(int n){

    int a = random(n);

    while(mcd(a,n) != 1)
        a = random(n);

    return a;

}

int Cripto::GenerarB(int n){

    int b = random(n);

    return b;

}

std::string Cripto::cifrado(std::string textoPlano){

    std::string textoCifrado;
    int length_textoPlano = textoPlano.length();
    int posicion;

    for(int i = 0; i < length_textoPlano; i++){

       // posicion = mod((alfabeto.find(textoPlano[i]) * mod(claveA, length_alfabeto)) + mod(claveB, length_alfabeto), length_alfabeto);
        //textoCifrado += alfabeto[posicion];
        posicion=mod(claveA*textoPlano[i],length_alfabeto);
        textoCifrado += posicion;
    }

    return textoCifrado;

}

std::string Cripto::descifrado(std::string textoCifrado){

    std::string textoDescifrado;
    int length_textoCifrado = textoCifrado.length();
    int posicion;
    int invclaveA = inversa(mod(claveA, length_alfabeto), length_alfabeto);

    for(int i = 0; i < length_textoCifrado; i++){

       // posicion = mod((alfabeto.find(textoCifrado[i]) - mod(claveB, length_alfabeto)) * invclaveA, length_alfabeto);
       // textoDescifrado += alfabeto[posicion];
         posicion=mod(textoCifrado[i]*invclaveA,length_alfabeto);
         textoDescifrado += posicion;
    }

    return textoDescifrado;

}
