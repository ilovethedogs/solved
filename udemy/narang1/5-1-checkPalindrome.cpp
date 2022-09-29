bool isPalindrome(string str)
{
    // your code goes here
    for (size_t i {0}, j{str.size() - 1}; i <= j; ++i, --j) {
        if (str[i] != str[j]) return false;
    }
    return true;
}