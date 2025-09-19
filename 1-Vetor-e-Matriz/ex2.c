#include <stdio.h>

int main(){
    char vetorString[4][4] = {{"abcd"}, {"efgh"}, {"ijkl"}, {"mnop"}};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%c ", vetorString[i][j]);
        }
    }
    return 0;
}