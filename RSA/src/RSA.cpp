#include "rsa.h"

int mod(int a, int b)
{
    int mod;
    mod = a - b * (a/b);
    if (mod >= 0)
    {
        return mod;
    }
    mod = mod + b;
    return mod;
}

ZZ modulo(ZZ a, ZZ b)
{
    ZZ mod;
    mod = a - b * (a/b);
    if (mod >= int_ZZ(0))
    {
        return mod;
    }
    mod = mod + b;
    return mod;
}

ZZ mcd(ZZ a, ZZ b)
{
    ZZ r;
    while(b != int_ZZ(0))
    {
        r = modulo(a,b);
        a = b;
        b = r;
    }
    return a;
}

ZZ inversa(ZZ a, ZZ b)
{
    ZZ x, x1 = int_ZZ(0), x2 = int_ZZ(1), y, y1 = int_ZZ(1), y2 = int_ZZ(0), q, r;
    if(b == int_ZZ(0))
    {
        return int_ZZ(1);
    }
    else
    {
        while(b > int_ZZ(0))
        {
            q = a / b;
            r = modulo(a,b);
            x = x2 - (x1 * q);
            y = y2 - (y1 * q);
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        return x2;
    }
}

ZZ exponenciacion(ZZ a, ZZ b, ZZ n)
{
    ZZ r = int_ZZ(1);
    while(b > int_ZZ(0))
    {
        if( modulo(b,int_ZZ(2)) == 1)
        {
            r = modulo(r*a,n);
        }
        a = modulo(a*a,n);
        b = b / int_ZZ(2);
    }
    return r;
}/*

ZZ restochino(ZZ m, ZZ exp1, ZZ exp2, ZZ q1, ZZ q2)
{
    ZZ tmp1, tmp2;
    tmp1 = mod(exp_mod(m,exp1,n) * q * q1,n);
    tmp2 = mod(exp_mod(m,exp2,n) * p * q2,n);
    return mod(tmp1+tmp2,n);
}*/
ZZ int_ZZ(int n)
{
    ZZ z;
    conv(z,n);
    return z;
}

int ZZ_int(ZZ z)
{
    int n;
    conv(n,z);
    return n;
}

ZZ string_ZZ(string s)
{
    ZZ n(INIT_VAL, s.c_str());
    return n;
}

string ZZ_string(ZZ n)
{
    stringstream ss;
    ss<<n;
    string s = ss.str();
    return s;
}
bool Primalidad(int  a){
	if(a<2)return 0;
	if(a<4)return 1;
	if(mod(a,2)==0)return 0;
	int e=sqrt(a)+1;
	bool *arr;
	arr[e];
	for(int i=0;i<e;i++)arr[i]=1;
	for(int i=3;i<e;i+=2){
		if(arr[i]){
			if(mod(a,i)==0)return 0;
			for(int j=i*i;j<e;j+=i){
				arr[j]=0;
			}
		}
	}
	return 1;
}/*
ZZ GenerarN(ZZ bits){
    ZZ p;

    GenPrime(p,bits);
    GenPrime(q,bits);
    N = p * q;
    return  N;
}
ZZ GenerarE(ZZ bits){
    ZZ E=GenPrime(e,bits);
    return E;

}*/
rsa::rsa(int bits)
{
   // GenPrime(p,bits);
    //GenPrime(q,bits);
    //N = p * q;
    p=8411563;
q=11389529;
    phi = (p - int_ZZ(1)) * (q - int_ZZ(1));
   // GenPrime(e,bits);
    e=12892219;
N=95803740723827;

    //e=11537573;

    d = modulo(inversa(e,phi),phi);
    //N=145429066737589;
    cout<<e<<endl;
    cout << N << endl;
    cout << p << endl;
    cout << q << endl;
}

string rsa::convertir(string messag)
{
    string convertido;
    string tmp;
    string cero = "0";
    for(int i = 0; i < messag.size(); i++)
    {
        tmp = static_cast<ostringstream*>(&(ostringstream() << alfabeto.find(messag[i])))->str();
        if(tmp.size() == 1)
        {
            tmp = cero + tmp;
        }
        convertido += tmp;
    }
    return convertido;
}

string rsa::convertir2(string messag)
{
    string convertido;
    for(int i = 0; i < messag.size(); i+=2)
    {
        string tmp(messag,i,2);
        int b = atoi(tmp.c_str());
        convertido += alfabeto[b];
    }
    return convertido;
}

void rsa::rellenar(string &messag, int tam)
{
    int t = messag.size();
    while( mod(t,tam) != 0)
    {
        messag += "22";
        t = messag.size();
    }
}

string rsa::cifrar(string messag)
{
    string cifrado;
    ZZ cif;
    int tN = (ZZ_string(N)).size() - 1;
    messag = convertir(messag);
    rellenar(messag,tN);
    for(int i = 0; i < messag.size(); i+=tN)
    {
        string tmp(messag,i,tN);
        cif = string_ZZ(tmp);
        cif = exponenciacion(cif, e, N);
        tmp = ZZ_string(cif);
        if(tmp.size() != tN + 1)
        {
            string ceros(tN+1 - tmp.size(),'0');
            cifrado += ceros;
        }
        cifrado += tmp;
    }
    return cifrado;
}

string rsa::decifrar(string messag)
{
    ZZ dcif;
    string decifrado;
    int tN = (ZZ_string(N)).size();
    for(int i = 0; i < messag.size(); i+=tN)
    {
        string tmp(messag,i,tN);
        dcif = string_ZZ(tmp);
        dcif = exponenciacion(dcif, d, N);
        tmp = ZZ_string(dcif);
        if(tmp.size() != tN - 1)
        {
            string ceros(tN-1 - tmp.size(),'0');
            decifrado += ceros;
        }
        decifrado += tmp;
    }
    decifrado = convertir2(decifrado);

    //decifrado = exponenciacion(messag, d, N);
    return decifrado;
}
