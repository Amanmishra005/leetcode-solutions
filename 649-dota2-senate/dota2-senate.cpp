class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> r, d;

        // Fill initial positions
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        // Simulate rounds
        while (!r.empty() && !d.empty()) {
            int ri = r.front(); r.pop();
            int di = d.front(); d.pop();

            if (ri < di) {
                // Radiant bans Dire → Radiant gets another chance later
                r.push(ri + n);
            } else {
                // Dire bans Radiant → Dire gets another chance later
                d.push(di + n);
            }
        }

       if (r.empty()) {
    return "Dire";
} else {
    return "Radiant";
}

    }
};
