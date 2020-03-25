#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) 
{
    // set up the initial min as the largest possible integer tha c++ 11 allows
    int min_abs_diff = INT_MAX;
    int size = arr.size();

    // sort the input array so that the numbers can just be subtracted once going left to right
    // i.e. exampleArray = {-3, 4, -7, 3, -9}  {-9, -7, -3, 4, 4}
    // Must be sorted before subtracting since we are running only one for loop
    // the min difference in this example is supposed to be zero (4 - 4)
    // before the sort, (4 - 4) is never checked, again since we only have 1 for loop
    sort(arr.begin(), arr.begin() + size);

    // basic for loop going left to right on an array, comparing it with its direct next neighbor
    // update min_abs_diff based on comparison of curr and min
    for(int i = 0; i < size - 1; i++)
    {   
        int curr_abs_diff = abs(arr[i] - arr[i + 1]);
        min_abs_diff = min(curr_abs_diff, min_abs_diff);
    }

    return min_abs_diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

    fout << result << "\n";

    fout.close();

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
