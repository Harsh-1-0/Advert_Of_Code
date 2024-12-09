#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <fstream>
using namespace std;
void printArr(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}
void printArr(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
int main()
{
    ifstream inputFile("input8.txt");
    vector<string> arr;
    if (!inputFile)
    {
        cout << "Unable to open file";
        return 1;
    }
    string line;
    while (getline(inputFile, line))
    {
        arr.push_back(line);
    }
    unordered_map<char, vector<pair<int, int>>> coords;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] != '.')
            {
                coords[arr[i][j]].push_back({i, j});
            }
        }
    }
    int m = arr.size();
    int n = arr[0].size();
    // cout << m << " " << n << endl;
    // for (auto i : coords)
    // {
    //     cout << i.first;
    //     for (auto j : i.second)
    //     {
    //         cout << "(" << j.first << " " << j.second << ")";
    //     }
    //     cout << endl;
    // }
    set<pair<int, int>> visited;

    for (auto i : coords)
    {
        for (int j = 0; j < i.second.size(); j++)
        {
            for (int k = j + 1; k < i.second.size(); k++)
            {
                int r1 = i.second[j].first;
                int c1 = i.second[j].second;
                int r2 = i.second[k].first;
                int c2 = i.second[k].second;

                visited.insert({2 * r1 - r2, 2 * c1 - c2});
                visited.insert({2 * r2 - r1, 2 * c2 - c1});
            }
        }
    }
    cout << m << " " << n << endl;
    set<pair<int, int>> ans;
    for (auto i : visited)
    {
        if (i.first < 0 || i.first >= m || i.second < 0 || i.second >= n)
        {
            continue;
        }
        ans.insert(i);
    }
    cout << ans.size() << endl;

    visited.clear();
    for (auto i : coords)
    {
        for (int j = 0; j < i.second.size(); j++)
        {
            for (int k = j + 1; k < i.second.size(); k++)
            {
                int r1 = i.second[j].first, c1 = i.second[j].second;
                int r2 = i.second[k].first, c2 = i.second[k].second;
                int delX = r2 - r1, delY = c2 - c1;
                visited.insert({r1, c1});
                while (true)
                {
                    r1 -= delX;
                    c1 -= delY;
                    if (r1 < 0 || r1 >= m || c1 < 0 || c1 >= n)
                    {
                        break;
                    }
                    visited.insert({r1, c1});
                }
                visited.insert({r2, c2});
                while (true)
                {
                    r2 += delX;
                    c2 += delY;
                    if (r2 < 0 || r2 >= m || c2 < 0 || c2 >= n)
                    {
                        break;
                    }
                    visited.insert({r2, c2});
                }
            }
        }
    }
    cout << visited.size();
    return 0;
}
