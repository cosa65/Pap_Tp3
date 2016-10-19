#include <iostream>

using namespace std;

class SegmentTree{
public:
	
	SegmentTree();

private:

	struct Node{
	public:

		Node();

	private:

	};

	Node *root;

};

SegmentTree::Node::Node(){}

SegmentTree::SegmentTree(){}

int main() {

	int D, R;

	cin >> D >> R;
	vector<int> fun_at_day(D);

	for (int i = 0; i < D; i++) {
		cin >> fun_at_day[i];
	}

	

}