/* this algorithm somewhat has a probelm */
vector<int> optimizedBubbleSort(vector<int> v){
    // your code  goes here
	for (size_t i {1}; i != v.size(); ++i) {
	    bool done {true};
	    for (size_t j {0}; j != v.size() - i; ++j) {
	        if (v[j] > v[j+1]) {
	            done = false;
	            std::swap(v[j], v[j+1]);
	        }
	    }
	    if (done) break;
	}
		
    return v;
}