#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <string>
using namespace std;

int main() {
	/*
	double Dmin;
	double Dmax;
	double Arlimit;
	*/
	double Dmin = 10;
	double Dmax = 12;
	double x;
	double y;
	double buff;
	double Arlimit = pow((Dmax - Dmin), 2) / 2;
	int i = 1;
	string strbuff;
	list< pair <double, double> > dotlist;
	bool save1, save2;

	//cout << Arlimit;
	//while(fin){
	ifstream fin("u.txt");
	ofstream fon("uout.txt");
	//while(true)
	//{
	for (int i = 0; i < 7; i++) {
		fin >> strbuff;
		cout << strbuff << "\t";
	}
	cout << "\n";
	while (!fin.eof()) {
		switch (i) {
		case 2:
			fin >> buff;
			if (buff < Arlimit) {
				save1 = 1;
				//cout << "save1 true\t";
			}
			else save1 = 0;
			i++;
			break;
		case 3:
			fin >> x;
			i++;
			break;
		case 4:
			fin >> y;
			i++;
			break;
		case 6:
			fin >> buff;
			if (save1 && buff < 2) {
				save2 = 1;
				//cout << "save2 true\n";
			}
			else save2 = 0;
			i++;
			break;
		case 8:
			fin >> buff;
			if (save1 && save2)	dotlist.push_back(make_pair(x, y));
			save1 = 1;
			save2 = 1;
			i = 1;
			break;
		default:
			fin >> buff;
			i++;
			break;
		}
	}

	//for( pair<double,double> x : dotlist) cout << x.first << "\t" << x.second << "\n";
	//cout << dotlist.size();
}