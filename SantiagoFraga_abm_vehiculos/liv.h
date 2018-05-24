
typedef struct
{
    int idDuenio;
    char nombre[15];
    char apellido[15];
    char direccion[30];
    int tarjetaCredito;
    int estado;
}eDuenio;

typedef struct
{
    char patente[10];
    int marca;
    int idDuenio;
    int horarioDeEntrada;
    int estado;
}eAutomovil;

int menu();
void inicializarClientes(eDuenio clientes[], int tamClientes);
int buscarLibre(eDuenio clientes[], int tamClientes);
int buscarIgual(eDuenio clientes[],int tamClientes, int idAux);
int altaDuenio(eDuenio clientes[], int tamClientes);
int BajaPersona(eDuenio lista[],int cant);

void inicializarIngresos(eAutomovil ingresos[], int tamIngresos);
int buscarEspacioLibre(eAutomovil ingresos[], int tamIngresos);
int buscarPatenteIgual(eAutomovil ingresos[],int tamIngresos, char patente[]);
void altaIngreso(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes);

void mostrarIngreso(eAutomovil ingreso, eDuenio clientes[], int tamClientes);
void mostrarVariosIngresos(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes);
int menuInformar();

void mostrarDuenio(eDuenio cliente);
void mostrarDuenios(eDuenio clientes[], int tamClientes);

void cargarClientes(eDuenio clientes[], int tamClientes);
void cargarIngresos(eAutomovil ingresos[], int tamIngresos);


void modificarDuenio(eDuenio clientes[], int tamClientes);
int calcularValorEstadia(int horaIngreso, int horaEgreso, int marca);
void egreso(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes);
void mostrarDueniosPorMarca(eDuenio clientes[], int tamClientes, eAutomovil ingresos[], int tamIngresos, int marca);
void recaudacionTotalPorMarca();
void recaudacionEstacionamiento();

void mostrarIngresosOrdenados(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes);
