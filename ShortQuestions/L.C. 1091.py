class Solution:

    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        def addVector(coord, direction):
            return (coord[0] + direction[0], coord[1] + direction[1])

        def isValid(coord, grid):
            n = len(grid)
            return 0 <= coord[0] < n and 0 <= coord[1] < n


        directions = {(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,-1),(-1,1)}
        distances = {}
        n = len(grid)

        if(grid[0][0] == 1 or grid[n-1][n-1] == 1):
            return -1
        
        if(n==1):
            return 1

        start = (0,0)
        qu = deque()
        visited = set()
        qu.append(start)
        visited.add(start)
        distances[start] = 1


        while(qu):
            curr = qu.popleft()

            for dr in directions:
                coord = addVector(curr, dr)

                if(isValid(coord, grid) and grid[coord[0]][coord[1]] == 0 and coord not in visited):
                    qu.append(coord)
                    visited.add(coord)
                    distances[coord] = distances[curr] + 1

                    if(coord == (n-1,n-1)):
                        return distances[coord]

        return -1

