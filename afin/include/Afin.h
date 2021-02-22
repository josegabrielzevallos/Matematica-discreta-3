#include <iostream>
using namespace std;
class Cripto{

public:

    Cripto(){
        claveA = GenerarA(length_alfabeto);
        claveB = GenerarB(2*length_alfabeto);
    }

    Cripto(int A, int B){
        claveA = A;
        claveB = B;

    }

    int random(int n);
    int GenerarA(int n);
    int GenerarB(int n);

    int getClaveA() { return claveA; }
    int getClaveB() { return claveB; }

    std::string cifrado(std::string textoPlano);
    std::string descifrado(std::string textoCifrado);

    //std::string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
    //int length_alfabeto = alfabeto.length();
     int length_alfabeto = 256;

private:
    int claveA;
    int claveB;

};
