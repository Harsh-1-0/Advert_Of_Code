#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

bool checkOpetions(long long result, vector<long long> input, int pos, long long val)
{

    if (pos == input.size())
    {
        return result == val;
    }

    if (checkOpetions(result, input, pos + 1, val + input[pos]))
    {
        return true;
    }
    if (checkOpetions(result, input, pos + 1, val * input[pos]))
    {
        return true;
    }

    if (checkOpetions(result, input, pos + 1, val * pow(10, to_string(input[pos]).size()) + input[pos]))
    {
        return true;
    }

    return false;
}

int main()
{
    ifstream inputFile("input7.txt");
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
    vector<long long> result;
    vector<vector<long long>> inputs;
    for (int i = 0; i < arr.size(); i++)
    {
        int k = 0;
        string c;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] != ':')
                c += arr[i][j];
            else
            {
                k = j + 2;
                result.push_back(stoll(c));
                break;
            }
        }
        c = "";
        vector<long long> temp;
        for (k; k < arr[i].size(); k++)
        {
            if (arr[i][k] != ' ')
            {
                c += arr[i][k];
            }
            else
            {
                temp.push_back(stoll(c));
                c = "";
            }
        }
        temp.push_back(stol(c));
        inputs.push_back(temp);
    }
    long long sum = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        if (checkOpetions(result[i], inputs[i], 0, 0))
        {
            sum += result[i];
        }
    }
    // cout << checkOpetions(result[1], inputs[1], 0, 0);
    cout << sum;
    // cout << 12 * pow(10, to_string(345).size()) + 345;
    return 0;
}