#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix {
	vector<vector<int>> m;
public:
	Matrix() {
		vector<vector<int>> m(3);
		this->m = m;
		for (int i = 0; i < 3; i++) {
			vector<int> m_i(3);
			this->m[i] = m_i;
		}
	}

	int &operator[](int i, int j) {
		return m[i][j];
	}

	vector<vector<int>>::iterator begin() {
		return m.begin();
	}
	vector<vector<int>>::iterator end() {
		return m.end();
	}
};

int main() {
   Matrix m;
   m[1, 1] = 5;

   for (const auto &row : m) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
   }
}