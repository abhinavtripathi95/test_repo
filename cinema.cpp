#include <bits/stdc++.h>
using namespace std;

class seating{
public:
	int nrows;
	int ncols;
	bool **occupied;
	seating();
	seating(int, int);
};

seating::seating(){}
seating::seating(int rows, int cols){
	nrows = rows;
	ncols = cols;
	occupied = (bool**)malloc(nrows* sizeof(bool*));
	for (int i=0; i<nrows; i++){
		occupied[i] = (bool *)calloc(ncols, sizeof(bool));
	}
	
}

class screen{
public:
	string name;
	seating seat;
	screen(string movie, int nrows, int ncols){
		name = movie;
		seat = seating(nrows, ncols);
	}
	addScreen(string )
};

screen reservation(string line){
	
}


int main() {
	// your code goes here
	string line;
	while(getline(cin, line)){
		cout << line  << endl;
		istringstream ss(line);
		string word;
		ss >> word;
		if (word == "reserve-seats"){
			
		}
	}
	vector<screen> all_screens;
	all_screens.emplace_back(screen("dangal", 10, 50));
	cout << all_screens[0].name << endl << all_screens[0].seat.occupied[1][1] ;
	bool t1 = true;
	cout << t1;
	return 0;
}
