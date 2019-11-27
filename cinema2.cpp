#include <bits/stdc++.h>
using namespace std;

class seating{
public:
	int nrows;
	int ncols;
	vector<int> aisle_seats;
	bool** occupied;
	// define constructors
	seating();
	seating(int, int, vector<int> &);
};

seating::seating(){}
seating::seating(int rows, int cols, vector<int> &aisle){
	nrows = rows;
	ncols = cols;
	occupied = (bool**)malloc(nrows * sizeof(bool*));
	for(int i=0; i<nrows; i++){
		occupied[i] = (bool *)calloc(ncols, sizeof(bool));
	}
	int n = aisle.size();
	for(int i=0; i<n; i++){
		aisle_seats.emplace_back(aisle[i]);
	}
}

class screen{
public:
	string name;
	seating seat;
	screen();
	screen(string, int, int, vector<int> &);
};

screen::screen(){}
screen::screen(string movie, int rows, int cols, vector<int> &aisle){
	name = movie;
	seat = seating(rows, cols, aisle);
}

void add_screen(string line, vector<screen> &all){
	// cout << line << endl;
	int count = 0;
	string movie_name;
	int rows, cols;
	vector<int> aisle;
	istringstream ss(line);
	while(!ss.eof()){
		string word0;
		ss >> word0;
		
		if (count == 1)
			movie_name = word0;
		if (count == 2)
			rows = stoi(word0);
		if (count == 3)
			cols = stoi(word0);
		if (count > 3)
			aisle.emplace_back(stoi(word0));
		count++;
	}
	all.emplace_back(screen(movie_name, rows, cols, aisle));
}


bool reserve_screen(string line, vector<screen> &all){
	string screen_name;
	int row_no;
	vector<int> booking;
	istringstream ss(line);
	count = 0;
	while(!ss.eof()){
		string word0;
		ss >> word0;
		if (count == 1){
			screen_name = word0;
		}
		else if (count == 2){
			row_no = stoi(word0);
		}
		else if(count > 2){
			if()
			booking.emplace_back(stoi(word0));
		}
	}
}

int main() {
	// your code goes here
	string line;
	vector<screen> all;
	while(getline(cin, line)){
		// cout << line;
		if (line.substr(0,10) == "add-screen"){
			add_screen(line, all);
		}
		else if (line.substr(0,14) == "reserve-screen"){
			reserve_screen(line, all);
		}
	}
	// vector<screen> all;
	// all.emplace_back(screen("Dangal", 10, 12));
	int total = all.size();
	for(int i=0; i<total; i++){
		cout << all[i].name << endl << (all[i].seat.aisle_seats).size() << endl;
	}
	return 0;
}
