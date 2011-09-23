/*
Minesweeper

Have you ever played Minesweeper? This cute little game comes with a certain operating system whose name we can't remember. The goal of the game is to find where all the mines are located within a M x N field.
The game shows a number in a square which tells you how many mines there are adjacent to that square. Each square has at most eight adjacent squares. The 4 x 4 field on the left contains two mines, each represented by a ``*'' character. If we represent the same field by the hint numbers described above, we end up with the field on the right:

*...
....
.*..
....
*100
2210
1*10
1110

Input

The input will consist of an arbitrary number of fields. The first line of each field contains two integers n and m ( 0 < n, m100) which stand for the number of lines and columns of the field, respectively. Each of the next n lines contains exactly m characters, representing the field.

Safe squares are denoted by ``.'' and mine squares by ``*,'' both without the quotes. The first field line where n = m = 0 represents the end of input and should not be processed.

Output

For each field, print the message Field #x: on a line alone, where x stands for the number of the field starting from 1. The next n lines should contain the field with the ``.'' characters replaced by the number of mines adjacent to that square. There must be an empty line between field outputs.

Sample Input

 4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0

Sample Output

Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100
*/

#include <stdio.h>

int field[100][100]; //mine squares will be denoted by -1
//current bounds:
int nLines = 100;
int nColumns = 100;

void clearField() {
    int i;
    for (i = 0; i < nLines; i++) {
        int j;
        for (j = 0; j < nColumns; j++) {
            field[i][j] = 0;
        }
    }
}

void setBounds(int l, int c) {
    nLines = l;
    nColumns = c;
}

int isInsideBounds(int i, int j) {
    return i >= 0 && i < nLines && j >=0 && j < nColumns;
}

void increment(int i, int j) {
    if (isInsideBounds(i, j) && field[i][j] != -1) {
        ++field[i][j];
    }
}

void setMine(int i, int j) {
    field[i][j] = -1;
    
    //increment neighbours
    int m;
    for (m = -1; m <= 1; m++) {
        int n;
        for (n = -1; n <= 1; n++) {
            increment(i + m, j + n);
        }
    }
}

void printField(nField) {
    printf("Field #%d:\n", nField);
    
    int i;
    for (i = 0; i < nLines; i++) {
        int j;
        for (j = 0; j < nColumns; j++) {
            int x = field[i][j];
            
            if (x == -1) { //if is mine, print *
                printf("*");
            } else {
                printf("%d", x);
            }
        }
        printf("\n");
    }
}

int main() {
    int l, c; //input vars (field lines and columns)
    int nField = 1;
    
    for (;;) {
        scanf("%d %d", &l, &c);
        if (l == 0 && c == 0) { //if end of input, break
            break;
        }
        
        setBounds(l, c);
        clearField();
        
        int i;
        for (i = 0; i < l; i++) {
            char line[c + 1]; //remeber \0
            scanf("%s", line);
            
            int j;
            for (j = 0; j < c; j++) {
                char currentChar = line[j];
                if (currentChar == '*') {
                    setMine(i, j);
                }
            }
        }
        
        if (nField > 1) {
            printf("\n");
        }
        printField(nField);
        
        ++nField;
    }
    return 0;
}
