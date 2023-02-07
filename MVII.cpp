//Edson Iram Moreno Quintanilla 1856049
//Ing.Adriana Garza Álvarez MV2
#include<iostream>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include <iomanip>
#include<conio.h>
#include<math.h>

using namespace std;

void Main();
int Tamaño(char xy);


char* Checarnum(string Indicaciones);
char* ChecarDat(string inst);
void LlenarMat(int x, int y,float mat[10][10]);
void gotoxy(int x, int y);
//void ImpMat(float mat[10][10], int x, int y);
void SumaMat(float mat1[10][10], int x1, int y1, float mat2[10][10], int x2, int y2, float op[10][10], string datos);
void InvAd(float mat1[10][10], int x1, int y1, float mat2[10][10], int x2, int y2, float op[10][10]);
void MultiMat(float mat1[10][10], int x1, int y1, float mat2[10][10], int x2, int y2, float op[10][10]);
void Traslacion();
void Escalamiento();
void Rotacion();
void Transformaciones();
void LlenarNodos(char op, float x, float y, float z);
void MatCompuesta(short cantidad);
void LlenarNodosPPuntos(char op, float x, float y, float z);
void MatrizxVector();
void RotacionCuaternios();
void LlenarCopiaNodosPuntos(float x, float y, float z);
float ChecarDecimales(float num);
void BorrarNodos();
void BorrarNodosC();

struct Nodo {
	Nodo* PPrev;
	char opc;
	float x;
	float y;
	float z;
	Nodo* PSig;
}*Inicio, * aux, * InicioC, * auxC;

int main() {
	Main();
}

void Main() {
	
	int x1, y1, x2, y2;
	char opc, opcion=2;
	float mat1[10][10] = { '\0' };
	float mat2[10][10] = { '\0' };
	float op[10][10] = { '\0' };
	do {
		system("cls");
		cout << "\t\t\tCalculadora de matrices.";
		cout << "\n\t\tElige una opcion:";
		cout << "\n\t1.-Suma de matrices.";
		cout << "\n\t2.-Inverso aditivo de matrices.";
		cout << "\n\t3.-Multiplicacion de matrices.";
		cout << "\n\t4.-Transformaciones simples.";
		cout << "\n\t5.-Matriz compuesta de un primitivo grafico segun angulos dados.";
		cout << "\n\t6.-Matriz por vector.";
		cout << "\n\t7.-Generacion de nuevas coordenadas por quaterniones.";
		cout << "\n\t8.-Salir.";
		cout << "\n  Opcion:";
		cin >> opc;
		switch (opc) {
		case'1':
			system("cls");
			cout << "Define el tamaño de la primer matriz:" << endl;
			x1 = Tamaño('x');
			y1 = Tamaño('y');
			system("cls");
			cout << "Matriz de " << y1 << "x" << x1;
			LlenarMat(x1, y1, mat1);
			system("cls");
			cout << "Define el tamaño de la segunda matriz:" << endl;
			x2 = Tamaño('x');
			y2 = Tamaño('y');
			system("cls");
			cout << "Matriz de " << y2 << "x" << x2;
			LlenarMat(x2, y2, mat2);
			SumaMat(mat1, x1, y1, mat2, x2, y2, op, "La suma de las matrices es:\n");
			break;
		case'2':
			system("cls");
			cout << "Define el tamaño de la primer matriz:" << endl;
			x1 = Tamaño('x');
			y1 = Tamaño('y');
			system("cls");
			cout << "Matriz de " << y1 << "x" << x1;
			LlenarMat(x1, y1, mat1);
			system("cls");
			cout << "Define el tamaño de la segunda matriz:" << endl;
			x2 = Tamaño('x');
			y2 = Tamaño('y');
			system("cls");
			cout << "Matriz de " << y2 << "x" << x2;
			LlenarMat(x2, y2, mat2);
			InvAd(mat1, x1, y1, mat2, x2, y2, op);
			break;
		case'3':
			system("cls");
			cout << "Define el tamaño de la primer matriz:" << endl;
			x1 = Tamaño('x');
			y1 = Tamaño('y');
			system("cls");
			cout << "Matriz de " << y1 << "x" << x1;
			LlenarMat(x1, y1, mat1);
			system("cls");
			cout << "Define el tamaño de la segunda matriz:" << endl;
			x2 = Tamaño('x');
			y2 = Tamaño('y');
			system("cls");
			cout << "Matriz de " << y2 << "x" << x2;
			LlenarMat(x2, y2, mat2);
			MultiMat(mat1, x1, y1, mat2, x2, y2, op);
			break;
		case'4':
			system("cls");
			cout << "\nTransformaciones simples.";
			cout << "\n\t1.-Traslacion.";
			cout << "\n\t2.-Escalamiento.";
			cout << "\n\t3.-Rotacion.";
			cout << "\nOpcion:";
			cin >> opc;
			switch (opc) {
			case'1':
				Traslacion();
				break;
			case'2':
				Escalamiento();
				break;
			case'3':
				Rotacion();
				break;
			default:
				system("cls");
				cout << "Opcion no valida.";
			}
			break;
		case '5':
			Transformaciones();
			break;
		case'6':
			system("cls");
			MatrizxVector();
			break;
		case'7':
			RotacionCuaternios();
			break;
		case'8':
			cout << "Quiere salir de la calculadora?";
			cout << "\n\t1.-SI\t\t\t2.-NO";
			cout << "\nOpcion:";
			cin >> opcion;
			break;
		default:
			cout << "Opcion invalida.";
		}
	} while (opcion != '1');
	system("pause");
}

int Tamaño(char xy) {
	int n;
	bool checar;
	do {
		checar = true;
		if (xy == 'x') {
			cout << "Introduce el tamaño en x(renglones)";
		}
		else {
			cout << "Introduce el tamaño en y(columnas)";
		}
		n = atoi(ChecarDat(":"));
		if (!((n > 0) && (n < 11))) {
			checar = false;
		}
	} while (!checar);
	return n;
}

void LlenarMat(int x, int y,float mat[10][10]) {
	short i, j;
	i = 0;
	mat[y][x];
	while (i < y) {
		j = 0;
		while (j < x) {
			gotoxy(1, 1);
			cout << "                                                    ";
			gotoxy(1, 1);
			mat[i][j] = atof(Checarnum("Ingresa el dato:"));
			gotoxy(3, 3);
			for (short n = 0; n <= i; n++) {
				cout << endl;
				for (short m = 0; m <= j; m++) {
					cout << mat[n][m] << "\t";
				}
			}
			j++;
		}
		i++;
	}
}

char* Checarnum(string Indicaciones) {
	char num[20];
	char numerador[20], denominador[20];
	int t,chdiv;
	float n1, n2,r;
	short p, men, div;
	bool checar;
	do {
		for (short i = 0; i < 20; i++) {
			numerador[i] = '\0';
			denominador[i] = '\0';
			num[i] = '\0';
		}
		checar = true;
		p = 0;
		men = 0;
		div = 0;
		cout << Indicaciones;
		cin >> num;
		t = strlen(num);
		for (short i = 0; i < t; i++) {
			if (!(isdigit(num[i]))) {
				if (num[i] == '.') {
					p++;
					if (p > 1) {
						checar = false;
					}
				}
				else if (num[i] == '-') {
					men++;
					if (men > 1) {
						checar = false;
					}
				}
				else if(num[i]=='/'){
					div++;
					if (div > 1) {
						checar = false;
					}
				}
				else {
					checar = false;
					break;
				}
			}
		}
	if (checar && div == 1) {
		for (short i = 0; i < t; i++) {
			if (num[i] == '/') {
				chdiv = i;
				break;
			}
		}
		for (short i = 0; i < chdiv; i++) {
			numerador[i] = num[i];
		}
		chdiv += 1;
		short i = 0;
		while (chdiv < t) {
			denominador[i] = num[chdiv];
			chdiv++;
			i++;
		}
		n1 = atof(numerador);
		n2 = atof(denominador);
		if (n2 != 0){
			r = n1 / n2;
		sprintf_s(num, "%f", r);
		}
		else {
			checar = false;
		}
	}
	if (checar) {
		for (int i = 0; i < t; i++) {
			if (num[i] == '.') {
				for (short j = i + 5; j < t; j++) {
					num[j] = '\0';
				}
				break;
			}
		}
	}
	} while (!checar);
	return num;
}

char* ChecarDat(string inst) {
	char num[15];
	bool checar=true;
	int t,pun,neg;
	short i;
	do {
		//gotoxy(0, 1);
		//cout << "                                ";
		//gotoxy(0, 1);
		cout << inst;
		cin >> num;
		checar = true;
		pun = 0;
		neg = 0;
		t = strlen(num);
		i = 0;
		while((i<t)&&(checar)){
			if (!(isdigit(num[i]))) {
				if (num[i] == '.') {
					pun++;
					if (pun > 1) {
						checar = false;
						
					}
				}
				if (num[i] == '-') {
					neg++;
					if (neg > 1) {
						checar = false;
					}
				}
				else {
					checar = false;
				}
			}
			i++;
		}
	} while (!checar);
	return num;
}

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void SumaMat(float mat1[10][10], int x1, int y1, float mat2[10][10], int x2, int y2, float op[10][10], string datos) {
	int i, j;
	if ((x1 == x2) && (y1 == y2)) {
		for (i = 0; i < y1; i++) {
			j = 0;
			while (j < x1) {
				op[i][j] = mat1[i][j] + mat2[i][j];
				j++;
			}
		}
		system("cls");
		cout << datos;
		for (short k = 0; k < y1; k++) {
			for (short n = 0; n < x1; n++) {
				cout << op[k][n] << "\t";
			}
			cout << endl;
		}
	}
	else {
		system("cls");
		cout << "Lo sentimos, la suma no pudo ser efectuada.";
	}
	system("pause>null");
}

void InvAd(float mat1[10][10], int x1, int y1, float mat2[10][10], int x2, int y2, float op[10][10]) {
	char an;
	system("cls");
	if ((x1 == x2) && (y1 == y2)) {
		cout << "Cual operacion quieres hacer?";
		cout << "\n1.-A+(-B).\n2.-B+(-A).";
		cin >> an;
		switch (an) {
		case '1':
			for (short i = 0; i < y2; i++) {
				for (short j = 0; j < x2; j++) {
					mat2[i][j] *= -1;
				}
			}
			break;
		case '2':
			for (short i = 0; i < y1; i++) {
				for (short j = 0; j < x1; j++) {
					mat1[i][j] *= -1;
				}
			}
			break;
		default:
			cout << "\nOpcion no valida.";
		}
		if (an == '1' || an == '2')
			SumaMat(mat1, x1, y1, mat2, x2, y2, op, "El inverso aditivo es:\n");
	}
	else {
		cout << "\nNo se puede efectuar el inverso aditivo.";
	system("pause");
	}
}

void MultiMat(float mat1[10][10], int x1, int y1, float mat2[10][10], int x2, int y2, float op[10][10]) {
	short i, j, k, v, n, m;
		for (short i = 0; i < 10; i++) {
			for (short j = 0; j < 10; j++) {
				op[i][j] = 0;
			}
		}
	if (x1 == y2) {
		system("cls");
		for (i = 0; i < y1; i++) {
			for (j = 0; j < x2; j++) {
				for (k = 0; k < y2; k++) {
					op[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		}
		cout << "La multiplicacion de las matrices es:\n";
		for (short k = 0; k < y1; k++) {
			for (short n = 0; n < x2; n++) {
				cout << op[k][n] << "\t";
			}
			cout << endl;
		}
	}
	else {
		system("cls");
		cout << "La multiplicacion no se puede efectuar.";
	}
	system("pause>null");
}

void Traslacion() {
	char op;
	short p = 0;
	int n;
	float x, y, z;
	system("cls");
	cout << "Introduce un nuevo punto:";
	x = atof(Checarnum("\nIntrouce la coordenada en x:"));
	y = atof(Checarnum("\nIntrouce la coordenada en y:"));
	z = atof(Checarnum("\nIntrouce la coordenada en z:"));
	LlenarNodosPPuntos(NULL, x, y, z);
	LlenarCopiaNodosPuntos(x, y, z);
	do {
		system("cls");
		cout << "Quiere introducir un nuevo punto?";
		cout << "\n1.-SI\t\t2.-NO\nOpcion:";
		cin >> op;
		system("cls");
		if (op != '2') {
			cout << "Introduce un nuevo punto:";
			x = atof(Checarnum("\nIntrouce la coordenada en x:"));
			y = atof(Checarnum("\nIntrouce la coordenada en y:"));
			z = atof(Checarnum("\nIntrouce la coordenada en z:"));
			LlenarNodosPPuntos(NULL, x, y, z);
			LlenarCopiaNodosPuntos(x, y, z);
			system("cls");
		}
	} while (op != '2');
		system("cls");
		cout << "Traslacion:";
		x = atof(Checarnum("\nIntroduce la traslacion de la figura en x:"));
		system("cls");
		y = atof(Checarnum("\nIntroduce la traslacion de la figura en y:"));
		system("cls");
		z = atof(Checarnum("\nIntroduce la traslacion de la figura en z:"));
		system("cls");
		while (aux->PPrev != 0) {
			aux->x = aux->x + x;
			aux->y = aux->y + y;
			aux->z = aux->z + z;
			aux = aux->PPrev;
		}
		aux->x = aux->x + x;
		aux->y = aux->y + y;
		aux->z = aux->z + z;
		cout << "La figura trasladada es:\n";
		auxC = InicioC;
		while (aux->PSig != 0) {
			p++;
			cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
			cout << "El punto #" << p << " trasladado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
			aux = aux->PSig;
			auxC = auxC->PSig;
		}
		p++;
		cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
		cout << "El punto #" << p << " trasladado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
		system("pause");
		BorrarNodos();
		BorrarNodosC();
}

void Escalamiento() {
	int n;
	short p = 0;
	float  x, y, z;
	char op;
	system("cls");
	cout << "Introduce un punto:";
	x = atof(Checarnum("\nIntrouce la coordenada en x:"));
	y = atof(Checarnum("\nIntrouce la coordenada en y:"));
	z = atof(Checarnum("\nIntrouce la coordenada en z:"));
	LlenarNodosPPuntos(NULL, x, y, z);
	LlenarCopiaNodosPuntos(x, y, z);
	do {
		system("cls");
		cout << "Quiere introducir un nuevo punto?";
		cout << "\n1.-SI\t\t2.-NO\nOpcion:";
		cin >> op;
		system("cls");
		if (op != '2') {
			x = atof(Checarnum("\nIntrouce la coordenada en x:"));
			y = atof(Checarnum("\nIntrouce la coordenada en y:"));
			z = atof(Checarnum("\nIntrouce la coordenada en z:"));
			LlenarNodosPPuntos(NULL, x, y, z);
			LlenarCopiaNodosPuntos(x, y, z);
			system("cls");
		}
	} while (op != '2');
		system("cls");
		x = atof(Checarnum("\nIntroduce la escala de la figura en x:"));
		system("cls");
		y = atof(Checarnum("\nIntroduce la escala de la figura en y:"));
		system("cls");
		z = atof(Checarnum("\nIntroduce la escala de la figura en z:"));
		system("cls");
		while (aux->PPrev != 0) {
			aux->x = aux->x * x;
			aux->y = aux->y * y;
			aux->z = aux->z * z;
			aux = aux->PPrev;
		}
		aux->x = aux->x * x;
		aux->y = aux->y * y;
		aux->z = aux->z * z;
		cout << "La figura escalada es:\n";
		auxC = InicioC;
		while (aux->PSig != 0) {
			p++;
			cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
			cout << "El punto #" << p << " escalado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
			aux = aux->PSig;
			auxC = auxC->PSig;
		}
		p++;
		cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
		cout << "El punto #" << p << " escalado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
		BorrarNodos();
		BorrarNodosC();
	system("pause>null");
}

void Transformaciones() {
	char opc, eje, op;
	float x = 0, y = 0, z = 0;
	short cant = 0;
	system("cls");
	cout << "Introduce un punto:";
	x = atof(Checarnum("\nIntrouce la coordenada en x:"));
	y = atof(Checarnum("\nIntrouce la coordenada en y:"));
	z = atof(Checarnum("\nIntrouce la coordenada en z:"));
	LlenarCopiaNodosPuntos(x, y, z);
	system("cls");
	do {
		cout << "Quiere introducir un nuevo punto?";
		cout << "\n1.-SI\t\t2.-NO\nOpcion:";
		cin >> op;
		system("cls");
		if (op != '2') {
			x = atof(Checarnum("\nIntrouce la coordenada en x:"));
			y = atof(Checarnum("\nIntrouce la coordenada en y:"));
			z = atof(Checarnum("\nIntrouce la coordenada en z:"));
			LlenarCopiaNodosPuntos(x, y, z);
			system("cls");
		}
	} while (op != '2');
	do {
		system("cls");
		cout << "Selecciona la operacion siguiente:\n";
		cout << "1.-Traslacion.\n";
		cout << "2.-Escalamiento.\n";
		cout << "3.-Rotacion.\n";
		cout << "4.-Salir.\n";
		cout << "Opcion:";
		cin >> opc;
		switch (opc) {
		case '1':
			system("cls");
			cout << "Traslacion.\n";
			x = atof(Checarnum("\nIntrouce la coordenada en x:"));
			y = atof(Checarnum("\nIntrouce la coordenada en y:"));
			z = atof(Checarnum("\nIntrouce la coordenada en z:"));
			LlenarNodos(opc, x, y, z);
			cant++;
			break;
		case '2':
			system("cls");
			cout << "Escalamiento.\n";
			x = atof(Checarnum("\nIntrouce la coordenada en x:"));
			y = atof(Checarnum("\nIntrouce la coordenada en y:"));
			z = atof(Checarnum("\nIntrouce la coordenada en z:"));
			LlenarNodos(opc, x, y, z);
			cant++;
			break;
		case '3':
			system("cls");
			cout << "Rotacion.\n";
			do {
				system("cls");
				cout << "Introduce el eje para rotar:";
				cin >> eje;
				eje = toupper(eje);
			} while (eje != 'X' && eje != 'Y' && eje != 'Z');
			if (eje == 'X') {
				x = 1;
			}
			else if (eje == 'Y') {
				x = 2;
			}
			else {
				x = 3;
			}
			y = atof(Checarnum("\nIntroduce los grados a rotar:"));
			z = 0;
			LlenarNodos(opc, x, y, z);
			cant++;
			break;
		default:
			cout << "Quiere seguir agregando transformaciones?\n";
			cout << "1.-Si\t\t\t2.-No\nOpcion:";
			cin >> opc;
			if (opc == '1') {
				opc = '5';
			}
			else {
				opc = '4';
			}
			break;
			break;
		}
	} while (opc != '4');
	MatCompuesta(cant);
}

void LlenarNodos(char op, float x, float y, float z) {
	if (Inicio == 0) {
		Inicio = new Nodo;
		aux = Inicio;
		aux->PPrev = NULL;
		aux->opc = op;
		aux->x = x;
		aux->y = y;
		aux->z = z;
	}
	else {
		while (aux->PSig != 0) {
			aux = aux->PSig;
		}
		aux->PSig = new Nodo;
		aux->PSig->PPrev = aux;
		aux = aux->PSig;
		aux->opc = op;
		aux->x = x;
		aux->y = y;
		aux->z = z;
	}
	aux->PSig = NULL;
}

void MatCompuesta(short cantidad) {
	short p = 0;
	short i, j, k, v, n;
	float Mat1[4][4] = { '\0' }, Mat2[4][4] = { '\0' }, MatComp[4][4] = { '\0' };
	float x, y, z;
	char op, opct;
	if (cantidad > 1) {
		opct = aux->opc;
		switch (opct) {

		case '1':
			Mat1[0][0] = 1;
			Mat1[0][3] = aux->x;
			Mat1[1][1] = 1;
			Mat1[1][3] = aux->y;
			Mat1[2][2] = 1;
			Mat1[2][3] = aux->z;
			Mat1[3][3] = 1;
			break;
		case '2':
			Mat1[0][0] = aux->x;
			Mat1[1][1] = aux->y;
			Mat1[2][2] = aux->z;
			Mat1[3][3] = 1;
			break;
		case '3':
			if (aux->x == 1) op = '1';
			if (aux->x == 2) op = '2';
			else op = '3';
			switch (op) {
			case '1':
				Mat1[0][0] = 1;
				Mat1[1][1] = cos(aux->y / 180 * 3.1415);
				Mat1[1][2] = -sin(aux->y / 180 * 3.1415);
				Mat1[2][1] = sin(aux->y / 180 * 3.1415);
				Mat1[2][2] = cos(aux->y / 180 * 3.1415);
				Mat1[3][3] = 1;
				break;
			case '2':
				Mat1[0][0] = cos(aux->y / 180 * 3.1415);
				Mat1[1][1] = 1;
				Mat1[0][2] = sin(aux->y / 180 * 3.1415);
				Mat1[2][0] = -sin(aux->y / 180 * 3.1415);
				Mat1[2][2] = cos(aux->y / 180 * 3.1415);
				Mat1[3][3] = 1;
				break;
			case '3':
				Mat1[0][0] = cos(aux->y / 180 * 3.1415);
				Mat1[0][1] = -sin(aux->y / 180 * 3.1415);
				Mat1[1][0] = sin(aux->y / 180 * 3.1415);
				Mat1[1][1] = cos(aux->y / 180 * 3.1415);
				Mat1[2][2] = 1;
				Mat1[3][3] = 1;
				break;
			}
			break;
		}
		aux = aux->PPrev;
		opct = aux->opc;
		switch (opct) {
		case '1':
			Mat2[0][0] = 1;
			Mat2[0][3] = aux->x;
			Mat2[1][1] = 1;
			Mat2[1][3] = aux->y;
			Mat2[2][2] = 1;
			Mat2[2][3] = aux->z;
			Mat2[3][3] = 1;
			break;
		case '2':
			Mat2[0][0] = aux->x;
			Mat2[1][1] = aux->y;
			Mat2[2][2] = aux->z;
			Mat2[3][3] = 1;
			break;
		case '3':
			if (aux->x == 1) op = '1';
			if (aux->x == 2) op = '2';
			else op = '3';
			switch (op) {
			case '1':
				Mat2[0][0] = 1;
				Mat2[1][1] = cos(aux->y / 180 * 3.1415);
				Mat2[1][2] = -sin(aux->y / 180 * 3.1415);
				Mat2[2][1] = sin(aux->y / 180 * 3.1415);
				Mat2[2][2] = cos(aux->y / 180 * 3.1415);
				Mat2[3][3] = 1;
				break;
			case '2':
				Mat2[0][0] = cos(aux->y / 180 * 3.1415);
				Mat2[1][1] = 1;
				Mat2[0][2] = sin(aux->y / 180 * 3.1415);
				Mat2[2][0] = -sin(aux->y / 180 * 3.1415);
				Mat2[2][2] = cos(aux->y / 180 * 3.1415);
				Mat2[3][3] = 1;
				break;
			case '3':
				Mat2[0][0] = cos(aux->y / 180 * 3.1415);
				Mat2[0][1] = -sin(aux->y / 180 * 3.1415);
				Mat2[1][0] = sin(aux->y / 180 * 3.1415);
				Mat2[1][1] = cos(aux->y / 180 * 3.1415);
				Mat2[2][2] = 1;
				Mat2[3][3] = 1;
				break;
			}
			break;
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				for (k = 0; k < 4; k++) {
					MatComp[i][j] += Mat1[i][k] * Mat2[k][j];
				}
			}
		}
		system("cls");
		if (aux->PPrev != 0) {
			aux = aux->PPrev;
			do {
				for (i = 0; i < 4; i++) {
					for (j = 0; j < 4; j++) {
						Mat2[i][j] = 0;
					}
				}
				for (i = 0; i < 4; i++) {
					for (j = 0; j < 4; j++) {
						Mat1[i][j] = MatComp[i][j];
					}
				}
				for (i = 0; i < 4; i++) {
					for (j = 0; j < 4; j++) {
						MatComp[i][j] = 0;
					}
				}
				opct = aux->opc;
				switch (opct) {
				case '1':
					Mat2[0][0] = 1;
					Mat2[0][3] = aux->x;
					Mat2[1][1] = 1;
					Mat2[1][3] = aux->y;
					Mat2[2][2] = 1;
					Mat2[2][3] = aux->z;
					Mat2[3][3] = 1;
					break;
				case '2':
					Mat2[0][0] = aux->x;
					Mat2[1][1] = aux->y;
					Mat2[2][2] = aux->z;
					Mat2[3][3] = 1;
					break;
				case '3':
					if (aux->x == 1) op = '1';
					if (aux->x == 2) op = '2';
					else op = '3';
					switch (op) {
					case '1':
						Mat2[0][0] = 1;
						Mat2[1][1] = cos(aux->y / 180 * 3.1415);
						Mat2[1][2] = -sin(aux->y / 180 * 3.1415);
						Mat2[2][1] = sin(aux->y / 180 * 3.1415);
						Mat2[2][2] = cos(aux->y / 180 * 3.1415);
						Mat2[3][3] = 1;
						break;
					case '2':
						Mat2[0][0] = cos(aux->y / 180 * 3.1415);
						Mat2[1][1] = 1;
						Mat2[0][2] = sin(aux->y / 180 * 3.1415);
						Mat2[2][0] = -sin(aux->y / 180 * 3.1415);
						Mat2[2][2] = cos(aux->y / 180 * 3.1415);
						Mat2[3][3] = 1;
						break;
					case '3':
						Mat2[0][0] = cos(aux->y / 180 * 3.1415);
						Mat2[0][1] = -sin(aux->y / 180 * 3.1415);
						Mat2[1][0] = sin(aux->y / 180 * 3.1415);
						Mat2[1][1] = cos(aux->y / 180 * 3.1415);
						Mat2[2][2] = 1;
						Mat2[3][3] = 1;
						break;
					}
				}
				for (i = 0; i < 4; i++) {
					for (j = 0; j < 4; j++) {
						for (k = 0; k < 4; k++) {
							MatComp[i][j] += Mat1[i][k] * Mat2[k][j];
						}
					}
				}
				if (aux->PPrev != 0) {
					aux = aux->PPrev;
				}
				else {
					break;
				}
			} while (aux->PPrev != 0);
			cout << "Matriz compuesta:";
			for (short i = 0; i < 4; i++) {
				cout << endl;
				for (short j = 0; j < 4; j++) {
					MatComp[i][j] = ChecarDecimales(MatComp[i][j]);
					cout << MatComp[i][j] << "\t";
				}
			}
			system("pause>null");
			auxC = InicioC;
			cout << "\nLos puntos transformados son:\n";
			while (auxC->PSig != 0) {
				p++;
				x = auxC->x;
				y = auxC->y;
				z = auxC->z;
				cout << "La punto #" << p << " original es : " << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
				auxC->x = (MatComp[0][0] * x) + (MatComp[0][1] * y) + (MatComp[0][2] * z) + (MatComp[0][3] * 1);
				auxC->y = (MatComp[1][0] * x) + (MatComp[1][1] * y) + (MatComp[1][2] * z) + (MatComp[1][3] * 1);
				auxC->z = (MatComp[2][0] * x) + (MatComp[2][1] * y) + (MatComp[2][2] * z) + (MatComp[2][3] * 1);
				aux->x = ChecarDecimales(aux->x);
				aux->y = ChecarDecimales(aux->y);
				aux->z = ChecarDecimales(aux->z);
				cout << "El punto #" << p << " transformado es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
				auxC = auxC->PSig;
			}
			p++;
			x = auxC->x;
			y = auxC->y;
			z = auxC->z;
			cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
			auxC->x = (MatComp[0][0] * x) + (MatComp[0][1] * y) + (MatComp[0][2] * z) + (MatComp[0][3] * 1);
			auxC->y = (MatComp[1][0] * x) + (MatComp[1][1] * y) + (MatComp[1][2] * z) + (MatComp[1][3] * 1);
			auxC->z = (MatComp[2][0] * x) + (MatComp[2][1] * y) + (MatComp[2][2] * z) + (MatComp[2][3] * 1);
			aux->x = ChecarDecimales(aux->x);
			aux->y = ChecarDecimales(aux->y);
			aux->z = ChecarDecimales(aux->z);
			cout << "El punto #" << p << " transformado es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
			system("pause>null");
			BorrarNodos();
			BorrarNodosC();
		}
		else {
		cout << "Matriz compuesta:";
		for(short i = 0; i < 4; i++) {
			cout << endl;
			for (short j = 0; j < 4; j++) {
				MatComp[i][j] = ChecarDecimales(MatComp[i][j]);
				cout << MatComp[i][j] << "\t";
			}
		}
		auxC = InicioC;
		cout << "\nLos puntos transformados son:\n";
		short p = 0;
		while (auxC->PSig != 0) {
			p++;
			x = auxC->x;
			y = auxC->y;
			z = auxC->z;
			cout << "La punto #" << p << " original es : " << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
			auxC->x = (MatComp[0][0] * x) + (MatComp[0][1] * y) + (MatComp[0][2] * z) + (MatComp[0][3]*1);
			auxC->y = (MatComp[1][0] * x) + (MatComp[1][1] * y) + (MatComp[1][2] * z) + (MatComp[1][3]*1);
			auxC->z = (MatComp[2][0] * x) + (MatComp[2][1] * y) + (MatComp[2][2] * z) + (MatComp[2][3]*1);
			cout << "El punto #" << p << " transformado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
			auxC = auxC->PSig;
		}
		p++;
		x = auxC->x;
		y = auxC->y;
		z = auxC->z;
		cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
		auxC->x = (MatComp[0][0] * x) + (MatComp[0][1] * y) + (MatComp[0][2] * z) + (MatComp[0][3] * 1);
		auxC->y = (MatComp[1][0] * x) + (MatComp[1][1] * y) + (MatComp[1][2] * z) + (MatComp[1][3] * 1);
		auxC->z = (MatComp[2][0] * x) + (MatComp[2][1] * y) + (MatComp[2][2] * z) + (MatComp[2][3] * 1);
		aux->x = ChecarDecimales(aux->x);
		aux->y = ChecarDecimales(aux->y);
		aux->z = ChecarDecimales(aux->z);
		cout << "El punto #" << p << " transformado es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
		system("pause>null");
		BorrarNodos();
		BorrarNodosC();
		}
	}
	else {
	cout << "\nLa matriz compuesta debe tener al menos 2 transformaciones.";
	system("pause");
	}
	system("pause");
}

void Rotacion() {
	char num[15], op;
	int n = 0, t;
	char eje;
	float grad, x, y, z;
	float mat[4][4], punto[4];
	short p = 0;
	system("cls");
	cout << "Introcuce un punto:";
	x = atof(Checarnum("\nIntrouce la coordenada en x:"));
	y = atof(Checarnum("\nIntrouce la coordenada en y:"));
	z = atof(Checarnum("\nIntrouce la coordenada en z:"));
	LlenarNodosPPuntos(NULL, x, y, z);
	LlenarCopiaNodosPuntos(x, y, z);
	do {
		system("cls");
		cout << "Quiere introducir un nuevo punto?";
		cout << "\n1.-SI\t\t2.-NO\nOpcion:";
		cin >> op;
		system("cls");
		if (op != '2') {
			x = atof(Checarnum("\nIntrouce la coordenada en x:"));
			y = atof(Checarnum("\nIntrouce la coordenada en y:"));
			z = atof(Checarnum("\nIntrouce la coordenada en z:"));
			LlenarNodosPPuntos(NULL, x, y, z);
			LlenarCopiaNodosPuntos(x, y, z);
			system("cls");
		}
	} while (op != '2');
		do {
			system("cls");
			cout << "Introduce el eje para rotar:";
			cin >> eje;
			eje = toupper(eje);
		} while (eje != 'X' && eje != 'Y' && eje != 'Z');
		grad = atof(Checarnum("\nIntroduce los grados a rotar:"));
		for (int h = 0; h < 4; h++) {
			for (int k = 0; k < 4; k++) {
				mat[h][k] = 0;
			}
		}
		switch (eje) {
		case 'X':
			mat[0][0] = 1;
			mat[1][1] = cos(grad / 180 * 3.1415);
			mat[1][2] = -sin(grad / 180 * 3.1415);
			mat[2][1] = sin(grad / 180 * 3.1415);
			mat[2][2] = cos(grad / 180 * 3.1415);
			mat[3][3] = 1;
			break;
		case 'Y':
			mat[0][0] = cos(grad / 180 * 3.1415);
			mat[1][1] = 1;
			mat[0][2] = sin(grad / 180 * 3.1415);
			mat[2][0] = -sin(grad / 180 * 3.1415);
			mat[2][2] = cos(grad / 180 * 3.1415);
			mat[3][3] = 1;
			break;
		case 'Z':
			mat[0][0] = cos(grad / 180 * 3.1415);
			mat[0][1] = -sin(grad / 180 * 3.1415);
			mat[1][0] = sin(grad / 180 * 3.1415);
			mat[1][1] = cos(grad / 180 * 3.1415);
			mat[2][2] = 1;
			mat[3][3] = 1;
			break;
		default:
			cout << "El eje no existe.";
		}
		while (aux->PPrev != 0) {
			punto[0] = aux->x;
			punto[1] = aux->y;
			punto[2] = aux->z;
			punto[3] = 1;
			aux->x = (mat[0][0] * punto[0]) + (mat[0][1] * punto[1]) + (mat[0][2] * punto[2]) + (mat[0][3] * punto[3]);
			aux->y = (mat[1][0] * punto[0]) + (mat[1][1] * punto[1]) + (mat[1][2] * punto[2]) + (mat[1][3] * punto[3]);
			aux->z = (mat[2][0] * punto[0]) + (mat[2][1] * punto[1]) + (mat[2][2] * punto[2]) + (mat[2][3] * punto[3]);
			aux = aux->PPrev;
		}
		punto[0] = aux->x;
		punto[1] = aux->y;
		punto[2] = aux->z;
		punto[3] = 1;
		aux->x = (mat[0][0] * punto[0]) + (mat[0][1] * punto[1]) + (mat[0][2] * punto[2]) + (mat[0][3] * punto[3]);
		aux->y = (mat[1][0] * punto[0]) + (mat[1][1] * punto[1]) + (mat[1][2] * punto[2]) + (mat[1][3] * punto[3]);
		aux->z = (mat[2][0] * punto[0]) + (mat[2][1] * punto[1]) + (mat[2][2] * punto[2]) + (mat[2][3] * punto[3]);
		cout << "Los puntos rotados son:\n";
		auxC = InicioC;
		while (aux->PSig != 0) {
			p++;
			cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
			aux->x = ChecarDecimales(aux->x);
			aux->y = ChecarDecimales(aux->y);
			aux->z = ChecarDecimales(aux->z);
			cout << "El punto #" << p << " rotado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
			aux = aux->PSig;
			auxC = auxC->PSig;
		}
		p++;
		cout << "El punto #" << p << " original es : (" << auxC->x << "," << auxC->y << "," << auxC->z << ")\n";
		aux->x = ChecarDecimales(aux->x);
		aux->y = ChecarDecimales(aux->y);
		aux->z = ChecarDecimales(aux->z);
		cout << "El punto #" << p << " rotado es : (" << aux->x << "," << aux->y << "," << aux->z << ")\n";
		BorrarNodosC();
		BorrarNodos();
	system("pause>null");
}

void LlenarNodosPPuntos(char op, float x, float y, float z) {
	if (Inicio == 0) {
		Inicio = new Nodo;
		aux = Inicio;
		aux->PPrev = NULL;
		aux->opc = op;
		aux->x = x;
		aux->y = y;
		aux->z = z;
	}
	else {
		while (aux->PSig != 0) {
			aux = aux->PSig;
		}
		aux->PSig = new Nodo;
		aux->PSig->PPrev = aux;
		aux = aux->PSig;
		aux->opc = op;
		aux->x = x;
		aux->y = y;
		aux->z = z;
	}
	aux->PSig = NULL;
}

void LlenarCopiaNodosPuntos(float x, float y, float z) {
	if (InicioC == 0) {
		InicioC = new Nodo;
		auxC = InicioC;
		auxC->PPrev = NULL;
		auxC->x = x;
		auxC->y = y;
		auxC->z = z;
	}
	else {
		while (auxC->PSig != 0) {
			auxC = auxC->PSig;
		}
		auxC->PSig = new Nodo;
		auxC->PSig->PPrev = auxC;
		auxC = auxC->PSig;
		auxC->x = x;
		auxC->y = y;
		auxC->z = z;
	}
	auxC->PSig = NULL;
}

void MatrizxVector() {
	float x, y, z, xr, yr, zr;
	float Mat[10][10] = { '\0' };
	x = atof(Checarnum("Introuce la coordenada del vector en x:"));
	system("cls");
	y = atof(Checarnum("Introuce la coordenada del vector en y:"));
	system("cls");
	z = atof(Checarnum("Introuce la coordenada del vector en z:"));
	system("cls");
	cout << "Matriz 4x4.";
	LlenarMat(4, 4, Mat);
	xr = (Mat[0][0] * x) + (Mat[0][1] * y) + (Mat[0][2] * z) + (Mat[0][3] * 1);
	yr = (Mat[1][0] * x) + (Mat[1][1] * y) + (Mat[1][2] * z) + (Mat[1][3] * 1);
	zr = (Mat[2][0] * x) + (Mat[2][1] * y) + (Mat[2][2] * z) + (Mat[2][3] * 1);
	float extra = (Mat[3][0] * x) + (Mat[3][1] * y) + (Mat[3][2] * z) + (Mat[3][3] * 1);
	cout << "\nEl vector original es: (" << x << "," << y << "," << z << ")";
	xr = ChecarDecimales(xr);
	yr = ChecarDecimales(yr);
	zr = ChecarDecimales(zr);
	extra = ChecarDecimales(extra);
	cout << "\nEl vector multiplicado es: (" << xr << "," << yr << "," << zr << "," << ")";
	system("pause>null");
	system("cls");
}

void BorrarNodos() {
	aux = Inicio;
	while (Inicio != NULL) {
		aux = aux->PSig;
		delete Inicio;
		Inicio = aux;
	}
	delete Inicio;
}

//Checarla cuando nos diga que como se hace
void RotacionCuaternios() {
	float CuatMat[3][3];
	float x, y, z, vx, vy, vz, angulo, s, a, b, c, r, aux;
	char op, decimales[10];
	system("cls");
	cout << "Introducir un punto:";
	x = atof(Checarnum("\nIntrouce la coordenada en i:"));
	y = atof(Checarnum("\nIntrouce la coordenada en j:"));
	z = atof(Checarnum("\nIntrouce la coordenada en k:"));
	LlenarCopiaNodosPuntos(x, y, z);
	do {
		system("cls");
		cout << "Quiere introducir un nuevo punto?";
		cout << "\n1.-SI\t\t2.-NO\nOpcion:";
		cin >> op;
		system("cls");
		if (op != '2') {
			x = atof(Checarnum("\nIntrouce la coordenada en i:"));
			y = atof(Checarnum("\nIntrouce la coordenada en j:"));
			z = atof(Checarnum("\nIntrouce la coordenada en k:"));
			LlenarCopiaNodosPuntos(x, y, z);
			system("cls");
		}
	} while (op != '2');
	cout << "Introduce el vector.\n";
	vx = atof(Checarnum("\nIntrouce la coordenada del vector en i:"));
	system("cls");
	cout << "Introduce el vector.\n";
	vy = atof(Checarnum("\nIntrouce la coordenada del vector en j:"));
	system("cls");
	cout << "Introduce el vector.\n";
	vz = atof(Checarnum("\nIntrouce la coordenada del vector en k:"));
	system("cls");
	angulo= atof(Checarnum("\nIntrouce el angulo a rotar:"));
	system("cls");
	angulo /= 2;
	s = cos(angulo / 180 * 3.1415);
	r=(sqrt((vx * vx) + (vy * vy) + (vz * vz)));
	x = vx / r;
	y = vy / r;
	z = vz / r;
	a = x * sin(angulo / 180 * 3.1415);
	b = y * sin(angulo / 180 * 3.1415);
	c = z * sin(angulo / 180 * 3.1415);
	aux = 100 * a;
	a = aux * 1.0 / 100;
	aux = 100 * b;
	b = aux * 1.0 / 100;
	aux = 100 * c;
	c = aux * 1.0 / 100;
	CuatMat[0][0] = 1 - (2 * pow(b,2)) - (2 * pow(c,2));
	CuatMat[0][1] = (2 * a * b) - (2 * s * c);
	CuatMat[0][2] = (2 * a * c) + (2 * s * b);
	CuatMat[1][0] = (2 * a * b) + (2 * s * c);
	CuatMat[1][1] = 1 - (2 * pow(a,2)) - (2 * pow(c,2));
	CuatMat[1][2] = (2 * b * c) - (2 * s * a);
	CuatMat[2][0] = (2 * a * c) - (2 * s * b);
	CuatMat[2][1] = (2 * b * c) + (2 * s * a);
	CuatMat[2][2] = 1 - (2 * pow(a,2)) - (2 * pow(b,2));
	short p = 0;
	auxC = InicioC;
	while (auxC->PSig != 0) {
		p++;
		x = auxC->x;
		y = auxC->y;
		z = auxC->z;
		cout << "La punto #" << p << " original es : <" << auxC->x << "i," << auxC->y << "j," << auxC->z << "k>\n";
		auxC->x = (CuatMat[0][0] * x) + (CuatMat[0][1] * y) + (CuatMat[0][2] * z);
		auxC->y = (CuatMat[1][0] * x) + (CuatMat[1][1] * y) + (CuatMat[1][2] * z);
		auxC->z = (CuatMat[2][0] * x) + (CuatMat[2][1] * y) + (CuatMat[2][2] * z);
		auxC->x = ChecarDecimales(auxC->x);
		auxC->y = ChecarDecimales(auxC->y);
		auxC->z = ChecarDecimales(auxC->z);
		cout << "El punto #" << p << " rotado es : <" << auxC->x << "i," << auxC->y << "j," << auxC->z << "k>\n";
		auxC = auxC->PSig;
	}
	p++;
	x = auxC->x;
	y = auxC->y;
	z = auxC->z;
	cout << "El punto #" << p << " original es : <" << auxC->x << "i," << auxC->y << "j," << auxC->z << "k>\n";
	auxC->x = (CuatMat[0][0] * x) + (CuatMat[0][1] * y) + (CuatMat[0][2] * z);
	auxC->y = (CuatMat[1][0] * x) + (CuatMat[1][1] * y) + (CuatMat[1][2] * z);
	auxC->z = (CuatMat[2][0] * x) + (CuatMat[2][1] * y) + (CuatMat[2][2] * z);
	auxC->x = ChecarDecimales(auxC->x);
	auxC->y = ChecarDecimales(auxC->y);
	auxC->z = ChecarDecimales(auxC->z);
	cout << "El punto #" << p << " rotado es : <"<< auxC->x << "i,"<< auxC->y << "j," << auxC->z << "k>\n";
	BorrarNodosC();
	system("pause>null");
}

void BorrarNodosC() {
	auxC = InicioC;
	while (InicioC != NULL) {
		auxC = auxC->PSig;
		delete InicioC;
		InicioC = auxC;
	}
	delete InicioC;
}

float ChecarDecimales(float num) {
	char decimales[20];
	sprintf_s(decimales, "%f", num);
	for (int i = 0; i < 20; i++) {
		if (decimales[i] == '.') {
			for (short j = i + 5; j < 20; j++) {
				decimales[j] = '0';
			}
			break;
		}
	}
	if (decimales[0] == '-' && decimales[1] == '0' && decimales[2] == '.'
		&& decimales[3] == '0' && decimales[4] == '0' && decimales[5]=='0' && decimales[6] == '0') {
		decimales[0] = '0';
		}
	num = atof(decimales);
	return num;
}

//void BorrarNodos2() {
//	Inicio = aux;
//	while (Inicio != NULL) {
//		aux = aux->PPrev;
//		delete Inicio;
//		Inicio = aux;
//	}
//	delete Inicio;
//}
