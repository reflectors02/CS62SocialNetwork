class Solution {
public: 
    bool isValid(const vector<vector<int>> & heights, int y1, int x1, int y2, int x2)
    {
        int y_max = heights.size();
        int x_max = heights[0].size();
        if(x2 < 0 || x2 >= x_max || y2 < 0 || y2 >= y_max)
        {
            return false;
        }
    
        if(heights[y1][x1] < heights[y2][x2])
        {
            return false;
        }

        return true;
    }


    bool bfs(vector<vector<int>> & heights, vector<int> & source, vector<vector<int>> & visited)
    {
        bool pacific = false;
        bool atlantic = false;
        static const int directions[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        int y_max = heights.size();
        int x_max = heights[0].size();

        queue<pair<int,int>> qu;
        qu.push({source[0], source[1]});
        visited[source[0]][source[1]] = 1;

        while(!qu.empty())
        {
            auto [y,x] = qu.front();
            qu.pop();
            if (y == 0 || x == 0) pacific = true;
            if (y == y_max - 1 || x == x_max - 1) atlantic = true;
            if (pacific && atlantic) return true; 

            for(int k = 0; k < 4; k++)
            {
                int ny = y + directions[k][0];
                int nx = x + directions[k][1];

                if(isValid(heights, y, x, ny, nx) && !visited[ny][nx])
                {
                    qu.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }
        return pacific && atlantic;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> sol;
        int y_max = heights.size();
        int x_max = heights[0].size();
        vector<vector<int>> visited(y_max, vector<int>(x_max,0));


        for(int y = 0; y < heights.size(); y++)
        {
            for(int x = 0; x < heights[y].size(); x++)
            {
                for (int i = 0; i < y_max; ++i)
                {
                    fill(visited[i].begin(), visited[i].end(), 0);
                }

                vector<int> coords = {y,x};
                if(bfs(heights, coords, visited))
                {
                    sol.push_back(coords);
                }
            }
        }

        return sol;
    }
};