#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

bool minuscula(char letter) {
	return (int)letter - 97 >= 0;
}

int pos(char letter) {
	if (minuscula(letter)){
		return (int)letter - 97;
	} else {
		return (int)letter - 65;
	}
}

class WeightedTrie {
public:

	WeightedTrie();
	void add_word(string new_word);
	int get_count_of(string word);
	int get_count_at_depth(string word, int depth);

private:

	struct Node {
		Node();
		void set_child(char letter);
		Node *get_child(char letter);
		bool defined(char letter);

		Node operator++(int);

		vector<Node *> childs;
		int weight;
	};

	Node *root;
};

WeightedTrie::Node::Node() {
	this->childs.resize(26);
	this->weight = 0;
}

void WeightedTrie::Node::set_child(char letter) {
	if(not defined(letter)) {
		Node *letter_node = new Node();
		childs[pos(letter)] = letter_node;
	}
	(*childs[pos(letter)])++;
}

WeightedTrie::Node* WeightedTrie::Node::get_child(char letter) {
	return childs[pos(letter)];
}

bool WeightedTrie::Node::defined(char letter) {
	return childs[pos(letter)];
}

WeightedTrie::Node WeightedTrie::Node::operator++(int) {
	(this->weight)++;
	return *this;
}

WeightedTrie::WeightedTrie() {
	this->root = new Node();
}


void WeightedTrie::add_word(string new_word) {
	Node *curr_node = root;
	for (string::iterator it = new_word.begin(); it != new_word.end(); it++) {
		curr_node->set_child(*it);
		curr_node = curr_node->get_child(*it);
	}
}

int WeightedTrie::get_count_of(string word) {
	return get_count_at_depth(word, word.size());
}

int WeightedTrie::get_count_at_depth(string word, int depth) {
	Node *curr_node = root;
	for (string::iterator it = word.begin(); it != word.end(); it++, depth--) {
		curr_node = curr_node->get_child(*it);
		if (not curr_node){
			cout << "[Error] No word in trie found that matches " << word << " at depth " << depth << endl;
			exit(0);
		}
		if (depth == 1) break;
	}
	return curr_node->weight;
}

int main() {

	int A;
	cin >> A;

	vector<string> alumnos(A);
	vector<int> prefijos(A);

	WeightedTrie diccionario_de_mails = WeightedTrie();

	for (int i = 0; i < A; i++) {
		cin >> alumnos[i];
		cin >> prefijos[i];
		
		diccionario_de_mails.add_word(alumnos[i]);
	}

	int max, act;
	max = 0;
	for (int i = 0; i < A; i++) {
		act = diccionario_de_mails.get_count_at_depth(alumnos[i], prefijos[i]);
		max = (act > max) * act + (act <= max) * max;
	}

	cout << max << endl;

}