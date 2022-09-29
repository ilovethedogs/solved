int pairSticks(vector<int> length, int D)
{
    // your code goes here
    sort(length.begin(), length.end());
    
    int result {0};
    for (auto i {0}; i != length.size() - 1; ++i) {
        if (length[i+1] - length[i] <= D) {
            ++result;
            ++i;
        }
    }
    return result;
}