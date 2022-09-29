bool solution(string inputString) {
    size_t left {0};
    size_t right {inputString.size() - 1};

    while (left < right) {
        if (inputString[left] != inputString[right]) return false;
        ++left; --right;
    }
    return true;
}
