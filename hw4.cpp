#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void display(int b[][15]);
void searchpath(int b[][15], stack<int>&);

int main()
{
	int map[15][15] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,1,1,1,1,0,0,0,0,1,1,1},
		{1,1,0,1,1,1,1,1,0,1,1,0,1,1,1},
		{1,1,0,1,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,0,0,1,1,1,0,0,1,1,1},
		{1,1,1,1,1,1,0,0,1,1,0,1,1,1,1},
		{1,1,1,1,1,1,1,0,1,1,0,1,1,1,1},
		{1,1,1,1,0,0,0,0,1,1,0,1,1,1,1},
		{1,1,1,1,1,1,1,0,1,1,0,1,1,1,1},
		{1,1,1,1,0,1,1,0,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} 
	};
	display(map);

	stack<int> path;
	searchpath(map, path);

	cout << "\n\n'>'为可行路径\n";
	display(map);

	return 0;
}

void display(int b[][15]) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (b[i][j] == 0)
				cout << "·";
			if (b[i][j] == 1)
				cout << "# ";
			if (b[i][j] == 2)
				cout << "> ";
			if (b[i][j] == 3)
				cout << "$ ";
		}
		cout << endl;
	}
}
void searchpath(int b[][15], stack<int>& path) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++)
			if (b[i][j] == 2) {
				path.push(i * 14 + j);
				break;
			}
	}

	int x, y;
	while(!path.empty()) {
		x = path.top() / 14;
		y = path.top() % 14;
		if (b[x + 1][y] == 0) {
			b[x + 1][y] = 2;
			path.push((x + 1) * 14 + y);
			continue;
		}
		if (b[x - 1][y] == 0) {
			b[x - 1][y] = 2;
			path.push((x - 1) * 14 + y);
			continue;
		}
		if (b[x][y + 1] == 0) {
			b[x][y + 1] = 2;
			path.push(x * 14 + y + 1);
			continue;
		}
		if (b[x][y - 1] == 0) {
			b[x][y - 1] = 2;
			path.push(x * 14 + y - 1);
			continue;
		}
		if (b[x + 1][y] == 3 || b[x - 1][y] == 3 || b[x][y + 1] == 3 || b[x][y - 1] == 3)
			break;

		b[x][y] = 1;
		path.pop();
	}
}