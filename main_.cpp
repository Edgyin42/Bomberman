#include <iostream>
#include <vector>
#include <utility>

// Define game elements
enum CellType {
    EMPTY = 0,
    PLAYER = 1,
    WALL_SOLID = 2,
    WALL_BREAKABLE = 3,
    BOMB = 4,
    EXPLOSION = 5,
    POWERUP = 6
};

// Direction vectors for raycasting (Up, Right, Down, Left)
// const std::pair<int, int> DIRECTIONS[4] = {
//     {-1, 0}, {0, 1}, {1, 0}, {0, -1}
// };



class GameMap {
private:
    std::vector<std::vector<int>> grid;
    int rows;
    int cols;

public:
    GameMap(int r, int c) : rows(r), cols(c) {
        // Initialize empty grid
        grid.resize(rows, std::vector<int>(cols, EMPTY));
    }

    // Set a cell's type
    void setCell(int row, int col, CellType type) {
        if (isValidPosition(row, col)) {
            grid[row][col] = type;
        }
    }

    // Get a cell's type
    CellType getCell(int row, int col) const {
        if (isValidPosition(row, col)) {
            return static_cast<CellType>(grid[row][col]);
        }
        return WALL_SOLID; // Out of bounds cells act as solid walls
    }

    // Check if position is within grid bounds
    bool isValidPosition(int row, int col) const {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    // Perform raycast explosion from a bomb
    void raycastExplosion(int bombRow, int bombCol, int explosionRange) {
        // Mark bomb cell as explosion
        setCell(bombRow, bombCol, EXPLOSION);
        
        // Cast rays in all four directions
        for (const auto& dir : DIRECTIONS) {
            castRay(bombRow, bombCol, dir.first, dir.second, explosionRange);
        }
    }

private:
    // Cast a ray from bomb position in a given direction
    void castRay(int startRow, int startCol, int rowDir, int colDir, int range) {
        int currentRow = startRow;
        int currentCol = startCol;
        
        // Continue ray up to maximum range
        for (int i = 1; i <= range; ++i) {
            currentRow += rowDir;
            currentCol += colDir;
            
            // Stop if out of bounds
            if (!isValidPosition(currentRow, currentCol)) {
                break;
            }
            
            CellType cellType = getCell(currentRow, currentCol);
            
            if (cellType == WALL_SOLID) {
                // Solid wall stops explosion
                break;
            } else if (cellType == WALL_BREAKABLE) {
                // Breakable wall is destroyed and stops explosion
                setCell(currentRow, currentCol, EXPLOSION);
                break;
            } else if (cellType == PLAYER) {
                // Player is hit by explosion
                setCell(currentRow, currentCol, EXPLOSION);
                // In a real game, this would damage or eliminate the player
            } else if (cellType == BOMB) {
                // Chain reaction - this would trigger the bomb
                setCell(currentRow, currentCol, EXPLOSION);
                // In a real game, this would schedule this bomb to explode next
                break;
            } else if (cellType == POWERUP) {
                // Powerup is destroyed
                setCell(currentRow, currentCol, EXPLOSION);
            } else {
                // Empty space or already an explosion
                setCell(currentRow, currentCol, EXPLOSION);
            }
        }
    }
};

class BombManager {
private:
    GameMap& gameMap;

public:
    BombManager(GameMap& map) : gameMap(map) {}

    // Place a bomb at the specified position
    void placeBomb(int row, int col) {
        if (gameMap.getCell(row, col) == EMPTY) {
            gameMap.setCell(row, col, BOMB);
        }
    }

    // Detonate a bomb at the specified position
    void detonateBomb(int row, int col, int explosionRange) {
        if (gameMap.getCell(row, col) == BOMB) {
            gameMap.raycastExplosion(row, col, explosionRange);
        }
    }
};

// Debug function to print the grid
void printGrid(const GameMap& map, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char symbol;
            switch (map.getCell(i, j)) {
                case EMPTY: symbol = '.'; break;
                case PLAYER: symbol = 'P'; break;
                case WALL_SOLID: symbol = '#'; break;
                case WALL_BREAKABLE: symbol = 'B'; break;
                case BOMB: symbol = 'O'; break;
                case EXPLOSION: symbol = '*'; break;
                case POWERUP: symbol = '?'; break;
                default: symbol = '?'; break;
            }
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int ROWS = 10;
    const int COLS = 10;
    
    // Create a new game map
    GameMap gameMap(ROWS, COLS);
    
    // Create bomb manager
    BombManager bombManager(gameMap);
    
    // Set up some walls and a player
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                gameMap.setCell(i, j, WALL_SOLID); // Border walls
            } else if ((i % 2 == 0) && (j % 2 == 0)) {
                gameMap.setCell(i, j, WALL_SOLID); // Interior solid walls
            }
        }
    }
    
    // Add some breakable walls
    gameMap.setCell(2, 1, WALL_BREAKABLE);
    gameMap.setCell(1, 2, WALL_BREAKABLE);
    gameMap.setCell(3, 2, WALL_BREAKABLE);
    gameMap.setCell(5, 5, WALL_BREAKABLE);
    
    // Add a player
    gameMap.setCell(1, 1, PLAYER);
    
    // Add a powerup
    gameMap.setCell(3, 4, POWERUP);
    
    // Place a bomb
    bombManager.placeBomb(2, 3);
    
    // Print initial state
    std::cout << "Initial Map:" << std::endl;
    printGrid(gameMap, ROWS, COLS);
    
    // Detonate the bomb with range 3
    bombManager.detonateBomb(2, 3, 3);
    
    // Print final state
    std::cout << "After Explosion (range 3):" << std::endl;
    printGrid(gameMap, ROWS, COLS);
    
    return 0;
}