#include <iostream>
#include <math.h>

int *eucEx(int a, int b){

	int q, r, s, s1, s2, t, t1, t2;
	s1 = t2 = 1;
	s2 = t1 = 0;
	int *resultado;

	while (b > 0){

		q = a / b;

		r = a - (q * b);
		a = b;
		b = r;

		s = s1 - (q * s2);
		s1 = s2;
		s2 = s;

		t = t1 - (q * t2);
		t1 = t2;
		t2 = t;

	}

	resultado = new int[3];
	resultado[0] = a;
	resultado[1] = s1;
	resultado[2] = t1;

	return resultado;

}


int mod(int a, int n){

	int q = a / n;
	int r = a - q * n;
	if(r < 0) { return r + n; }
	return r;

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
}
int mcd(int a, int b){

	int r = mod(a, b);
	while(r != 0){
		a = b;
		b = r;
		r = mod(a, b);
	}
	return b;

}



int inversa(int a, int b){

	int r, q, s, s1, s2;

	if(b == 0){
        s2 = 1;
        return s2;
	}
	else{
		s1=0;
		s2=1;
		while(b>0){
			q = a/b;
			r = a - (q * b);
			s = s2 - (q * s1);
			a = b;
			b = r;
			s2 = s1;
			s1 = s;
		}
		return s2;
	}
}

int exponenciacion(int a, int b, int n)
{
    int r = 1;
    while(b > 0)
    {
        if( mod(b,2) == 1)
        {
            r = mod(r*a,n);
        }
        a = mod(a*a,n);
        b = b / 2;
    }
    return r;
}
