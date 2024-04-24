#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void getNM(vector<int> &seq, set<int> &numbers, int n, int m)
{
    if (seq.size() == static_cast<size_t>(m))
    {
        for (int i = 0; i < m - 1; i++)
            cout << seq.at(i) << " ";
        cout << seq.at(m - 1) << "\n";
        return;
    }

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        if (seq.size() && seq.back() > *it)
            continue;
        seq.push_back(*it);
        getNM(seq, numbers, n, m);
        seq.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m, input;
    vector<int> seq;
    set<int> numbers;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        numbers.insert(input);
    }

    getNM(seq, numbers, n, m);

    return 0;
}