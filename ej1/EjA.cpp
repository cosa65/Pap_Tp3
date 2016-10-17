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
	string t;
	string s;
	cin >> t >> s;
	vector<int> bordes = tablaBordes(t);
	int i=0, j=0;
	while(i <= t.size() - s.size()){
		if(j == s.size()){
			cout << 'S'<< endl;
			return 0;
		} else if(s[j] != t[i+j]){
			i = i + max(1, j-bordes[j]); //i++;
			j = max(0,bordes[j]); //j=0;
		} else {
			j++;
		}
	}
	cout << 'N' << endl;
	return 0;
}
