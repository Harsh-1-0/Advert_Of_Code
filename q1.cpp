#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Unable to open file input.txt";
        return 1;
    }
    vector<long> a, b;
    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        long num;
        while (ss >> num)
        {
            a.push_back(num);
            cout << num << endl;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long sum = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << b[i] << endl;
        sum += abs(a[i] - b[i]);
    }
    cout << sum << endl;
    inputFile.close();

    return 0;
}