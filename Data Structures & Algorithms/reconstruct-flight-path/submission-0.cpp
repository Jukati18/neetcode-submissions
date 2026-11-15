class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];
            graph[from].push(to);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
private:
    void dfs(const string& current_airport, 
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, 
             vector<string>& itinerary) {

        while (!graph[current_airport].empty()) {
            string next_airport = graph[current_airport].top();
            
            graph[current_airport].pop(); 
            
            dfs(next_airport, graph, itinerary);
        }
        
        itinerary.push_back(current_airport);
    }
};
