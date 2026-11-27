class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        auto factors = items | views::transform([](auto& item) { return item[0]; });
        auto prices = items | views::transform([](auto& item) { return item[1]; });
        int cheapest = ranges::min(prices);
        vector<int> best(budget + 1);  // no first copies yet: everything goes to the cheapest item
        for (int money = 0; money <= budget; money++) best[money] = money / cheapest;
        for (auto& item : items) {
            int factor = item[0], price = item[1];
            int gain = ranges::count_if(factors, [&](int other) { return other % factor == 0; });  // the copy itself + a free copy of every other multiple
            for (int money = budget; money >= price; money--)  // backwards: one first copy per item
                best[money] = max(best[money], best[money - price] + gain);
        }
        return best[budget];
    }
};