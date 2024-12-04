#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream file("input3.txt");
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    regex mul_regex(R"(mul\((\d+),(\d+)\))");
    regex do_regex(R"(do\(\))");
    regex dont_regex(R"(don't\(\))");

    vector<pair<int, int>> mul_values;
    vector<size_t> mul_indices, do_indices, dont_indices;
    smatch match;
    string::const_iterator search_start(data.cbegin());

    while (regex_search(search_start, data.cend(), match, mul_regex))
    {
        mul_values.emplace_back(stoi(match[1]), stoi(match[2]));
        mul_indices.push_back(match.position());
        search_start = match.suffix().first;
    }

    search_start = data.cbegin();
    while (regex_search(search_start, data.cend(), match, do_regex))
    {
        do_indices.push_back(match.position());
        search_start = match.suffix().first;
    }

    search_start = data.cbegin();
    while (regex_search(search_start, data.cend(), match, dont_regex))
    {
        dont_indices.push_back(match.position());
        search_start = match.suffix().first;
    }

    int sum = 0, sum2 = 0;
    for (const auto &val : mul_values)
    {
        sum += val.first * val.second;
    }

    vector<int> p(mul_indices.size(), 1);
    size_t i = 0, j = 0;

    while (i < do_indices.size() && j < dont_indices.size())
    {
        if (do_indices[i] < dont_indices[j])
        {
            for (size_t k = 0; k < mul_indices.size(); ++k)
            {
                if (mul_indices[k] > do_indices[i])
                {
                    p[k] = 1;
                }
            }
            ++i;
        }
        else
        {
            for (size_t k = 0; k < mul_indices.size(); ++k)
            {
                if (mul_indices[k] > dont_indices[j])
                {
                    p[k] = 0;
                }
            }
            ++j;
        }
    }

    while (i < do_indices.size())
    {
        for (size_t k = 0; k < mul_indices.size(); ++k)
        {
            if (mul_indices[k] > do_indices[i])
            {
                p[k] = 1;
            }
        }
        ++i;
    }

    while (j < dont_indices.size())
    {
        for (size_t k = 0; k < mul_indices.size(); ++k)
        {
            if (mul_indices[k] > dont_indices[j])
            {
                p[k] = 0;
            }
        }
        ++j;
    }

    for (size_t k = 0; k < mul_indices.size(); ++k)
    {
        if (p[k] == 1)
        {
            sum2 += mul_values[k].first * mul_values[k].second;
        }
    }

    cout << sum << endl;
    cout << sum2 << endl;

    return 0;
}