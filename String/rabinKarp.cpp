#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define K 256 // todos os caracteres possiveis
const ll Q = 1e9 + 7; // mod

string subs;
string text;

int search(){

	int M = subs.size();
	int N = text.size();

	ll f = 0;
	ll t = 0;
	ll h = 1; 

	for(int i=0;i<M;i++){
		f = (f*K + ((int) subs[i]))%Q; // calculando o valor da chave da substring que irei procurar
		t = (t*K + ((int) text[i]))%Q; // calculandoa chave da substring atual do texto
	}

	// calculando h^(m-1)
	for(int i=0;i<M-1;i++){
		h = (h*K)%Q;
	}

	int ret = -1; // retorno
	for(int i=0;i<=N-M;i++){
		// achei uma chave parecida
		if(f == t){
			// sao as mesmas substrings ?
			bool ok = true;
			for(int j=0;j<M;j++){
				if(subs[j] != text[i+j]){
					ok = false;
					break;
				}
			}
			// encontrei uma substring
			if(ok){
				ret = i;
				break;
			}
		}

		// calcula um novo valor para a chave
		t = (t - (text[i] * h)%Q);
		if(t < 0) t += Q;
		t = (t*K + text[i+M])%Q;
	}

	return ret; // complexidade O(N + M) 
}



int main(){

	int ret;
	cin >> text;
	cin >> subs;

	ret  = search();

	if(ret == -1) cout << "substring nao existe na string" << endl;
	else cout << "substring encontrada na posicao " << ret << endl;
}
