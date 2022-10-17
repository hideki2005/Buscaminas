#include<iostream>
#include<time.h>
#define MAX 32

using namespace std;

void mensaje();
int elegir_nivel();
int elegir_filas(int level);
int elegir_columnas(int level);
int elegir_minas(int level);
void inicializa_tablero(int row, int col, char space[MAX][MAX]);
void coloca_minas(int row, int col, char space[MAX][MAX], int minas);
void coloca_numeros(int row, int col, char space[MAX][MAX]);
void imprime_tablero(int jugadafila, int jugadacol, char space[MAX][MAX], char space2[MAX][MAX], int row, int col);
int verifica_ganador(int filas, int columnas, char space[MAX][MAX], int minas);

int main() {

	int level, row, col, min;
	int jugada_fila, jugada_columna;
	int situacion;
	char space[MAX][MAX], space2[MAX][MAX];

	mensaje();

	level = elegir_nivel();
	row = elegir_filas(level);
	col = elegir_columnas(level);
	min = elegir_minas(level);

	inicializa_tablero(row, col, space);
	coloca_minas(row, col, space2, min);
	coloca_numeros(row, col, space2);
	
	while (1)
	{
		cout << "Ingrese la fila y columna de la casilla que desea voltear: ";
		cin >> jugada_fila >> jugada_columna;

		if (jugada_fila > 0 and jugada_fila < row + 1 and jugada_columna >0 and jugada_columna < col + 1) {

			imprime_tablero(jugada_fila, jugada_columna, space, space2, row, col);
			situacion = verifica_ganador(row, col, space, min);

			if (situacion == 1) {

				cout << "Usted gano el juego";
				break;
			}
			else if (situacion == 2) {

				cout << "Usted perdio el juego";
				break;
			}
		}
		else cout << "Valores ingresados no son correctos" << endl;


	}
	


	return 0;
}



void mensaje () {


	cout << "Bienvenido a busca minas" << endl;
	cout << "Los niveles son: " << endl;
	cout << "<1>Nivel Principiante" << endl;
	cout << "<2>Nivel intermedio" << endl;
	cout << "<3>Nivel avanzado " << endl;
	cout << "<4>Nivel personalizado" << endl;




	
}

int elegir_nivel() {

	int l;

	do
	{

		cout << "Ingrese el nivel: ";
		cin >> l;


	} while (l != 1 and l != 2 and l != 3 and l != 4);


	return l;
}

int elegir_filas(int level)
{
	int filas;

	if (level == 1) filas = 8;
	else if (level == 2)filas = 16;
	else if (level == 3)filas = 16;
	else if (level == 4) {

		do
		{

			cout << "Ingrese el numero de filas: ";
			cin >> filas;

		} while (!(filas <= 30 and filas > 0));

	}


	return filas;
}

int elegir_columnas(int level)
{
	int columnas;

	if (level == 1) columnas = 8;
	else if (level == 2)columnas = 16;
	else if (level == 3)columnas = 30;
	else if (level == 4) {

		do
		{

			cout << "Ingrese el numero de columnas: ";
			cin >> columnas;

		} while (!(columnas <= 30 and columnas > 0));

	}


	return columnas;
}

int elegir_minas(int level)
{
	int minas;

	if (level == 1) minas = 10;
	else if (level == 2)minas = 40;
	else if (level == 3)minas = 99;
	else if (level == 4) {

		do
		{

			cout << "Ingrese el numero de minas: ";
			cin >> minas;

		} while (!(minas <= 200 and minas > 0));

	}


	return minas;
}

void inicializa_tablero(int row, int col, char space[MAX][MAX])
{
	for (int i = 0; i < row + 2; i++) {

		for (int j = 0; j < col+2; j++){

			space[i][j] = '0';


		}

	}

	cout << endl << "El tablero ha sido creado, puede empezar a jugar: " << endl;
	cout << "El table actual es: " << endl << endl;

	for (int i = 1; i < row + 1; i++) {

		for (int j = 1; j < col + 1; j++) {

			cout << space[i][j];

		}

		cout << endl;
	}

}

void coloca_minas(int row, int col, char space[MAX][MAX], int minas)
{

	int pcol, pfil; //columnas aleatorias

	for (int i = 0; i < row+2; i++)
	{
		for ( int j = 0; j < col +2; j++)
		{

			space[i][j] = '0';

		}
	}

	srand(time(NULL));

	while (1)
	{
		pfil = 1+rand()%row;
		pcol = 1 + rand() % col;


		//verificando si no hay una mina en la misma posicion
		if (space[pfil][pcol] == '0') {

			space[pfil][pcol] = 'M';

			minas--;
		}
		if (minas == 0)break;
	}

}

void coloca_numeros(int row, int col, char space[MAX][MAX]){



	int number; //cantidad de minas que hay en las casillas vecinas a cierta casilla

	for (int i = 1; i < row + 1; i++)
	{
		for (int j = 1; j < col + 1; j++)
		{

			if (space[i][j] == '0') {

				number = 0;

				if (space[i - 1][j] == 'M')number++;
				if (space[i - 1][j - 1] == 'M')number++;
				if (space[i - 1][j + 1] == 'M')number++;
				if (space[i][j - 1] == 'M')number++;
				if (space[i][j + 1] == 'M')number++;
				if (space[i + 1][j] == 'M')number++;
				if (space[i + 1][j - 1] == 'M')number++;
				if (space[i + 1][j + 1] == 'M')number++;

				if (number == 0)space[i][j] = ' ';
				else space[i][j] = number+'0';

			}


		}
	}
}




void imprime_tablero(int jugadafila, int jugadacol, char space[MAX][MAX], char space2[MAX][MAX], int row, int col)

{

	space[jugadafila][jugadacol] = space2[jugadafila][jugadacol];

	for (int i = 1; i < row + 1; i++) {

		for (int j = 1; j < col + 1; j++) {

			cout << space[i][j];

		}

		cout << endl;

	}



}

int verifica_ganador(int row, int col, char space[MAX][MAX], int minas)

{

	int situacion = 0;

	int casillas_falta = 0, cantidad_minas = 0;

	for (int i = 1; i < row + 1; i++) {

		for (int j = 1; j < col + 1; j++) {

			if (space[i][j] == 'M') cantidad_minas++;

			else if (space[i][j] == '0') casillas_falta++;

		}

	}



	if (cantidad_minas != 0) situacion = 2;

	else if (casillas_falta == minas) situacion = 1;



	return situacion;

}

