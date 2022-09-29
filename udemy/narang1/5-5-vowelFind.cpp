string vowel(string S){
    // your code goes here
    vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
    
    string result {};
    for (auto i : S) {
        if (find(vowels.begin(), vowels.end(), i) != vowels.end()) result += i;
    }
    
    return result;
} 