#include <iostream>
#include <fstream>
#include "Afin.h"

int main(){


   std::string mensajeOriginal;
    std::string mensajeCifrado;
    std::string mensajeDescifrado;
    string line;
    int clave1, clave2;

    Cripto Emisor;

    ifstream original("original.txt");
    while(getline(original,line)){
        mensajeOriginal+=line + "\n";}
    cout<<mensajeOriginal;
    //std::cout << "Ingrese un mensaje: ";
    //std::getline(std::cin, mensajeOriginal);

	mensajeCifrado = Emisor.cifrado(mensajeOriginal);

    std::cout << "Mensaje Cifrado: " << mensajeCifrado<<endl;
    std::cout << "\n";

    std::cout<<"Clave1: "<<Emisor.getClaveA()<<endl;
    mensajeDescifrado = Emisor.descifrado(mensajeCifrado);
    std::cout << "Mensaje Decifrado: " << mensajeDescifrado<<endl;
    //std::cout<<"Clave2: "<<Emisor.getClaveB()<<endl;


    //clave1 = Emisor.getClaveA();
    //clave2 = Emisor.getClaveB();
    //clave1=1;
    //std::cout<<"Clave1: "<< clave1<<endl;
    //clave2=43;
   // std::cout<<"Clave2: "<< clave2<<endl;

    //std::string a ("4TaZK_ZUaKYa.TGaIUSVUYOIOUTaJKaYOMTUYaIUJOLOIGJUYaKTa.TaYOYZKSGaJKaKYIXOZ.XGaW.KaLUXSGa.TGa.TOJGJaJKaYKTZOJU");
    //Cripto Receptor(clave1, clave2);

    //mensajeDescifrado = Receptor.descifrado(a);
    //std::cout << "Mensaje Descifrado: " << mensajeDescifrado<<endl;




	return 0;

}
