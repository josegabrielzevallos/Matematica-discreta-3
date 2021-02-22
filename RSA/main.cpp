#include <iostream>
using namespace std;
#include"rsa.h"
/*
int main()
{
    string cadena;
    rsa prueba(6);
    ifstream fe("mensaje.txt");
    int tam=strlen(fe);
    fe.getline(cadena,tam);
    int tam=strlen(cadena);
    string c;
    c = prueba.cifrar(cadena);

    cout << c << endl;
    c = prueba.decifrar(c);
    cout << c << endl;


    return 0;
}*/

/*int main()
{
int clave1, clave2;
    rsa prueba(24);
    string c;
    string cadena;
    ifstream fe("mensaje.txt");
    getline (fe,cadena);
    cout<<cadena<<endl;
    c = prueba.cifrar(cadena);
    cout << c << endl;
    c = prueba.decifrar(c);
    cout << c << endl;


    return 0;
}*/

int main()
{


    rsa prueba(24);
    //cout <<prueba.N <<endl;
    //cout <<prueba.e<<endl;
    string c;
    string v="41374033479785301605287739441220157691682106769245641546214211093563205980199340811992982541397617799213236713957726196013317199142389";
;
    //c = prueba.cifrar("hola123");
   // cout << c << endl;

    v = prueba.decifrar(v);
    cout << v << endl;


    return 0;
}
