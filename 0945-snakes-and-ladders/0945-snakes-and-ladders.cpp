class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> adj(n * n + 1, -1);
        bool leftToRight = true;
        int idx = 1;
        for(int row = n - 1; row >= 0; row--)
        {
            if(leftToRight)
            {
                for(int col = 0; col < n; col++)
                {
                    adj[idx++] = board[row][col];
                }
            }
            else
            {
                for(int col = n - 1; col >= 0; col--)
                {
                    adj[idx++] = board[row][col];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int>q;
        vector<bool> vis(n * n + 1, false);
        q.push(1);
        vis[1] = true;
        int moves = 0;
        while(! q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                if(curr == n * n) return moves;
                for(int dice = 1; dice <= 6; dice++)
                {
                    int next = curr + dice;
                    if(next > n * n) break;
                    int dist = (adj[next] == -1) ? next : adj[next];
                    if(! vis[dist])
                    {
                        vis[dist] = true;
                        q.push(dist);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};