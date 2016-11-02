#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tablaBordes(string t){
	vector<int> res(t.size()+1);
	res[0]=-1;
	int j;
	for(int i=1; i<t.size(); i++){
		j = res[i-1];
		while(j>=0 && t[i-1]!=t[j]) j=res[j];
		res[i] = j+1;
	}
	return res;
}

int main(){
	string nombre;
	string apodo;
	cin >> nombre >> apodo;
	vector<int> bordes = tablaBordes(apodo);
	int i=0, j=0;
	while(i <= nombre.size() - apodo.size()){
		if(j == apodo.size()){
			cout << 'S'<< endl;
			return 0;
		} else if(apodo[j] != nombre[i+j]){
			i = i + max(1, j-bordes[j]); //i++;
			j = max(0,bordes[j]); //j=0;
		} else {
			j++;
		}
	}
	cout << 'N' << endl;
	return 0;
}
