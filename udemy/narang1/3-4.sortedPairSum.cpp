/* given a sorted array and a number x, find a pair in array whose sum is closest to x */

std::pair<int, int> closestSum(std::vector<int> arr, int x) {
	size_t s { 0 };
	size_t e { arr.size() - 1 };

	size_t cur { x + 100 };
	std::pair<int, int> result { };
	while ( s < e ) {
		auto tmp { x - arr[e] };

		if (tmp == arr[e]) {
			result.first = arr[s];
			result.second = arr[e];
			return result;
		}
		else if (tmp < arr[e]) {
			if (cur > arr[e] - tmp) {
				cur = arr[e] - tmp;
				result.first = arr[s];
				result.second = arr[e];
			}
			--e;
		}
		else {
			if (cur > tmp - arr[e]) {
				cur = tmp - arr[e];
				result.first = arr[s];
				result.second = arr[e];
			}
			++s;
		}
	}
	return result;
}
