#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

std::vector<Interval> heapsort(std::vector<Interval>& vec) {

	int n = vec.size();
	std::vector<int> res(n);

	std::make_heap(vec.begin(), vec.end());
	for (int i = n; i != 0; i--) {
		res[i-1] = vec.front();
		std::pop_heap(vec.begin(), vec.end());
		vec.pop_back();
	}
	return res;
}

struct Interval{

	Interval(int fst, int lst);
	int end_of_intersection_with(Interval other);
	bool operator<=(Interval i1, Interval i2);

	int fst, lst;
};

Interval::Interval(int fst, int lst) {
	this->fst = fst;
	this->lst = lst;
}

int Interval::end_of_intersection(Interval first, Interval next) {
	return (first.lst > next.fst)*first.last + (first.lst <= next.fst)*next.fst;
}

bool Interval::operator<=(Interval& i1, Interval& i2) {
	return i1.lst <= i2.lst;
}

struct EssentialInterval {

	EssentialInterval(Interval &real_int, int essential_fst);
	int fst();
	int lst();

	Interval real_int;
	int essential_fst;
};

EssentialInterval::EssentialInterval(Interval &real_int, int essential_fst) {
	this->real_int = real_int;
	this->essential_fst = essential_fst;
}

void EssentialInterval::compare_and_set(Interval first, Interval next) { 
	
}

int EssentialInterval::fst() {
	return essential_fst;
}

int EssentialInterval::lst() {
	return real_int.lst;
}

class SegmentTree{
public:
	
	SegmentTree(vector<Interval> intervals);

private:



	Node *root;

};


SegmentTree(vector<Interval> intervals);

std::vector<EssentialInterval> get_essential_intervals(std::vector<Interval>& vec) {
	int size = vec.size();
	heapsort(vec);

	vector<int> res(size);
	int essential_fst;

	for(int i = 1; i < size-1; i++) {
		essential_fst = res[i].end_of_intersection_with(res[i-1]);
		res[i] = EssentialInterval(vec[i], essential_fst);
	}
	return res;
}

int main() {

	int D, R;
	vector<int> fun_at_day(D);
	vector<Interval> intervals(R);

	cin >> D >> R;
	for (int i = 0; i < D; i++) {
		cin >> fun_at_day[i];
	}

	int fst, lst;
	for (int i = 0; i < R; i++) {
		cin >> fst >> lst;
		intervals[i] = Interval(fst, lst);
	}

	vector<>
	stree = SegmentTree(intervals);

}