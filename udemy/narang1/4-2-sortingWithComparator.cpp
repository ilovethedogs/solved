vector<int> sortingWithComparator(vector<int> a, bool flag){
    // your code  goes here
    switch (flag) {
        case true:
            sort(a.begin(), a.end());
            break;
        case false:
            sort(a.begin(), a.end(), greater<int>());
    }
    return a;
}