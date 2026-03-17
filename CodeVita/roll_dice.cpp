#include <bits/stdc++.h>
using namespace std;

struct Dice {
    int top, bottom, left, right, front, back;

    Dice(int t, int l, int f) {
        top = t;
        left = l;
        front = f;
        bottom = 7 - t;
        right = 7 - l;
        back = 7 - f;
    }

    Dice roll(string dir) const {
        Dice d = *this;
        if (dir == "right") {
            d.top = left;
            d.left = bottom;
            d.bottom = right;
            d.right = top;
        } else if (dir == "left") {
            d.top = right;
            d.right = bottom;
            d.bottom = left;
            d.left = top;
        } else if (dir == "up" || dir == "top") {
            d.top = front;
            d.front = bottom;
            d.bottom = back;
            d.back = top;
        } else if (dir == "down") {
            d.top = back;
            d.back = bottom;
            d.bottom = front;
            d.front = top;
        }
        return d;
    }

    bool operator==(const Dice &o) const {
        return top == o.top && left == o.left && front == o.front;
    }
};

struct State {
    int cube;
    Dice dice;
    int cost;

    bool operator>(const State &o) const {
        return cost > o.cost;
    }
};

int main() {
    int N;
    cin >> N;

    vector<tuple<int, int, string>> placements;
    for (int i = 0; i < N; i++) {
        int a, b;
        string dir;
        cin >> a >> b >> dir;
        placements.push_back({a, b, dir});
    }

    sort(placements.begin(), placements.end());

    unordered_map<int, pair<int, int>> pos;
    pos[get<0>(placements[0])] = {0, 0};
    map<pair<int, int>, int> grid;
    grid[{0, 0}] = get<0>(placements[0]);

    for (auto &[a, b, dir] : placements) {
        auto [x, y] = pos[a];
        if (dir == "left") x--;
        else if (dir == "right") x++;
        else if (dir == "top" || dir == "up") y++;
        else if (dir == "down") y--;

        // handle overlap: remove old cube if exists
        if (grid.count({x, y})) {
            int old = grid[{x, y}];
            pos.erase(old);
        }

        pos[b] = {x, y};
        grid[{x, y}] = b;
    }

    // build adjacency
    unordered_map<int, vector<pair<int, string>>> adj;
    for (auto &[cube, p] : pos) {
        int x = p.first, y = p.second;
        vector<pair<string, pair<int, int>>> dirs = {
            {"right", {x + 1, y}},
            {"left", {x - 1, y}},
            {"up", {x, y + 1}},
            {"down", {x, y - 1}}
        };
        for (auto &[dname, coord] : dirs) {
            if (grid.count(coord)) adj[cube].push_back({grid[coord], dname});
        }
    }

    int src, dest;
    cin >> src >> dest;
    int top, left, front;
    cin >> top >> left >> front;
    Dice start(top, left, front);

    map<tuple<int, int, int, int>, int> dist;
    priority_queue<State, vector<State>, greater<State>> pq;
    dist[{src, top, left, front}] = 0;
    pq.push({src, start, 0});

    int ans = -1;
    while (!pq.empty()) {
        auto [cube, dice, cost] = pq.top();
        pq.pop();

        if (cube == dest) {
            ans = cost;
            break;
        }

        for (auto &[nextCube, dir] : adj[cube]) {
            Dice newDice = dice.roll(dir);
            int newCost = cost + newDice.top;
            auto key = make_tuple(nextCube, newDice.top, newDice.left, newDice.front);
            if (!dist.count(key) || newCost < dist[key]) {
                dist[key] = newCost;
                pq.push({nextCube, newDice, newCost});
            }
        }
    }

    cout << ans << endl;
    return 0;
}
