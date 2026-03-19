#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int, int>> mp;
        for (auto &p : pick) {
            int player = p[0];
            int color = p[1];

            mp[player][color]++;
        }

        int winners = 0;

        for (int i = 0; i < n; i++) {
            bool won = false;

        
            auto &playerColors = mp[i];

            for (auto &entry : playerColors) {
                int count = entry.second;
                if (count > i) {
                    won = true;
                    break;
                }
            }

            if (won) {
                winners++;
            }
        }

        return winners;
    }
};