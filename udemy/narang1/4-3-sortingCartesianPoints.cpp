bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    else return false;
}

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    // your code goes here
    sort(v.begin(), v.end(), comp);
    
    return v;
}