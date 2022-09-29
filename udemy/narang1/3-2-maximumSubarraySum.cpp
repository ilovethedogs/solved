/* implement a function that takes an array as input an returns the maximum subarray sum */

int maxSumSubarray(std::vector<int> A) {
	bool all_negative { true };

	for (auto i : A)
		i > 0 ? all_negative = false : true;

	auto maxSum { A[0] };
	if (all_negatvie) {
		for (int i {1}; i != A.size(); ++i) {
			curSum += A[i];
			curSum < 0 ? curSum = 0 : 0;
			maxSum = max(maxSum, curSum);
		}
	}
	return maxSum;
}
