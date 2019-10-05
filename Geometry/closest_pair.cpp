#include <bits/stdc++.h>
using namespace std;
#define PREC 0.00001

typedef long double ld;
typedef pair<ld,ld> lld;

vector<lld> Point;

ld module(lld A, lld B){

	ld ans,x,y;

	x = (B.first - A.first);
	y = (B.second - A.second);
	x *= x;
	y *= y;

	ans = sqrt(x + y);

	return ans;
}

lld inverso(lld A){

	swap(A.first,A.second);

	return A;
}

ld closestPair(){

	// recebe valores passados pelo vetor global (Point)

	set<lld> open;
	set<lld>::iterator itB,itE,it;

	// answer
	ld dist;
	// pointer
	int cont = 0;

	dist = module(Point[0],Point[1]);
	// salvar no set em relacao a coordenada Y
	lld aux;

	aux = inverso(Point[0]); // inverte coordenada x/y
	open.insert(aux);
	aux = inverso(Point[1]);
	open.insert(aux);

	for(int i=2;i<Point.size();i++){

		while(Point[cont].first+PREC < (Point[i].first - dist)){
			aux = inverso(Point[cont]);
			open.erase(aux);
			cont++;
		}

		// limite inferior
		aux.first = Point[i].second - dist - PREC;
		aux.second = -1e17;
		itB = open.lower_bound(aux);
		// limite superior
		aux.first = Point[i].second + dist + PREC;
		aux.second = 1e17;
		itE = open.upper_bound(aux);

		aux = inverso(Point[i]);
		// calcula uma nova distancia minima (se existir)
		for(it = itB; it != itE; ++it){
			dist = min(dist,module((*it),aux));
		}
		open.insert(aux);
	}

	open.clear();

	return dist;
}
