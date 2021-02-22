#include <iostream>

int mod(int a, int n){

	int q = a / n;
	int r = a - q * n;
	if(r < 0) { return r + n; }
	return r;

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
