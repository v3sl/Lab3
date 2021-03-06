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

void test_matrix(int number_of_columns, int number_of_lines) {
	while (number_of_columns > 10 || 2 * number_of_lines > 10) {
		cout << "Your matrix doesn't satisfies the condition, try again." << endl;
		cout << "Enter number of lines in your matrix." << endl;
		cin >> number_of_lines;
		cout << "Enter number of columns in your matrix." << endl;
		cin >> number_of_columns;
		test_matrix(number_of_columns, number_of_lines);
	}
}
void test_ZERO_OR_ONE(int ZERO_OR_ONE) {
	while (ZERO_OR_ONE != 1 && ZERO_OR_ONE != 0) {
		cout << "You should enter 1 or 0 to continue" << endl;
		cin >> ZERO_OR_ONE;
		test_ZERO_OR_ONE(ZERO_OR_ONE);
	}
}
void create_matrix(int ZERO_OR_ONE, vector<vector <int>>& matrix, int number_of_columns, int number_of_lines) {
	float MIN_ELEMENT = 0;
	float MAX_ELEMENT = 0;
	if (ZERO_OR_ONE == 0) {
		for (int i = 0; i < number_of_lines; i++) {
			for (int j = 0; j < number_of_columns; j++) {
				cin >> matrix[i][j];
				Find_element(matrix, i, j, number_of_lines);
			}
		}
	}
	else {
		cout << "Enter maximum border of your array " << endl;
		cin >> MAX_ELEMENT;
		cout << "Enter minimum border of your array " << endl;
		cin >> MIN_ELEMENT;
		cout << "Your array will consist of elemenst from " << MIN_ELEMENT << " to " << MAX_ELEMENT << " " << endl;
		for (int i = 0; i < number_of_lines; i++) {
			for (int j = 0; j < number_of_columns; j++) {
				static const float fraction = 1.0 / (static_cast<float>(RAND_MAX) + 1.0);
				matrix[i][j] = static_cast<int>(rand() * fraction * (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT);
				Find_element(matrix, i, j, number_of_lines);
			}
		}
	}
	cout << endl << endl;
}
void print_matrix(vector<vector <int>>& matrix, int number_of_columns, int number_of_lines) {
	for (int i = 0; i < number_of_lines * 2; i++) {
		for (int j = 0; j < number_of_columns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
int task1(vector<vector <int>>& matrix, int number_of_columns, int number_of_lines) {
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
	return sum;
}
int task2(vector<vector <int>>& matrix, int number_of_columns, int number_of_lines) {
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
	return  max_line;
}

int main() {
	int number_of_lines, number_of_columns, ZERO_OR_ONE = -2;
	cout << "Enter number of lines in your matrix. (0 < number of lines < 6 )" << endl;
	cin >> number_of_lines;
	cout << "Enter number of columns in your matrix. (0 < number_of_columns < 11)" << endl;
	cin >> number_of_columns;
	test_matrix(number_of_columns, number_of_lines);
	vector<vector<int>> matrix(2 * number_of_lines, vector<int>(number_of_columns));
	cout << "Enter 1 if you want to generate random numbers or 0 if you want to enter numbers by yourself" << endl;
	cin >> ZERO_OR_ONE;
	test_ZERO_OR_ONE(ZERO_OR_ONE);
	create_matrix(ZERO_OR_ONE, matrix, number_of_columns, number_of_lines);
	print_matrix(matrix, number_of_columns, number_of_lines);
	cout << "Task 1" << endl << task1(matrix, number_of_columns, number_of_lines) << endl << endl;
	cout << "Task 2" << endl << task2(matrix, number_of_columns, number_of_lines);
	return 0;
}