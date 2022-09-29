// Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

int solution(vector<int> inputArray) {
    auto result {inputArray[0] * inputArray[1]};
    for (auto i {1}; i != inputArray.size() - 1; ++i)
        result = max(result, inputArray[i] * inputArray[i + 1]);
    return result;
}
