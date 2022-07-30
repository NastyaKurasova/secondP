#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double Dmax = 20;
double Dmin = 1;

struct Dot {
    int number;
    int area;
    double xm;
    double ym;
    double circ;
    double AR;
    double round;
    double solid;
};

istream &operator>>(istream &in, Dot &a) {
    in >> a.number >> a.area >> a.xm >> a.ym >> a.circ >> a.AR >> a.round >> a.solid;
    return in;
}

ostream &operator<<(ostream &out, const Dot &a) 
{
    out << a.number << " " << a.area << " " << a.xm << " " << a.ym << " " << a.circ << " " << a.AR << " " << a.round << " " << a.solid;
    return out;
}
///5.c////


vector <vector<double>> MatrixFirst(vector <Dot>& Ar, double Dmin, double Dmax)
{
	const double M = Ar.size();
	vector <vector<double>> matrix_one(Ar.size(), vector<double>(Ar.size()));
	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			double distance = sqrt((Ar[i].xm - Ar[j].xm) * (Ar[i].xm - Ar[j].xm) + (Ar[i].ym - Ar[j].ym) * (Ar[i].ym - Ar[j].ym));
			if (distance > Dmin && distance < Dmax)
			{
				matrix_one[i][j] = 1;
				matrix_one[j][i] = 1;
			}
			else
			{
				matrix_one[i][j] = 0;
				matrix_one[j][i] = 0;
			}
		}
	}
	return matrix_one;
}

vector<vector<int>> MatrixSecond(const vector<Dot> &Ar, double Dmin, double Dmax) 
{
    vector<vector<int>> matrix_two(Ar.size(), vector<int>(Ar.size()));
    for (int i = 0; i < Ar.size(); i++) 
	{
        for (int j = i + 1; j < Ar.size(); j++) 
		{
           double distance = sqrt((Ar[i].xm - Ar[j].xm) * (Ar[i].xm - Ar[j].xm) + (Ar[i].ym - Ar[j].ym) * (Ar[i].ym - Ar[j].ym));
           if (distance > Dmin && distance < Dmax)
			{
				matrix_two[i][j] = sqrt((Ar[i].xm - Ar[j].xm) * (Ar[i].xm - Ar[j].xm) + (Ar[i].ym - Ar[j].ym) * (Ar[i].ym - Ar[j].ym)); 
				matrix_two[j][i] = sqrt((Ar[j].xm - Ar[i].xm) * (Ar[j].xm - Ar[i].xm) + (Ar[j].ym - Ar[i].ym) * (Ar[j].ym - Ar[i].ym)); 
			}
        }
        matrix_two[i][i] = 0;
    }
    return matrix_two;
}


///5.b////
vector <Dot> ChooseArea(vector <Dot>& a, double Dmin, double Dmax)
{
	vector <Dot> resultArea;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].area < ((pow((Dmax - Dmin), 2)) / 2))
		{
			resultArea.push_back(a[i]);
		}
	}
	return resultArea;
}


vector <Dot> ArLowTwo(vector <Dot>& a)
{
	vector <Dot> AreaLow;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].ar < 2)
			AreaLow.push_back(a[i]);
	}
	return AreaLow;
}


/// 5.a/////
int main()
{
	vector <double> a;
	//int n = 2;

	for (int i = 20; i < 304; i+=20)
	{
		ifstream fin{ "D:\\files\\file\\data- (" + to_string(i) + ").txt" };
		if (!fin)
		{
			cout << "Error";
			return 0;
		}
		else {
			string str;
			while (getline(fin, str))
			{
				for (double x; fin >> x;)
				{
					a.push_back(x);
					//cout << i << ": " << x << "\n" << endl;
				}
			}
			cout << a.size();
		}
		


	vector <Dot> p = ChooseArea(a, Dmin, Dmax);
	//for (const Dot& y : p) cout << y;
	cout << "Choose area: " << p.size() << "\n";

	vector <Dot> Ar = ArLowTwo(a, size);
	//for (const Dot& z : Ar) cout << z;
	cout << "AR lower 2: " << Ar.size();

	vector<vector<double>> matrix = MatrixFirst(Ar, Dmin, Dmax);
	vector<vector<double>> matrix2 = MatrixSecond(Ar, Dmin, Dmax);

	/*for (int i = 0; i < Ar.size(); i++)
	{
		for (int j = 0; j < Ar.size(); j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}*/
}
