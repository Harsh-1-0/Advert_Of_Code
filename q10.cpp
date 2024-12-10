#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;
void findTrail(vector<vector<int>> input, int x, int y, int &n, vector<vector<bool>> &visited)
{
    if (visited[x][y] == true)
    {
        return;
    }
    visited[x][y] = true;
    if (input[x][y] == 9)
    {
        n++;
        return;
    }
    // up
    if (y - 1 >= 0 && input[x][y - 1] == input[x][y] + 1)
    {
        findTrail(input, x, y - 1, n, visited);
    }
    // right
    if (x + 1 < input.size() && input[x + 1][y] == input[x][y] + 1)
    {
        findTrail(input, x + 1, y, n, visited);
    }
    // down
    if (y + 1 < input[0].size() && input[x][y + 1] == input[x][y] + 1)
    {
        findTrail(input, x, y + 1, n, visited);
    }
    // left
    if (x - 1 >= 0 && input[x - 1][y] == input[x][y] + 1)
    {
        findTrail(input, x - 1, y, n, visited);
    }
    return;
}

void findTrailQ2(vector<vector<int>> input, int x, int y, int &n)
{

    if (input[x][y] == 9)
    {
        n++;
        return;
    }
    // up
    if (y - 1 >= 0 && input[x][y - 1] == input[x][y] + 1)
    {
        findTrailQ2(input, x, y - 1, n);
    }
    // right
    if (x + 1 < input.size() && input[x + 1][y] == input[x][y] + 1)
    {
        findTrailQ2(input, x + 1, y, n);
    }
    // down
    if (y + 1 < input[0].size() && input[x][y + 1] == input[x][y] + 1)
    {
        findTrailQ2(input, x, y + 1, n);
    }
    // left
    if (x - 1 >= 0 && input[x - 1][y] == input[x][y] + 1)
    {
        findTrailQ2(input, x - 1, y, n);
    }
    return;
}
int main()
{
    ifstream inputfile("input10.txt");
    string line;
    vector<vector<int>> input;
    vector<pair<int, int>> coordsZero;
    {
        while (getline(inputfile, line))
        {
            vector<int> temp;
            for (int i : line)
            {
                temp.push_back(int(i) - '0');
            }
            input.push_back(temp);
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j] == 0)
            {
                coordsZero.push_back({i, j});
            }
        }
    }
    int n = 0;
    int count = 0;
    for (auto i : coordsZero)
    {
        vector<vector<bool>> visited(input.size(), vector<bool>(input[0].size(), false));
        n = 0;
        findTrail(input, i.first, i.second, n, visited);
        count += n;
    }
    cout << count << endl;
    int count2 = 0;
    for (auto i : coordsZero)
    {
        n = 0;
        findTrailQ2(input, i.first, i.second, n);
        count2 += n;
    }

    cout << count2 << endl;
    return 0;
}