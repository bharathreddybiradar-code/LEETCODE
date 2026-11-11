class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long both = min(need1, need2);

        long long cost = both * min(costBoth, cost1 + cost2);

        if (need1 > need2) {
            cost += 1LL * (need1 - need2) * min(cost1, costBoth);
        }
        else {
            cost += 1LL * (need2 - need1) * min(cost2, costBoth);
        }

        return cost;
    }
};