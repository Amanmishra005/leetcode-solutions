class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    struct State {
        int row;
        int col;
        int energyleft;
        int collectedMask;  //to count currently collected number of mask
    };

    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, -1, 0, 1};

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;

        int litterBit[20][20];          //use to store unique bit posi for L 
        int littercount = 0;
        int startR = 0;
        int startC = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                litterBit[r][c] = -1;

                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = littercount;
                    littercount++;
                }
            }
        }

        int allcollected = (1 << littercount) - 1; //2^litterCount - 1

        if (littercount == 0)
            return 0;

        VVVVB visited(m,VVVB(n, VVB(maxEnergy + 1, VB(1 << littercount, false))) );

        queue<State> que;
        que.push({startR, startC, maxEnergy, 0});

        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;

        while (!que.empty()) {
            int currsize = que.size();

            while (currsize--) {
                State curr = que.front();
                que.pop();

                if (curr.collectedMask == allcollected)
                    return moves;

                if (curr.energyleft == 0)
                    continue;

                for (int i = 0; i < 4; i++) {
                    int nrow = curr.row + row[i];
                    int ncol = curr.col + col[i];

                    if (nrow < 0 || nrow >= m ||ncol < 0 || ncol >= n)
                        continue;

                    char cell = classroom[nrow][ncol];

                    if (cell == 'X')
                        continue;

                    int nextenergy = curr.energyleft - 1;
                    int nextcollectedMask = curr.collectedMask;

                    if (cell == 'R') {
                        nextenergy = maxEnergy;
                    }
                    else if (cell == 'L') {
                        nextcollectedMask |=
                            (1 << litterBit[nrow][ncol]);
                    }
                    if (!visited[nrow][ncol][nextenergy][nextcollectedMask]) {
                        visited[nrow][ncol][nextenergy][nextcollectedMask] = true;

                        que.push({ nrow,ncol,nextenergy,nextcollectedMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};