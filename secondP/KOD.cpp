#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "Hallo!" << "\n";
	cout << "��� ������?";
	ifstream fin{ "DZ.txt" };
	vector <double> a;
	//for (double x; fin >> x;) a.push_back(x);
}