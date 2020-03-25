#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
// Contests is a double vector array with [i][j] being
// i = value of the contest (the amount that will be added or subtracted depending on loss or win respectively)
// j = importance (1 = important, 0 = unimportant)
int luckBalance(int k, vector<vector<int>> contests) {
    int final_luck = 0;
    int size = contests.size();
    int lossTrack = k;

    sort(contests.begin(), contests.begin() + size);

    for(int i = size - 1; i >= 0; i--)
    {
        int luck = contests[i][0];
        int importance = contests[i][1];
        if(importance == 0)
        {
            final_luck += luck;
            cout << luck << endl;
        }
        else if(importance == 1 && lossTrack > 0)
        {
            final_luck += luck;
            cout << luck << endl;
            lossTrack--;
        }
        else
        {
            final_luck -= luck;
            cout << luck << endl;
        }
    }

    return final_luck;
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}