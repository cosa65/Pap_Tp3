#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //max
#include <cmath>

using namespace std;

int val_min;

pair<int, int> maxs2( pair <int,int> izq, pair <int,int> der)  //dado dos nodos (dos rangos) unifica uno nuevo apartir de estos 
{   
    vector<int> valores;

	valores.push_back(izq.first);
	valores.push_back(izq.second);
	
	valores.push_back(der.first);
	valores.push_back(der.second);

	// sort using the default operator<
    sort(valores.begin(), valores.end());
  	//entre los 4 valores me quedo con los dos maximos
  	pair <int, int> res(valores[2], valores[3]);
    return res;
}      	

pair <int, int> maximos_dias(vector <pair <int,int> > &maxs_cada_rango, int k, int l, int r, int i, int j)
{
	if (i <= l && l< r && r <= j)//si estoy dentro del rango devuelvo el valor 
		return maxs_cada_rango[k - 1];

	if (r <= i || l >= j)//estoy fuera del rango no debo recorrer esta rama
	{
		pair<int,int> res(val_min,val_min);
		return res;
	}
	//delego la soluciòn a mis hijos
	return maxs2(maximos_dias(maxs_cada_rango, 2*k, l, (l+r)/2, i, j),maximos_dias(maxs_cada_rango, 2*k + 1, (l+r)/2, r, i, j)); 	
}

////////////////////////////////
int main()
{
	int D, R;
	val_min = -100;
    cin >> D >> R;

    int ex = 0;
    for (ex = 0; pow(2,ex) < D; ++ex){}//completo por si no tengo 2^j nodos (no tengo totalmente completo el arbol)

    int D2 = pow(2,ex);	//nuevo numero de nodos (dias) con D2 <= 2D
	
	vector <int> diversionDia(D2); //almaceno la diversion de cada dia
		
	for (int i = 0; i < D; ++i)//los dias originales
	{
		int e_i;
		cin >> e_i;
		diversionDia[i] = e_i;
	}

	for (int i = D; i < diversionDia.size(); ++i)//para los nuevos nodos (dias) agregados, los inicializo con un valor minimo 
		diversionDia[i] = val_min;

	vector <pair <int,int> > rangos(R);//completo con los rangos parametros

	for (int i = 0; i < R; ++i)
	{
		int p_i, u_i;
		cin >> p_i >> u_i;
		pair<int, int> elem (p_i, u_i);
		rangos[i] = elem; 
	}

	vector <pair  <int,int> > maxs_cada_rango(2*D2 - 1);//arreglo que va a emular el arbol. Cada nodo hace referencia a un intervalo
	// y almacenara en èl, el valor de diversiòn de los dos eventos mas divertidos dentro de dicho rango

	for (int i = maxs_cada_rango.size() -1 ; i >= 0; --i)
	{
		if(i >= D2 -1)//en el arreglo las posiciones [D2 -1; 2*D2 - 1) son las hojas, los valores que vienen como parametros
		{
			maxs_cada_rango[i].first = diversionDia[i - (D2-1)];
			maxs_cada_rango[i].second = val_min;
		}
		else //en el arreglo las posiciones [0; 2*D2 - 1) son nodos internos deben ser calculados apartir de su hijo izquierdo y derecho
		{
			pair<int, int> izq = maxs_cada_rango[2*i + 1];  //2*(i +1) - 1
			pair<int, int> der = maxs_cada_rango[2*i + 2];  //2*(i +1) 	
			maxs_cada_rango[i] = maxs2(izq, der);
		}	
	}

	for (int i = 0; i < rangos.size(); ++i)
	{
		int suma = 0;
		pair <int, int> res = maximos_dias(maxs_cada_rango, 1, 0, D2, rangos[i].first, rangos[i].second);
		if (res.first != val_min)
			suma += res.first;
		if (res.second != val_min)
			suma += res.second;
		cout << suma << endl;
	}

	return 0;
}