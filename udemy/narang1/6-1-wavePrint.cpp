vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    // your code goes here
    vector<int> result {};
    for (auto col {n - 1}; col != -1; --col) {
        if (col % 2){
            for (int row {0}; row != m; ++row) {
                result.push_back(arr[row][col]);
            }
        }
        else {
            for (int row {m - 1}; row != -1; --row) {
                result.push_back(arr[row][col]);
            }
        }
    }
    return result;
}
