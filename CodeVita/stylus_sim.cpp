#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Rectangle {
    int x, y, w, h;
};

bool isWithinCanvas(int M, int N, int x, int y, int w, int h) {
    return (x >= 0 && y >= 0 && x + w <= N && y + h <= M);
}

bool overlaps(const Rectangle& r1, const Rectangle& r2) {
    if (r1.x < r2.x + r2.w && r1.x + r1.w > r2.x &&
        r1.y < r2.y + r2.h && r1.y + r1.h > r2.y) {
        return true;
    }
    return false;
}

bool touches(const Rectangle& r1, const Rectangle& r2) {
    if (r1.x == r2.x + r2.w || r1.x + r1.w == r2.x ||
        r1.y == r2.y + r2.h || r1.y + r1.h == r2.y) {
        return true;
    }
    return false;
}

bool isValidPlacement(const vector<Rectangle>& rects, const Rectangle& newRect) {
    for (const auto& rect : rects) {
        if (overlaps(rect, newRect) || touches(rect, newRect)) {
            return false;
        }
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    
    int C;
    cin >> C;
    cin.ignore();
    
    vector<Rectangle> rectangles;
    vector<string> invalidCommands;
    
    for (int i = 0; i < C; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;
        
        if (command == "draw") {
            int x, y, w, h;
            ss >> x >> y >> w >> h;
            
            Rectangle newRect = {x, y, w, h};
            
            if (!isWithinCanvas(M, N, x, y, w, h) || !isValidPlacement(rectangles, newRect)) {
                invalidCommands.push_back(line);
            } else {
                rectangles.push_back(newRect);
            }
        }
        else if (command == "remove") {
            int x, y, w, h;
            ss >> x >> y >> w >> h;
            
            bool found = false;
            for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
                if (it->x == x && it->y == y && it->w == w && it->h == h) {
                    rectangles.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found) {
                invalidCommands.push_back(line);
            }
        }
        else if (command == "extend" || command == "shrink") {
            int x, y, w, h;
            ss >> x >> y >> w >> h;
            
            bool found = false;
            for (auto& rect : rectangles) {
                if (rect.x == x && rect.y == y) {
                    Rectangle newRect = {x, y, w, h};
                    
                    if (!isWithinCanvas(M, N, x, y, w, h) || !isValidPlacement(rectangles, newRect)) {
                        invalidCommands.push_back(line);
                    } else {
                        rect.w = w;
                        rect.h = h;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                invalidCommands.push_back(line);
            }
        }
    }
    
    for (const auto& cmd : invalidCommands) {
        cout << cmd << endl;
    }
    
    cout << rectangles.size() << endl;
    
    return 0;
}