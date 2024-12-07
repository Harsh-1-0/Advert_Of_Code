#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int path = 0;
void traversal(vector<string> &arr, int ic, int jc, int dirX, int dirY)
{
    if (ic == 0 || jc == 0 || ic == arr.size() - 1 || jc == arr.size() - 1)
    {
        arr[ic][jc] = 'X';
        return;
    }

    // up
    if (dirX == 0 && dirY == 1)
    {
        if (arr[ic - 1][jc] == '#')
        {
            arr[ic][jc] = '>';
            traversal(arr, ic, jc, 1, 0);
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic - 1][jc] = '^';
            traversal(arr, ic - 1, jc, 0, 1);
        }
        return;
    }
    // right
    if (dirX == 1 && dirY == 0)
    {
        if (arr[ic][jc + 1] == '#')
        {
            arr[ic][jc] = 'v';
            traversal(arr, ic, jc, 0, -1);
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic][jc + 1] = '>';
            traversal(arr, ic, jc + 1, 1, 0);
        }
        return;
    }
    // down
    if (dirX == 0 && dirY == -1)
    {
        if (arr[ic + 1][jc] == '#')
        {
            arr[ic][jc] = '<';
            traversal(arr, ic, jc, -1, 0); // calling left
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic + 1][jc] = 'v';
            traversal(arr, ic + 1, jc, 0, -1);
        }
        return;
    }
    // left
    if (dirX == -1 && dirY == 0)
    {
        if (arr[ic][jc - 1] == '#')
        {
            arr[ic][jc] = '^';
            traversal(arr, ic, jc, 0, 1);
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic][jc - 1] = '<';
            traversal(arr, ic, jc - 1, -1, 0);
        }
    }
}
void traversalQ2(vector<string> &arr, int ic, int jc, int dirX, int dirY, int &path)
{
    if (ic == 0 || jc == 0 || ic == arr.size() - 1 || jc == arr.size() - 1)
    {
        arr[ic][jc] = 'X';
        return;
    }

    // up
    if (dirX == 0 && dirY == 1)
    {
        if (arr[ic - 1][jc] == 'O')
        {
            cout << "h";
            path += 1;
            return;
        }
        if (arr[ic - 1][jc] == '#')
        {
            arr[ic][jc] = '>';
            traversalQ2(arr, ic, jc, 1, 0, path);
            return;
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic - 1][jc] = '^';
            traversalQ2(arr, ic - 1, jc, 0, 1, path);
            return;
        }
    }
    // right
    if (dirX == 1 && dirY == 0)
    {
        if (arr[ic][jc + 1] == '#' || arr[ic][jc + 1] == 'O')
        {
            arr[ic][jc] = 'v';
            traversalQ2(arr, ic, jc, 0, -1, path);
            return;
        }
        else
        {
            arr[ic][jc] = '!';
            arr[ic][jc + 1] = '>';
            traversalQ2(arr, ic, jc + 1, 1, 0, path);
            return;
        }
    }
    // down
    if (dirX == 0 && dirY == -1)
    {
        if (arr[ic + 1][jc] == 'O')
        {
            cout << "h";
            path += 1;
            return;
        }
        if (arr[ic + 1][jc] == '#')
        {
            arr[ic][jc] = '<';
            traversalQ2(arr, ic, jc, -1, 0, path); // calling left
            return;
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic + 1][jc] = 'v';
            traversalQ2(arr, ic + 1, jc, 0, -1, path);
            return;
        }
    }
    // left
    if (dirX == -1 && dirY == 0)
    {
        if (arr[ic][jc - 1] == 'O')
        {
            cout << "h";
            path += 1;
            return;
        }
        if (arr[ic][jc - 1] == '#')
        {
            arr[ic][jc] = '^';
            traversalQ2(arr, ic, jc, 0, 1, path);
            return;
        }
        else
        {
            arr[ic][jc] = 'X';
            arr[ic][jc - 1] = '<';
            traversalQ2(arr, ic, jc - 1, -1, 0, path);
            return;
        }
    }
}
int main()
{
    ifstream inputFile("input6.txt"); // Open the file for reading

    if (!inputFile)
    {
        cerr << "Unable to open file";
        return 1; // Return an error code
    }
    vector<string> arr;
    string line;
    while (getline(inputFile, line))
    {
        arr.push_back(line);
    }
    inputFile.close();
    int ic, jc;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == '^')
            {
                ic = i;
                jc = j;
            }
        }
    }
    int count = 0;
    traversal(arr, ic, jc, 0, 1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 'X')
                count += 1;
        }
    }
    cout << count << endl;
    arr[ic][jc] = '^';
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 'X')
            {
                arr[i][j] = 'O';
                traversalQ2(arr, ic, jc, 0, 1, path);
                arr[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {

        cout << arr[i] << endl;
    }
    cout << path;
    return 0;
}