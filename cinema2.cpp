#include <bits/stdc++.h>
using namespace std;

class seating{
public: 
	int nrows;
	int ncols;
	vector<int> aisle_seats;
	
	seating();
	seating(int, int, vector <int> &);
};

seating::seating(){}
seating::seating(int rows, int cols, vector<int> &aisle){
	nrows = rows;
	ncols = cols;
	int n = aisle.size();
	for (int i=0; i<n; i++)
		aisle_seats.emplace_back(aisle[i]);
}
// global variable
unordered_map<string, seating> all_screens;

void add_screen(string line){
	istringstream ss(line);
	string name;
	int rows, cols;
	vector <int> aisle;
	int count = 0;
	while(!ss.eof()){
		string word0;
		ss >> word0;
		if(count == 1){
			name = word0;
		}
		else if (count == 2){
			rows = stoi(word0);
		}
		else if (count == 3){
			cols = stoi(word0);
		}
		else if (count > 3){
			aisle.emplace_back(stoi(word0));
		}
		count++;
	}
	cout << name << " inside add_screen " << rows << " rows, " << cols << " cols, number of aisle = " << aisle.size() <<endl;
	all_screens[name] = seating(rows, cols, aisle);
	return;
}

int main() {
	// your code goes here
	string line;
	while(getline(cin, line)){
		if(line.substr(0,10) == "add-screen"){
			add_screen(line);
			cout << "aaya";
		}
	}
	cout << all_screens["dangal"].nrows << endl;	
	cout << all_screens["dangal"].ncols << endl;	
	return 0;
}
