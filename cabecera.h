using namespace std;
typedef struct{
	int DNI;
	string Apellidos;
	string Nombre;
	int Telefono;
}registro;
void nuevoElemento(registro agenda[], int n);
void leeRegistro(registro agenda[], int r);
void mostrarAgenda(registro agenda[], int n);
void elementosRepetidos(registro agenda[], int n);
void copiarVector(int A[], registro B[], int n);
int cuentaLetraInicial(registro agenda[], char letra, int n);
int mediaLetras(registro agenda[], int n);
bool buscaRegistro(registro agenda[], int dni, int n);
bool borrarElemento(registro agenda[], int dni, int n);