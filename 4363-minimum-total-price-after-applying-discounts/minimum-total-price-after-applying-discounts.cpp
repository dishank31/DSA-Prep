class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int idx1 = prices.size() - 1;
        int idx2 = discounts.size() - 1;

        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double sum = 0;
        while(idx1 >= 0 && idx2 >= 0)
        {
            sum += (double)(prices[idx1] * (double)(100 - discounts[idx2])) / 100;
            idx1--;
            idx2--;
        }

        for(int i=0 ; i<=idx1 ; i++)
            sum += (double)prices[i];

        return sum;
    }
};