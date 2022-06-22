int binaryToDecimal(string s)
{
    // your code goes here
    int fac = 1;
    int result {0};
    while (s.size()) {
        s.back() == '1' ? result += fac * 1 : 0;
        s.pop_back();
        fac *= 2;
    }
    return result;
}
 