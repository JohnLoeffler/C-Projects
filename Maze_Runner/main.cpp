/**
 *  NAME:   MAZERUNNER
 *  AUTHOR: JOHN LOEFFLER
 *  CONTACT:JOHN@JOHNLOEFFLER.COM | GITHUB.COM/JOHNLOEFFLER/C-PROJECTS/
 *  INPUT:  A PLAIN TEXT FILE "maze.txt", WITH SETUP INPUTS NEEDED TO BUILD THE
 *          MAZE, FED IN THIS ORDER: NUMBER OF COLUMNS, NUMBER OF ROWS, THE
 *          WHICH COLUMN YOU START IN, WHICH ROW YOU START IN, WHICH COLUMN YOU
 *          END IN, WHICH ROW YOU END IN, FOLLOWED BY A GRID LAYOUT OF THE MAZE,
 *          READ FROM LEFT TO RIGHT, THEN NEXT LINE, WHERE '0' IS AN ACCESSIBLE
 *          CELL AND '1' IS AN INEACCESSIBLE ONE
 *  OUTPUT: PRINTS TO CONSOLE
 *  USE:    NO RESTRICTIONS ON USE, HAVE AT IT
 */

#include <iostream>
#include <fstream>

using namespace std;

    //  PROTOTYPE  //

int mazeRunner(int** m,int sx,int sy,int ex,int ey,
               int nc,int nr,int **mx, int& ct);

int main()
{
    fstream infile("maze.txt");
    int nCol, nRow, sx, sy, ex, ey, ct = 0;
    infile >> nCol >> nRow >> sx >> sy >> ex >>  ey ;

    int     **maze,    **matrix;
    maze = new int*[nCol];
    matrix = new int*[nCol];
    for(int i = 0; i < nCol; i++){
        maze[i] =   new int[nRow];
        matrix[i]=  new int[nRow];
    }

    for(int i = 0; i < nCol; i++){
        for(int j = 0; j < nRow; j++){
            infile >> maze[j][i];
            matrix[j][i]    =   0;
            //cout << maze[j][i] << " ";    //  UNCOMMENT LINE 43 & 45 TO
        }                                   //      PRINT THE MAZE TO CONSOLE
        //cout << endl;                     //      BEFORE YOU RUN IT
    }

    infile.close(); // CLOSE MAZE.TXT

    /*
    *   FUNCTION RETURNS TRUE || FALSE, AND PRINTS DIFFERENT RESULTS TO CONSOLE
    *       DEPENDING ON WHETHER THE RUNNER SUCCESSFULLY REACHED THE EXIT CELL
    */
    if(mazeRunner(maze, sx, sy, ex, ey, nCol, nRow, matrix, ct)){
        cout << "==================================="   << endl;
        cout << "        Route Taken"                   << endl;
        cout << "==================================="   << endl;

        for(int x = 0; x < nCol+2; x++)
            cout << "=";
        cout << endl;

        for(int i = 0; i < nRow; i++){
            cout << "|";
            for(int j = 0; j < nCol; j++){
                if(matrix[j][i] != 0)
                    cout << matrix[j][i];
                else
                    cout << maze[j][i];
            }
            cout << "|"<< endl;
        }
        for(int x = 0; x < nCol+2; x++)
            cout << "=";
        cout << endl;
        cout << "Number of moves to find exit: " << ct << endl;
        cout << "===================================" << endl;
    }
    else{
        cout << "=====================================" << endl;
        cout << "         No route to exit" << endl;
        cout << "=====================================" << endl;
        cout << "Number of moves to exhaust search: " << ct << endl;
        cout << "=====================================" << endl;
    }

    //  RETURNS MEMORY TO SYSTEM    //

    for(int i = 0; i<nCol; i++)
        delete[] maze[i];
    delete[]    maze;

    return 0;
}
/**
 *  MAZERUNNER()    -   RECURSIVE, DYNAMIC FUNCTION THAT MAKES DECISIONS BASED
 *                          ON WHICH CELL IT HAS ALREADY VISITED
 *  @param  M       -   THE 2-D ARRAY CONTAINING THE MAZE
 *  @param  X       -   INITIALLY, THE STARTING COLUMN X IN ORDERED PAIR (X,Y)
 *                          BUT AFTER RECURSION, THE CURRENT COLUMN
 *  @param  Y       -   INITIALLY, THE STARTING ROW Y IN ORDERED PAIR (X,Y)
 *                          BUT AFTER RECURSION, THE CURRENT ROW
 *  @param  EX      -   THE ENDING COLUMN FOR THE MAZE
 *  @param  EY      -   THE ENDING ROW FOR THE MAZE
 *  @param  C       -   THE NUMBER OF COLUMNS IN THE MAZE GRID, FOR BOUNDS CHECK
 *  @param  R       -   THE NUMBER OF ROWS IN THE MAZE GRID, FOR BOUNDS CHECK
 *  @param  MX      -   THE MATRIX OF VISITED CELLS TO ENABLE FASTER PATHFINDING
 *  @param  CT      -   THE NUMBER OF MOVES, INCREMENTED ONCE FOR EACH FUNCTION
 *                          CALL AND AGAIN ON RETURN WITHOUT REACHING THE END
 *  @return 0,1     -   RETURNS '1' ONCE RUNNER FINDS THE EXIT, '0' WHEN
 *                          BACKTRACKING WITHOUT SUCCESS, FINAL RETURN '0' MEANS
 *                          RUNNER WAS UNABLE TO SUCCESSFULLY COMPLETE THE MAZE
 */

int mazeRunner(int **m, int x, int y, int ex, int ey,
                            int c, int r, int **mx, int& ct){
    //  FLAG CELL AS INACCESSIBLE UNLESS BACKTRACKING
    //      IF EXIT FOUND, THIS FLAG WILL NOT CHANGE, SHOWING
    //      SUCCESSFUL PATH THROUGH THE MAZE
    mx[x][y] = 2;

    //  EXIT FOUND  //
    if(x == ex && y == ey){ //  DON'T COUNT THE MOVES IN THE FINAL UNWINDING
        return 1;
    }

    /*

    for(int x = 0; x < c+2; x++)          //  UNCOMMENT TO SEE PATH
        cout << "=";                    //      AS IT IS DRAWN
        cout << endl;

    for(int i = 0; i < r; i++){
        cout << "|";
        for(int j = 0; j < c; j++){
            if(mx[j][i] != 0)
                cout << mx[j][i];
            else
                cout << m[j][i];
        }
        cout << "|"<< endl;
    }
    for(int x = 0; x < c+2; x++)
        cout << "=";
        cout << endl;

    */

    //  CHECKS SURROUNDING CELLS    //

            //  DOWN    //
    if(y < r-1 && mx[x][y+1] == 0 && m[x][y+1] == 0){

        if(mazeRunner(m, x, y+1, ex, ey, c, r, mx, ++ct)){
            return 1;
        }
        ct++;           //  BACKTRACKING COUNTS AS MOVES   //
        mx[x][y+1] = 0; //  NOT THE PATH, CLEAR ROUTE   //
    }
            //  LEFT    //
    if(x > 0 && mx[x-1][y] == 0 && m[x-1][y] == 0){
        if(mazeRunner(m, x-1, y, ex, ey, c, r, mx, ++ct)){
            return 1;
        }
        ct++;           //  BACKTRACKING COUNTS AS MOVES   //
        mx[x-1][y] = 0; //  NOT THE PATH, CLEAR ROUTE   //
    }
            //  UP      //
    if(y > 0 && mx[x][y-1] == 0 && m[x][y-1]==0){
        if(mazeRunner(m, x, y-1, ex, ey, c, r, mx, ++ct)){
            return 1;
        }
        ct++;           //  BACKTRACKING COUNTS AS MOVES   //
        mx[x][y-1] = 0; //  NOT THE PATH, CLEAR ROUTE   //
    }
            //  RIGHT   //
    if(x < c-1 && mx[x+1][y] == 0 && m[x+1][y] == 0){
        if(mazeRunner(m, x+1, y, ex, ey, c, r, mx, ++ct)){
            return 1;
        }
            ct++;           //  BACKTRACKING COUNTS AS MOVES   //
            mx[x+1][y] = 0; //  NOT THE PATH, CLEAR ROUTE   //
    }

    return 0;
}




