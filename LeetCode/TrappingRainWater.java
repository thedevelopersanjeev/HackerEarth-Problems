class Solution {
    class Cell {
        int x, y, h;
        public Cell(int x, int y, int h) {
            this.x = x;
            this.y = y;
            this.h = h;
        }
    }
    // main code block
    public int trapRainWater(int[][] heightMap) {
        if(isInvalid(heightMap)) return 0;
        
        int m = heightMap.length, n = heightMap[0].length;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        boolean[][] visited = new boolean[m][n];
        // Prepare queue
        PriorityQueue<Cell> queue = new PriorityQueue<>(Comparator.comparing(cell -> cell.h));
        init(visited, queue, heightMap);
        
        // Calculate total
        int total = 0;
        while (!queue.isEmpty()) {
            Cell cell = queue.poll();
            for (int i = 0; i < dx.length; i++) {
                int mX = cell.x + dx[i];
                int mY = cell.y + dy[i];
                if (isValidCoordinate(mX, mY, visited)) {
                    visited[mX][mY] = true;
                    total += cell.h > heightMap[mX][mY] ? cell.h - heightMap[mX][mY] : 0; // cell is lowest, so any lower should contain water
                    queue.offer(new Cell(mX, mY, Math.max(cell.h, heightMap[mX][mY])));
                }
            }
        }
        return total;
    }

    // helper functions:
    private void init(boolean[][] visited, PriorityQueue<Cell> queue, int[][] heightMap) {
        int m = heightMap.length, n = heightMap[0].length;
        // LEFT/RIGHT
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            queue.offer(new Cell(i, 0, heightMap[i][0]));
            queue.offer(new Cell(i, n - 1, heightMap[i][n - 1]));
        }
        // TOP/BOTTOM
        for (int j = 0; j < n; j++) {
            visited[0][j] = true;
            visited[m - 1][j] = true;
            queue.offer(new Cell(0, j, heightMap[0][j]));
            queue.offer(new Cell(m - 1, j, heightMap[m - 1][j]));
        }
    }
    
    private boolean isValidCoordinate(int x, int y, boolean[][] visited) {
        int m = visited.length, n = visited[0].length;
        return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y];
    }
    
    private boolean isInvalid(int[][] heightMap) {
        return heightMap == null || heightMap.length == 0 || heightMap[0] == null || heightMap[0].length == 0;
    }
}