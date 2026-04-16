#include <stdio.h>

int BuscarVacia(int tablero[9][9], int *fila, int *columna);
int BuscarVaciaAux(int tablero[9][9], int filaActual, int columnaActual, int *fila, int *columna);
int ProbarValores(int tablero[9][9], int fila, int columna, int num);
int resolverSudoku(int tablero[9][9]);
int CeldasVaciasAux(int matriz[9][9], int fila, int columna);
int ProbarNumero(int tablero[9][9], int posx, int posy, int num);


//usamos la funcion recursiva
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

//revisamos si el numeor ya esta en la fila
int RevisarFila(int tablero[9][9], int fila, int columna, int num) {
    if (columna == 9) {
        return 1;
    }

    if (tablero[fila][columna] == num) {
        return 0;
    }

    return RevisarFila(tablero, fila, columna + 1, num);
}
//revisamos si el numero ya esta en la columna
int RevisarColumna(int tablero[9][9], int fila, int columna, int num) {
    if (fila == 9) {
        return 1;
    }

    if (tablero[fila][columna] == num) {
        return 0;
    }

    return RevisarColumna(tablero, fila + 1, columna, num);
}

//revisamos si el numeor ya esta en el bloque 3x3
 int RevisarBloque(int tablero[9][9], int inicioFila, int inicioColumna, int k, int num) {
    if (k == 9) {
        return 1;
    }

    int fila = inicioFila + k / 3; //saber que fila
    int columna = inicioColumna + k % 3; //saber que columna

    if (tablero[fila][columna] == num) {
        return 0;
    }

    return RevisarBloque(tablero, inicioFila, inicioColumna, k + 1, num);
}


int ProbarNumero(int tablero[9][9], int posx, int posy, int num) {
    int inicioFila = (posx / 3) * 3;
    int inicioColumna = (posy / 3) * 3;

    if (RevisarFila(tablero, posx, 0, num) == 0) {
        return 0;
    }

    if (RevisarColumna(tablero, 0, posy, num) == 0) {
        return 0;
    }

    if (RevisarBloque(tablero, inicioFila, inicioColumna, 0, num) == 0) {
        return 0;
    }

    return 1;
}
// si lo encuentra en cualquiera de esas 3 partes retorna 0, si no lo encuentra retorna 1

int BuscarVacia(int tablero[9][9], int *fila, int *columna) {
    return BuscarVaciaAux(tablero, 0, 0, fila, columna);
}

int BuscarVaciaAux(int tablero[9][9], int filaActual, int columnaActual, int *fila, int *columna) {
    if (filaActual == 9) {
        return 0;
    }

    if (columnaActual == 9) {
        return BuscarVaciaAux(tablero, filaActual + 1, 0, fila, columna);
    }

    if (tablero[filaActual][columnaActual] == 0) {
        *fila = filaActual;
        *columna = columnaActual;
        return 1;
    }

    return BuscarVaciaAux(tablero, filaActual, columnaActual + 1, fila, columna);
}

int ProbarValores(int tablero[9][9], int fila, int columna, int num) {
    if (num == 10) {
        return 0;
    }

    if (ProbarNumero(tablero, fila, columna, num) == 1) {
        tablero[fila][columna] = num;

        if (resolverSudoku(tablero) == 1) {
            return 1;
        }

        tablero[fila][columna] = 0;
    }

    return ProbarValores(tablero, fila, columna, num + 1);
}

 int resolverSudoku(int tablero[9][9]) {
        int fila;
        int columna;

        if (BuscarVacia(tablero, &fila, &columna) == 0) {
            return 1;
        }

        return ProbarValores(tablero, fila, columna, 1);
 }

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
    //si se soluciono o no
    if (resolverSudoku(matriz) == 1) {
    printf("Sudoku resuelto: \n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("|\n");
    }
} else if (resolverSudoku(matriz) == 0) {
    printf("No tiene solucion\n");
}
}