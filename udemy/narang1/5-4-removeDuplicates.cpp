string removeDuplicate(string s){
    // your code goes here
    string result {};
    
    map<char, int> dup {};
    for (auto i : s) {
        if (dup.find(i) == dup.end()) {
            dup.emplace(i, 0);
            result += i;
        }
    }
    sort(result.begin(), result.end());
    return result;
}