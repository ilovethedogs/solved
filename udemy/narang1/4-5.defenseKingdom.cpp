int defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    if (position.size() == 0) return W * H;
    
    vector<int> width {0, W+1};
    vector<int> height {0, H+1};
    for (auto& i : position) {
        width.push_back(i.first);
        height.push_back(i.second);
    }
    
    sort(width.begin(), width.end());
    sort(height.begin(), height.end());
    
    auto width_max {0};
    auto height_max {0};
    for (auto i {0}; i != width.size() - 1; ++i) {
        width_max = max(width_max, width[i+1] - width[i] - 1);
        height_max = max(height_max, height[i+1] - height[i] - 1);
    }
    
    return width_max * height_max;
}