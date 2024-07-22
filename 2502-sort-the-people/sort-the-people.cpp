#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        std::vector<std::pair<std::string, int>> pairs{};
        for (std::size_t i = 0; i < names.size(); i++)
            pairs.push_back(std::make_pair(names[i], heights[i]));

        std::sort(std::execution::par_unseq, pairs.begin(), pairs.end(), [](const auto& a, const auto& b) -> bool
        {
            return a.second > b.second;
        });

        std::vector<std::string> ret;
        for (const auto& p : pairs)
            ret.push_back(p.first);

        return ret;
    }
};