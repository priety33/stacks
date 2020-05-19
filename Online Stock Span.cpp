class StockSpanner {
public:
    vector<int> stocks;
    stack<int> days;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stocks.push_back(price);
        int n=stocks.size();
        while(!days.empty() && stocks[days.top()]<=price) days.pop();
        int ans= (days.empty())? n : n-days.top()-1;
        days.push(n-1);
        return ans;
    }
};
