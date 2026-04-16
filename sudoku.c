#include <stdio.h>


int CeldasVaciasAux(int matriz[9][9], int fila, int columna);

//usamos l funcion recursiva
int CeldasVacias(int matriz[9][9]) {
    return CeldasVaciasAux(matriz, 0,0);
   
};

//creamos funcion recursiva para buscar 
int CeldasVaciasAux(int matriz[9][9], int fila, int columna){
    if (fila == 9) {
        return 0;
    }
    if (columna == 9) {
        return CeldasVaciasAux(matriz, fila + 1, 0);
    }
    if (matriz[fila][columna] == 0) {
        return 1 + CeldasVaciasAux(matriz, fila, columna + 1);
    }
    return CeldasVaciasAux(matriz, fila, columna + 1);
}

//int ProbarNumero(int tablero[N][N], int posx, int posy, int num){

//}
//debe retornar 0 en caso de invalido y 1 en caso de valido

//int resolverSudoku(int tablero[N][N]){

//}
//resuelve el sudoku


int main() {
    int matriz[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    //imprimimos el tablero
    printf("Tablero: \n");
    for (int i = 0; i < 9; i++){
        printf("|");
        for(int j = 0; j < 9; j++){
            printf("%d", matriz[i][j]);
        }
        printf("|\n");
    }

    printf("%d \n", CeldasVacias(matriz));


}