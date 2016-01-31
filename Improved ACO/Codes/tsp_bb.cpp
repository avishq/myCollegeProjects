#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <fstream>
using namespace std;

int d_min = INT_MAX;
vector <int> v;
vector <int> v1;
vector <vector <int> > vv;

void tsp(int a[][100], int n, int i, int col[], int t, int cd, int sum, int c[])
{
//    for (int j = 0; j < v.size(); j++) {
//        cout << v[j];
//    }

//    cout << "= " << t << endl;
	if (i == 0 && t == n) {

		if (cd < d_min) {
			d_min = cd;
			v1.clear();
			vv.clear();
			for (int j = 0; j < v.size(); j++) {
		                v1.push_back(v[j]);
			}
			vv.push_back(v1);

		} else if (cd == d_min) {
        		v1.clear();
			for (int j = 0; j < v.size(); j++) {
		                v1.push_back(v[j]);
			}
			vv.push_back(v1);
		}
		return;
	}

	if (i == 0 && t != n && t != 0) {
		return;
	}

	for (int j = 0; j < n; j++) {
		if (a[i][j] != 99 && col[j] != 1) {
           // cout << "cd = " << cd << "sum = " << sum << "d_min" << endl;
			if (cd + sum <= d_min) {
                    v.push_back(j);
				col[j] = 1;
				tsp(a, n, j, col, t + 1, cd + a[i][j], sum - c[j] / 2, c);
            v.pop_back();
				col[j] = 0;
			}
		}
	}
}

int main()
{
	int a[100][100];
	int b[100];
	int c[100];
	int sum = 0;
	int n = 14;
	int col[100];
//	cin >> n;
	ifstream f;
	f.open("Output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
//			cin >> a[i][j];
			f >> a[i][j];
			b[j] = a[i][j];
		}
		col[i] = 0;
		sort(b, b + n);
		sum = sum + b[0] + b[1];
		c[i] = b[0] + b[1];
		cout << "min is : " << c[i] << endl;
	}
	sum = sum / 2;

	tsp(a, n, 0, col, 0, 0, sum - c[0] / 2, c);
    cout << endl;
	cout << d_min << endl;
	cout << endl;
	for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++)
        {

            cout << vv[i][j] << " ";
        }
        cout << endl;
	}
    cout << endl;
}
