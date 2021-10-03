#include <iostream>
#include <vector>

using namespace std;

void Find_element(vector<vector <int> >& matrix, int i, int j, int  number_of_columns) {
	matrix[i + number_of_columns][j] = matrix[i][j];
}

void check(int& pred_pos, int& pred_max, int now_pos, int now_max) {
	if (pred_max < now_max) {
		pred_max = now_max;
		pred_pos = now_pos;
	}
}

int main() {
	cout << "Enter number of lines in your matrix. (0 < number of lines < 6 )" << endl;
	int number_of_lines;
	cin >> number_of_lines;
	cout << "Enter number of columns in your matrix. (0 < number_of_columns < 11)" << endl;
	int number_of_columns;
	cin >> number_of_columns;
	while (number_of_columns > 10 || 2 * number_of_lines > 10) {
		cout << "Your matrix doesn't satisfies the condition, try again." << endl;
		cout << "Enter number of lines in your matrix." << endl;
		cin >> number_of_lines;
		cout << "Enter number of columns in your matrix." << endl;
		cin >> number_of_columns;
	}
	vector<vector<int>> matrix(2 * number_of_lines, vector<int>(number_of_columns));
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_columns; j++) {
			cin >> matrix[i][j];
			Find_element(matrix, i, j, number_of_lines);
		}
	}
	cout << endl << endl;
	for (int i = 0; i < number_of_lines * 2; i++) {
		for (int j = 0; j < number_of_columns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	int sum = 0;
	for (int j = 0; j < number_of_columns; j++) {
		bool ch = 1;
		for (int i = 0; i < number_of_lines; i++) {
			if (matrix[i][j] == 0) {
				ch = 0;
				break;
			}
		}
		if (ch) sum += 1;
	}
	cout << "Task 1" << endl << sum << endl << endl;
	int max_el = 1, line{}, max_line = 1;
	for (int i = 0; i < number_of_lines; i++) {
		line++;
		int el_kol = 1;
		for (int j = 1; j < number_of_columns; j++) {
			if (matrix[i][j] > matrix[i][j - 1]) {
				el_kol++;
			}
			else {
				el_kol = 1;
			}
			check(max_line, max_el, line, el_kol);
		}
	}
	cout << "Task 2" << endl << max_line;
	return 0;
}