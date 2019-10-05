// Jose Carlos da Silva Cruz
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
#define PREC 0.00001
typedef long double ldb;
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=

typedef struct{

	ldb x;
	ldb y;
	ldb raio;

}circle;

typedef struct{

	ldb x;
	ldb y;

}vetor;

vector<circle> g; 
// printf("");

ldb escalar(vetor A, vetor B){

	ldb ans = ((A.x * B.x) + (A.y * B.y)); 
	return ans;
}

ldb modulo(vetor A){

	ldb ans = sqrt((A.x * A.x) + (A.y*A.y));
	return ans;
}

ldb toDegree(ldb rad){

	ldb ans = ((180.0*rad)/PI);
	return ans;
}

ldb toRad(ldb degree){

	while(degree < 0.0) degree+= 360.0;
	while(degree > 360.0) degree -= 360.0;
	if(degree > 180.0) degree = 360.0 - degree;
	ldb ans = ((degree*PI)/(180.0));
	return ans;
}

void leitor(){

	circle aux;
	//printf("Digite a coordenada do centro 1:\n");
	scanf("%Lf %Lf",&aux.x,&aux.y);
	printf("%Lf %Lf\n",aux.x,aux.y);
	//printf("Digite o raio 1:\n");
	scanf("%Lf",&aux.raio);
	g.push_back(aux);
	//printf("Digite a coordenada do centro 2:\n");
	scanf("%Lf %Lf",&aux.x,&aux.y);
	printf("%Lf %Lf\n",aux.x,aux.y);
	//printf("Digite o raio 2:\n");
	scanf("%Lf",&aux.raio);
	g.push_back(aux);
}

int solve(ldb *ax,ldb *ay,ldb *bx,ldb *by,int pivoA,int pivoB){

	ldb angle;
	vetor Padrao = {1,0};
	vetor atual;
	// mesmo centro
	if(g[pivoA].x == g[pivoB].x && g[pivoA].y == g[pivoB].y) return 0;

	atual.x = g[pivoB].x - g[pivoA].x;
	atual.y = g[pivoB].y - g[pivoA].y;

	angle = toDegree(acos(escalar(Padrao,atual)/(modulo(Padrao)*modulo(atual))));

	// /printf("angle is %0.Lf\n",angle);

	int signaly;
	int signalx;
	if(atual.y < Padrao.y){
		signaly = -1;
	}
	else signaly = 1;

	if(atual.x < Padrao.x){
		signalx = -1;
	}
	else{
		signalx = 1;
	}

	vetor A;
	vetor B;

	B.x = g[pivoB].x;
	B.y = g[pivoB].y;

	A.x = g[pivoA].x + (g[pivoA].raio * cos(toRad(angle)));
	A.y = g[pivoA].y + ((ldb)signaly * g[pivoA].raio * sin(toRad(angle)));

	vetor aux;
	aux.x = A.x - B.x;
	aux.y = A.y - B.y;

	if(modulo(aux) > (ldb)g[pivoB].raio) return 0;

	A.x = g[pivoA].x + (g[pivoA].raio * cos(toRad(angle+180.0)));
	A.y = g[pivoA].y + ((ldb)signaly * g[pivoA].raio * sin(toRad(angle+180.0)));
	aux.x = A.x - B.x;
	aux.y = A.y - B.y;
	if(modulo(aux) < (ldb)g[pivoB].raio) return 0;

	/// busca binaria em uma banda do circulo
	ldb s = angle;
	ldb e = angle - 180.0;
	ldb pivo;
	ldb step = 180.0;
	while(step > PREC){
		if(s < 0) s += 360.0;
		if(s > 360.0) s -= 360.0;
		if(e < 0) e += 360.0;
		if(e > 360.0) e -= 360.0;
		step /= two;
		pivo = s-step;
		if(pivo < 0) pivo += 360.0;
		if(pivo > 360.0) pivo -= 360.0;

		if(pivo < 180.0) signaly = one;
		else signaly = -1;
		if(pivo > 90 && pivo < 270) signalx = -1;
		else signalx = 1;

		A.x = g[pivoA].x + (g[pivoA].raio * cos(toRad(pivo)));
		A.y = g[pivoA].y + ((ldb)signaly * g[pivoA].raio * sin(toRad(pivo)));
		aux.x = A.x - B.x;
		aux.y = A.y - B.y;

		if(modulo(aux) > (ldb)g[pivoB].raio){
			e = pivo;
		}
		else{
			s = pivo;
		}
	}
	//printf("angle is %0.Lf\n",angle);
	//printf("angle is %0.Lf\n",pivo);
	//printf("%0.Lf == %0.Lf\n",cos(toRad(45)),cos(toRad(135)));

	*ax = A.x; *ay = A.y;
	//printf("angle is %0.Lf\n",angle);
	ldb diff = angle + fabs(360.0 - pivo);
	//printf("angle is %0.Lf\n",diff);
	while(diff > 360.0) diff-=360.0;
	pivo = angle + diff;
	while(pivo > 360.0) pivo -= 360.0;

	if(pivo < 180.0) signaly = one;
	else signaly = -1;
	if(pivo > 90 && pivo < 270) signalx = -1;
	else signalx = 1;
	//printf("angle is %0.Lf\n",pivo);

	A.x = g[pivoA].x + (g[pivoA].raio * cos(toRad(pivo)));
	A.y = g[pivoA].y + ((ldb)signaly * g[pivoA].raio * sin(toRad(pivo)));

	*bx = A.x; *by = A.y;

	return two;
}

int main(){

	ldb ax,ay,bx,by;
	leitor();
	int ret = solve(&ax,&ay,&bx,&by,0,1);

	if(ret == 0){
		printf("Nao ha interseccoes nas circunferencias dadas\n");
	}
	else if(ret == one){
		printf("Existe apenas um ponto que intercepta a circunferencia: ");
		printf("(%Lf, %Lf)\n",ax,ay);
	}
	else{
		printf("Os dois pontos sao: (%.3Lf,%.3Lf) e (%.3Lf,%.3Lf)\n",ax,ay,bx,by);
	}

	return 0;
}
