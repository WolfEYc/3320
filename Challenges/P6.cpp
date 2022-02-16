#include <iostream>
#include <vector>
using namespace std; 

void DFS(vector<vector<int>>& grid, int i, int j){
    if(i < 0 || j < 0  || j == grid.size() || i == grid.size() || !grid[i][j])
        return;

    grid[i][j] = 0;
    DFS(grid, i + 1, j);
    DFS(grid, i - 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
}

void countIslands(int& cnt, vector<vector<int>>& grid, const int& n){
    int i, j;
    for(i = 0; i != n; i++){
        for(j = 0; j != n; j++){
            if(grid[i][j]){
                cnt++;
                DFS(grid, i, j);
            }
        }
    }
}


int main()
{
	int n; 
	cin >> n; 
	//cout << "n=" << n << endl;

	vector<vector<int>> grid(n, vector<int>(n)); 

	for(int i=0; i!=n; i++) {
		for(int j=0; j!=n; j++) {
            cin >> grid[i][j];
		}
	}
	int cnt = 0;
	// now count how many islands!
    countIslands(cnt, grid, n);

	cout << cnt << endl; 
	return 0; 
}
