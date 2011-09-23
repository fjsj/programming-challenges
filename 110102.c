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
