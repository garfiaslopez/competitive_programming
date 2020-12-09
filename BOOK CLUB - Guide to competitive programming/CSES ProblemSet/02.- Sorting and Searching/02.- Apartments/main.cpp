// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:       https://cses.fi/problemset/task/1084
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

// use binary search to search the closest in a X +- maxDiff range.
int binary_search(vector<int> &apartments, set<int> &taken, int maxDiff, int size) {
	
	int left = 0;
	int right = apartments.size();
	
	int last = -1;
	int minWindow = INT_MAX;
	
	while(left<=right) {
		int middle = left + (right - left) / 2;
		int val = apartments[middle];
		int diff = abs(val - size);
		
		if (val == size) { // exactly found size;
			if (taken.find(middle) == taken.end()) {
				taken.insert(middle);
				return middle;
			} else {
				return -1;
			}
		} else if (val < size) {
			if (diff <= maxDiff && diff < minWindow) {
				last = middle;
				minWindow = diff;
			}
			left = middle+1;
		} else if (val > size) {
			if (diff <= maxDiff && diff < minWindow) {
				last = middle;
				minWindow = diff;
			}
			right = middle-1;
		}
		
	}
	
	if (last != -1) {
		if (taken.find(last) == taken.end()) {
			taken.insert(last);
			return last;
		}
	}
	
	return -1;
}

int main() {
    int a,p,maxDiff;
    cin>>a>>p>>maxDiff;
	
    vector<int> apartments;
	vector<int> persons;
	set<int> apartmentTaken;
	
	for (int i=0; i<a; i++) {
		int tmp;
		cin>>tmp;
		apartments.push_back(tmp);
	}
	for (int i=0; i<p; i++) {
		int tmp;
		cin>>tmp;
		persons.push_back(tmp);
	}
	
	sort(apartments.begin(), apartments.end());
	
	int sellItApartments = 0;
	
	for (int i=0; i<persons.size(); i++) {
		if (search(apartments, apartmentTaken, maxDiff, persons[i]) != -1) {
			sellItApartments++;
		}
	}
	
	cout<<sellItApartments<<"\n";
	
    return (0);
}
