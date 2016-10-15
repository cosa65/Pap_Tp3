#include <iostream>
#include <vector>

using namespace std;

int main() {
	int c, a, q, act;
	cin >> c >> a >> q;
	vector<vector<int> > M(c + 1, vector<int>(a + 1, 0));
	for (int i = 1; i < c + 1; i++) {
		for (int j = 1; j < a + 1; j++) {
			cin >> act;
			M[i][j] = M[i][j-1] + M[i-1][j] - M[i-1][j-1] + act;
		}
	}

	int qc1, qa1, qc2, qa2;
	for (int i = 0; i < q; i++) {
		cin >> qc1 >> qa1 >> qc2 >> qa2;
		//sumar desde lo que tiene +1 hasta lo que aspira
		//las líneas de la matriz empiezan desde 1, parece a propósito
		cout << M[qc2][qa2] - M[qc2][qa1] - M[qc1][qa2] + M[qc1][qa1] << endl;
	}
}

