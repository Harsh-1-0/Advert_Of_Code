#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

long long calculateCheckSum(vector<string> &process)
{
    long long checkSum = 0;
    for (long long i = 0; i < process.size(); i++)
    {
        if (process[i] == ".")
        {
            continue;
        }

        checkSum += (stoi(process[i])) * i;
    }
    return checkSum;
}

void fileSystem(vector<string> &process)
{
    long long i = 0, j = process.size() - 1;
    while (i < j)
    {
        while (process[i] != ".")
        {
            i++;
        }
        while (process[j] == ".")
        {
            j--;
        }
        if (i < j)
        {
            swap(process[i], process[j]);
            i++;
            j--;
        }
    }
}

void fileSystemP2(vector<string> &process, vector<int> &gaps)
{
    map<int, int> count;
    for (int i = 0; i < process.size(); i++)
    {
        if (process[i] != ".")
        {
            count[stoi(process[i])]++;
        }
    }
    vector<pair<int, int>> countVec(count.begin(), count.end());
    sort(countVec.begin(), countVec.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first > b.first; });
    vector<vector<string>> gapMap(gaps.size(), vector<string>({}));
    // for (int i = 0; i < countVec.size(); i++)
    // {
    //     cout << countVec[i].first << " " << countVec[i].second << endl;
    // }
    for (int i = 0; i < countVec.size(); i++)
    {
        for (int j = 0; j < gaps.size(); j++)
        {
            // cout << countVec[i].first << " " << countVec[i].second << endl;
            if (gaps[j] >= countVec[i].second)
            {
                gaps[j] -= countVec[i].second;
                int s = countVec[i].second;
                countVec[i].second = 0;
                int k = 0;
                for (int k = 0; k < s; k++)
                {
                    gapMap[j].push_back(to_string(countVec[i].first));
                }

                break;
            }
        }
    }
    for (int i = 0; i < gapMap.size(); i++)
    {
        for (int j = 0; j < gapMap[i].size(); j++)
        {
            for (int k = 0; k < process.size(); k++)
            {
                if (process[k] == ".")
                {
                    process[k] = gapMap[i][j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < gapMap.size(); i++)
    {
        for (int j = 0; j < gapMap[i].size(); j++)
        {
            for (int k = process.size() - 1; k >= 0; k--)
            {
                if (process[k] == gapMap[i][j])
                {
                    process[k] = ".";
                    break;
                }
            }
        }
    }

    for (int i = 0; i < process.size(); i++)
    {
        cout << process[i] << " ";
    }
    cout << endl;
}
int main()
{
    ifstream inputfile("input9.txt");
    if (!inputfile)
    {
        cout << "Unable to open file";
        return 1;
    }
    string line;
    getline(inputfile, line);
    vector<string> process;
    vector<int> gaps;
    long long k = 0;
    for (long long i = 0; i < line.size(); i++)
    {
        long long n = line[i] - '0';
        if (i % 2 != 0)
        {
            gaps.push_back(n);
            if (n == 0)
            {
                continue;
            }
            for (long long i = 0; i < n; i++)
            {

                process.push_back(".");
            }
        }
        else
        {
            for (long long i = 0; i < n; i++)
            {
                process.push_back(to_string(k));
            }
            k++;
        }
    }
    // fileSystem(process);
    // cout << calculateCheckSum(process);

    fileSystemP2(process, gaps);
    cout << calculateCheckSum(process);

    return 0;
}