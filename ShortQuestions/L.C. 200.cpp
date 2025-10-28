class Solution 
{
public:

    vector<int> addVector(vector<int> & direction, vector<int> & current_coords)
    {
        return {direction[0] + current_coords[0], direction[1] + current_coords[1]};
    }

    bool isValidCoords(vector<vector<char>> & grid, vector<int> & coords)
    {
        return coords[0] >= 0 && coords[0] < grid[0].size() && 
               coords[1] >= 0 && coords[1] < grid.size();
    }

    void bfs(vector<vector<char>> & grid, set<vector<int>> & visited, vector<int> & source)
    {
        queue<vector<int>> qu;
        qu.push(source);
        visited.insert(source);
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!qu.empty())
        {
            vector<int> curr = qu.front();
            qu.pop();
            visited.insert(curr);

            for(auto & dr : directions)
            {
                vector<int> coords = addVector(dr, curr);
                if(isValidCoords(grid, coords) && !visited.contains(coords) && grid[coords[1]][coords[0]] == '1')
                {
                    visited.insert(coords);
                    qu.push(coords);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int sol = 0;
        set<vector<int>> visited;

        for(int y = 0; y < grid.size(); y++)
        {
            for(int x = 0; x < grid[y].size(); x++)
            {
                vector<int> coord = {x,y};
                if(grid[y][x] == '1' && !visited.contains(coord))
                {
                    bfs(grid, visited, coord);
                    sol++;
                }
            }
        }
        return sol;
    }
};