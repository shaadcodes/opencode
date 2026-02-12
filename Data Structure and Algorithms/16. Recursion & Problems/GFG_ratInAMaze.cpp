#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    isSafe() Function

    Return type - bool

    Arguments:
        1. Integer newx
        2. Integer newy
        3. Integer destination
        4. Reference to 2D vector of bool visited
        5. Reference to 2D vector of int maze

    Approach:
        Check if newx and newy are within bounds of the maze, if the cell is open (maze[newx][newy] == 1),
        and if it has not been visited yet
    
    Time Complexity: O(1) for each call
    Space Complexity: O(1) for each call
*/

bool isSafe(int newx, int newy, int destination,  vector <vector <bool>> & visited, vector <vector <int>> & maze)
{
    if((newx >= 0 && newx <= destination) && (newy >= 0 && newy <= destination) && (maze[newx][newy] == 1) && (visited[newx][newy] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
    solve() Function

    Return Type - void

    Arguments:
        1. Reference to 2D vector of int maze
        2. Reference to vector of strings answer
        3. String direction
        4. Reference to 2D vector of bool visited
        5. Integer xindex
        6. Integer yindex
        7. Integer destination

    Approach:
        Base case: If xindex and yindex are at the destination, push the current direction string to answer and return
        Recursive case: Mark the current cell as visited, then explore all four possible directions (down, up, right, left),
        if they are safe. After exploring each direction, backtrack by popping the last character from direction and
        marking the current cell as unvisited.

    Time Complexity: O(4^(n*m)) in the worst case where n and m are the dimensions of the maze (each cell can lead to 4 directions)
    Space Complexity: O(n*m) due to the visited array and recursive call stack in the worst case
*/
    
void solve(vector<vector<int>> & maze, vector<string> & answer, string direction, vector<vector<bool>> visited, int xindex, int yindex, int destination)
{
    if(xindex == destination && yindex == destination)
    {
        answer.push_back(direction);
        return;
    }
        
    visited[xindex][yindex] = true;
        
    int newx = xindex + 1;
    int newy = yindex;
    if(isSafe(newx, newy, destination, visited, maze))
    {
        direction.push_back('D');
        solve(maze, answer, direction, visited, newx, newy, destination);
        direction.pop_back();
    }
        
    newx = xindex - 1;
    newy = yindex;
    if(isSafe(newx, newy, destination, visited, maze))
    {
        direction.push_back('U');
        solve(maze, answer, direction, visited, newx, newy, destination);
        direction.pop_back();
    }
        
    newx = xindex;
    newy = yindex + 1;
    if(isSafe(newx, newy, destination, visited, maze))
    {
        direction.push_back('R');
        solve(maze, answer, direction, visited, newx, newy, destination);
        direction.pop_back();
    }
        
    newx = xindex;
    newy = yindex - 1;
    if(isSafe(newx, newy, destination, visited, maze))
    {
        direction.push_back('L');
        solve(maze, answer, direction, visited, newx, newy, destination);
        direction.pop_back();
    }
        
    visited[xindex][yindex] = false;
}

/*
    ratInMaze() Function

    Return type - vector of strings

    Arguments:
        1. Reference to 2D vector of int maze

    Approach:
        Initialize answer vector to store valid paths, direction string to build current path, and visited 2D vector to track visited cells.
        Check if the starting cell (0,0) is open (maze[0][0] == 1), if not return empty answer.
        Call solve() function to explore all paths from the starting cell.
        Sort the answer vector before returning to ensure paths are in lexicographical order.

    Time Complexity: O(4^(n*m)) in the worst case where n and m are the dimensions of the maze
    Space Complexity: O(n*m) due to the visited array and recursive call stack in the worst case
*/

vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<string> answer;
    string direction;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    int xindex = 0;
    int yindex = 0;
    int destination = maze.size() - 1;
        
    if (maze[0][0] == 0)
        return answer;
        
    solve(maze, answer, direction, visited, xindex, yindex, destination);
    sort(answer.begin(), answer.end());
    return answer;
}

// ---------------------------------------------------MAIN FUNCTION---------------------------------------------------

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    
    vector<string> paths = ratInMaze(maze);
    
    cout << "Paths from (0,0) to (" << maze.size() - 1 << "," << maze[0].size() - 1 << "):" << endl;
    for(int i = 0; i < paths.size(); i++)
    {
        cout << paths[i] << endl;
    }
    
    return 0;
}