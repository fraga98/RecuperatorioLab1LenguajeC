
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liv.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int acumAlphaRomeo = 0;
int acumFerrari = 0;
int acumAudi = 0;
int acumOtros = 0;

/** Menu principal del ABM Estacionamiento.
 *
 * \return int retorna la opcion seleccionada.
 *
 */
int menu()
{
    int opcion;
    system("cls");
    printf("\n***ESTACIONAMIENTO***\n\n\n");
    printf("1- Alta Duenio\n");
    printf("2- Modificacion Duenio\n");
    printf("3- baja Duenio\n");
    printf("4- Ingreso de Automovil\n");
    printf("5- Egreso del Automovil\n");
    printf("6- Mostar Automovil\n");
    printf("7- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** Funcion para inicializar el array de clientes en estado -1.
 *
 * \param clientes[] eDuenio  array de clientes.
 * \param tamClientes int  tamaño del array de clientes.
 *
 */
void inicializarClientes(eDuenio clientes[], int tamClientes)
{
    for(int i = 0; i < tamClientes; i++)
    {
        clientes[i].estado = 0;
    }
}

/** Funcion para buscar un espacio libre en el array de clientes.
 *
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \return int devuelve la posicion libre dentro del array.
 *
 */
int buscarLibre(eDuenio clientes[], int tamClientes)
{
    int index = -1;
    for(int i = 0; i < tamClientes; i++)
    {
        if(clientes[i].estado == 0)
        {
            index=i;
            break;
        }
    }
    return index;
}

/** Funcion para buscar si hay el id ingresado, ya esta presente en el array.
 *
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \param idAux int id a comparar.
 * \return int devuelve -1 si el id a comparar esta en el array, sino, devuelve el indice del ultimo registro del array.
 *
 */
int buscarIgual(eDuenio clientes[],int tamClientes, int idAux)
{
    int IdTest = -1;

    for(int i = 0; i < tamClientes; i++)
    {
        if(clientes[i].idDuenio == idAux && clientes[i].estado == 1)
        {
           IdTest = i;
           break;
        }
    }
    return IdTest;
}


/** Agrega un cliente a el array de clientes.
 *
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamño de el array de clientes.
 *  \return int rslt devuelve si se realizo un alta. 0 no se realizo, 1 si se pudo realizar.
 */
int altaDuenio(eDuenio clientes[], int tamClientes)
{
    int rslt = -1;
    int index,auxId;
    eDuenio newDuenio;
    index = buscarLibre(clientes, tamClientes);

    if(index == -1)
    {
        printf("No hay lugar libre.\n");
        system("pause");
    } else
        {
            printf("Ingrese ID: ");
            fflush(stdin);
            scanf("%d", &auxId);

            if(buscarIgual(clientes,tamClientes, auxId)){

                newDuenio.idDuenio=auxId;
                printf("-----------------\n");
                printf("ingrese nombre: ");
                fflush(stdin);
                gets(newDuenio.nombre);
                while(strlen(newDuenio.nombre)>14)
                {
                    printf("Nombre demasiado largo!\nReingrese: ");
                    fflush(stdin);
                    gets(newDuenio.nombre);
                    printf("-----------------");
                }

                printf("-----------------\n");
                printf("ingrese apellido: ");
                fflush(stdin);
                gets(newDuenio.apellido);
                while(strlen(newDuenio.apellido)>14)
                {
                    printf("apellido demasiado largo!\nReingrese: ");
                    fflush(stdin);
                    gets(newDuenio.apellido);
                    printf("-----------------");
                }

                printf("-----------------\n");
                printf("ingrese Direccion: ");
                fflush(stdin);
                gets(newDuenio.direccion);
                while(strlen(newDuenio.direccion)>29)
                {
                    printf("Direccion demasiado larga!\nReingrese: ");
                    fflush(stdin);
                    gets(newDuenio.direccion);
                    printf("-----------------");
                }


                printf("\nIngrese Numero de Tarjeta de Credito: ");
                fflush(stdin);
                scanf("%d", &newDuenio.tarjetaCredito);

                while(newDuenio.tarjetaCredito < 1)
                {
                    printf("Nuemor de Tarjeta de Cretido no valida!\nReingrese: ");
                    fflush(stdin);
                    scanf("%d", &newDuenio.tarjetaCredito);
                    printf("-----------------\n");
                }
                printf("-----------------");
                newDuenio.estado = 1;
                clientes[index] = newDuenio;
                rslt = 1;

            }else
                {
                    printf("el ID ya fue ingresado!\n");
                }
        }
    return rslt;
}

int BajaPersona(eDuenio lista[],int cant)
{
    int indice=-1;
    float iDsolicitado;

    printf("\n");
    printf("Ingrese id de la persona que sea dar de baja: ");
    scanf("%f",&iDsolicitado);

    int i;
    for(i=0; i<cant; i++)
        {
            if (lista[i].idDuenio== iDsolicitado)
                {
                    indice=i;
                    break;
                }
        }

    return indice;
}
/** Funcion para inicializar el estado en -1 en el array de ingresos al estacionamiento.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 *
 */
void inicializarIngresos(eAutomovil ingresos[], int tamIngresos)
{
    for(int i = 0; i < tamIngresos; i++)
    {
        ingresos[i].estado = 0;
    }
}

/** Funcion para buscar un espacio libre en el array de ingresos al estacionamiento.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \return int devuelve la posicion libre dentro de el array
 *
 */
int buscarEspacioLibre(eAutomovil ingresos[], int tamIngresos)
{
    int index = -1;
    for(int i = 0; i < tamIngresos; i++)
    {
        if(ingresos[i].estado == 0)
        {
            index=i;
            break;
        }
    }
    return index;
}

/** Funcion para validar si hay 2 patentes iguales dentro de el array de ingresos.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \param patente[] char patente a comparar.
 * \return int retorna -1 si no hay coincidencia.
 *
 */
int buscarPatenteIgual(eAutomovil ingresos[],int tamIngresos, char patente[])
{
    int IdTest = -1;

    for(int i = 0; i < tamIngresos; i++)
    {
        if(strcmp(ingresos[i].patente,patente) == 0 && ingresos[i].estado == 1)
        {
           IdTest = i;
           break;
        }
    }
    return IdTest;
}

/** Agrega un nuevo ingreso a el array de ingresos.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamañño de el array de clientes.
 *
 */
void altaIngreso(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes)
{
    int index, auxId;
    char auxPatente[10];
    eAutomovil newAutomovil;
    index = buscarEspacioLibre(ingresos, tamIngresos);

    if(index == -1)
    {
        printf("No hay lugar libre");
    } else
        {
            printf("Ingrese Patente: ");
            fflush(stdin);
            gets(auxPatente);
            while(strlen(auxPatente)>9)
                {
                    printf("Patente demasiado largo!\nReingrese: ");
                    fflush(stdin);
                    gets(auxPatente);
                    printf("-----------------");
                }

            if(buscarPatenteIgual(ingresos,tamIngresos, auxPatente))
            {
                strcpy(newAutomovil.patente,auxPatente);

                printf("-----------------\n1.ALPHA_ROMEO\n2.FERRARI\n3.AUDI\n4.OTRO\nIngrese Marca: ");
                fflush(stdin);
                scanf("%d",&newAutomovil.marca);

                while(newAutomovil.marca!= 1 && newAutomovil.marca!= 2 && newAutomovil.marca!= 3 && newAutomovil.marca!= 4){
                    printf("\nMarca no valida\nReingrese: ");
                    fflush(stdin);
                    scanf("%d",&newAutomovil.marca);
                }
                printf("\n ");
                mostrarDuenios(clientes,tamClientes);
                printf("\n ");
                printf("\nIngrese id del Dueño: ");
                fflush(stdin);
                scanf("%d", &auxId);
                while(buscarIgual(clientes,tamClientes, auxId) == -1)
                {
                    printf("\nError......Reingrese id del Dueño: ");
                    fflush(stdin);
                    scanf("%d", &auxId);
                }
                newAutomovil.idDuenio = auxId;

                printf("\nIngrese el horario de entrada: ");
                fflush(stdin);
                scanf("%d", &newAutomovil.horarioDeEntrada);
                newAutomovil.estado=1;
                ingresos[index]=newAutomovil;

            }else
                {
                    printf("La patente ya fue ingresado!\n");
                }
        }//fin else
}


/** Funcion para modificar el numero de la tarjeta de cretito de un cliente.
 *
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño de el array de clientes.
 *
 */
void modificarDuenio(eDuenio clientes[], int tamClientes)
{

    int index, aux, respuesta;
    int auxTarj;


    mostrarDuenios(clientes,tamClientes);
    printf("ingrese ID del cliente a modificar: ");
    fflush(stdin);
    scanf("%d", &aux);

    index=buscarIgual(clientes,tamClientes,aux);

    if(index!=-1)
    {

        printf("\nIngrese el numero de la nueva tarjeta de credito:");
        fflush(stdin);
        scanf("%d",&auxTarj);
        while(auxTarj < 0 || auxTarj == clientes[index].tarjetaCredito)
        {
            printf("\nError.....Reingrese el numero de la nueva tarjeta de credito: ");
            fflush(stdin);
            scanf("%d",&auxTarj);
        }
        printf("-----------------\n");
        printf("Seguro que desea modificar a:\n");
        mostrarDuenio(clientes[index]);

        printf("Si=1/No=0\n");
        fflush(stdin);
        scanf("%d", &respuesta);

        while(respuesta!=0 && respuesta!=1)
        {
            printf("opcion no valida!\nReingrese: ");
            fflush(stdin);
            scanf("%d", &respuesta);
        }
        if(respuesta==1)
        {
            clientes[index].tarjetaCredito = auxTarj;


            printf("el  dueñio fue dado modificado con exito!");
        }else
            {
                printf("operacion cancelada!");
            }

    }else
        {
            printf("no se encontro la ID ingresada!!");
        }

}


/** Muestra el registro de un ingreso por pantalla.
 *
 * \param ingreso eAutomovil registro a mostrar.
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño de el array de clientes.
 *
 */
void mostrarIngreso(eAutomovil ingreso, eDuenio clientes[], int tamClientes)
{
    if(ingreso.estado == 1)
    {
        printf("\n%s\t\t", ingreso.patente);

        switch(ingreso.marca)
        {
            case 1:
                printf("ALPHA_ROMEO\t");
            break;
            case 2:
                printf("FERRARI\t\t");
            break;
            case 3:
                printf("AUDI\t\t");
            break;
            case 4:
                printf("OTRO\t\t");
            break;
        }

        printf("%d\t\t%dhs\t\t", ingreso.idDuenio, ingreso.horarioDeEntrada);

        for (int i = 0; i < tamClientes;i++)
        {
            if (ingreso.idDuenio == clientes[i].idDuenio)
            {
                printf("%s\t%s\t",&clientes[i].nombre,&clientes[i].apellido);
            }

        }

    }

}

/** Funcion para mostrar todos los ingresos.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamañño de el array de clientes.
 *
 */
void mostrarVariosIngresos(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes)
{
    int flag = 0;

    printf("PATENTE\t\tMARCA\t\tID_DUENIO\tHORA_INGRESO\tNOMBRE\tAPELLIDO\n");
    printf("-----------------------------------------------------------------------------------\n");

    for(int i=0;i<tamIngresos;i++)
    {
        mostrarIngreso(ingresos[i],clientes,tamClientes);

        if(ingresos[i].estado==0)
        {
            flag++;
        }
    }

    if(flag==tamIngresos)
    {
        printf("No hay Ingresos para mostrar!\n");
    }else
        {
            printf("\nLugares disponibles: %d\n", flag);
        }

}

/** Menu para elegir el tipo de informe a mostrar.
 *
 * \return int retorna la opcion elegida.
 *
 */
int menuInformar()
{
    int opcion;
    system("cls");
    printf("\n***Informar***\n\n\n");
    printf("1- Listado de autos estacionados con sus dueños, ordenado por hora de entrada y patente.\n");
    printf("2- Todos los propietarios de autos de marca AUDI.\n");
    printf("3- Recaudacion total por marca.\n");
    printf("4- Recaudacion total del estacionamiento.\n");
    printf("5- Salir\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/** Funcion para mostrar un registro de un array de clientes por pantalla..
 *
 * \param cliente eDuenio array de clientes.
 *
 */
void mostrarDuenio(eDuenio cliente)
{
    if(cliente.estado == 1)
    {
        printf("\n%d\t\t%s\t%s\t\t%s\t%d\n", cliente.idDuenio,cliente.nombre,cliente.apellido,cliente.direccion,cliente.tarjetaCredito);
    }
}

/** Funcion para mostrar el array de clientes por pantalla.
 *
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño de el array de clientes.
 *
 */
void mostrarDuenios(eDuenio clientes[], int tamClientes)
{
    int flag = 0;

    printf("ID_DUENIO\tNOMBRE\tAPELLIDO\tDIRECCION\tNUM_TARJETA_CREDITO\n");
    printf("-------------------------------------------------------------\n");

    for(int i=0;i<tamClientes;i++)
    {
        mostrarDuenio(clientes[i]);

        if(clientes[i].estado==0)
        {
            flag++;
        }
    }

    if(flag==tamClientes)
    {
        printf("No hay Dueños para mostrar!\n");
    }else
        {
            printf("\nLugares disponibles: %d\n", flag);
        }

}

/** Funcion para hardcodear el array de clientes.
 *
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño de el array de clientes.
 *
 */
void cargarClientes(eDuenio clientes[], int tamClientes)
{
    int id[] = {100,200,300};
    char nombre [][15] = {"Juan ","Martin","Franco"};
    char apellido [][15] = {"Perez","Torcha","Ramirez"};
    char direccion [][30] = {"Mitre 750","Blegrano 400","Puan 200"};
    int numTarj[] = {2312321,654654645,32434};
    int estado[] = {1,1,1};

    for(int i = 0; i < tamClientes; i++)
    {
        clientes[i].idDuenio = id[i];
        strcpy(clientes[i].nombre,nombre[i]);
        strcpy(clientes[i].apellido,apellido[i]);
        strcpy(clientes[i].direccion,direccion[i]);
        clientes[i].tarjetaCredito = numTarj[i];
        clientes[i].estado = estado[i];
    }

    //mostrarDuenios(clientes,tamClientes);
    //system("pause");
}

/** Funcion para hardcodear el array de ingresos.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 *
 */
void cargarIngresos(eAutomovil ingresos[], int tamIngresos)
{
    char auxPatente[][10]= {"LKJ707","OIU344","SXZ694"};
    int auxMarca[] = {1,3,4};
    int auxIdDuenio[] = {100,200,300};
    int auxHorarioDeEntrada[] = {15,8,10};
    int auxEstado[] = {1,1,1};

    for(int i = 0; i < tamIngresos; i++)
    {
        strcpy(ingresos[i].patente,auxPatente[i]);
        ingresos[i].marca = auxMarca[i];
        ingresos[i].idDuenio = auxIdDuenio[i];
        ingresos[i].horarioDeEntrada = auxHorarioDeEntrada[i];
        ingresos[i].estado = auxEstado[i];
    }
}

/** Funcion para generar un ticket de salida de el estacionamiento,
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamañño de el array de clientes.
 *
 */
void egreso(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes)
{
    int auxId, index, auxHoraEgreso;

    mostrarDuenios(clientes,tamClientes);
    printf("ingrese ID del cliente: ");
    fflush(stdin);
    scanf("%d", &auxId);

    index = buscarIgual(clientes,tamClientes,auxId);

    if(index!=-1)
    {
        printf("\nIngrese el horario de salida: ");
        fflush(stdin);
        scanf("%d", &auxHoraEgreso);
        while(auxHoraEgreso < 0 || auxHoraEgreso > 24)
        {
            printf("\nError..........Reingrese el horario de salida: ");
            fflush(stdin);
            scanf("%d", &auxHoraEgreso);
        }
        if(ingresos[index].estado == 1)
        {
            for (int i = 0; i < tamClientes;i++)
            {
                if (ingresos[index].idDuenio == clientes[i].idDuenio)
                {
                    printf("\nDueño: %s %s\n",&clientes[i].nombre,&clientes[i].apellido);
                }

            }

            printf("Patente: %s\n", ingresos[index].patente);

            printf("Marca: ");
            switch(ingresos[index].marca)
            {
                case 1:
                    printf("ALPHA_ROMEO\n");
                break;
                case 2:
                    printf("FERRARI\n");
                break;
                case 3:
                    printf("AUDI\n");
                break;
                case 4:
                    printf("OTRO\n");
                break;
            }

            printf("valor estadia: $%d\n\n", calcularValorEstadia(ingresos[index].horarioDeEntrada,auxHoraEgreso,ingresos[index].marca));
            system("pause");
            ingresos[index].estado = 0;
        }

    }else
        {
            printf("No se encontro la ID ingresada!!");
            system("pause");
        }
}

/** Funcion para calcular el valor de la estadia al hacer un egreso de el estacionamiento.
 *
 * \param horaIngreso int hora de ingreso al estacionamiento.
 * \param horaEgreso int hora de egreso de el estacionamiento.
 * \param marca int marca de el automovil.
 * \return int total a pagar por la estadia.
 *
 */
int calcularValorEstadia(int horaIngreso, int horaEgreso, int marca)
{
    int rslt;

    switch(marca)
    {
        case 1:
            rslt = ((horaEgreso - horaIngreso)*150);
            acumAlphaRomeo = acumAlphaRomeo + rslt;
            break;
        case 2:
            rslt = ((horaEgreso - horaIngreso)*175);
            acumFerrari = acumFerrari + rslt;
            break;
        case 3:
            rslt = ((horaEgreso - horaIngreso)*200);
            acumAudi = acumAudi + rslt;
            break;
        case 4:
            rslt = ((horaEgreso - horaIngreso)*250);
            acumOtros = acumOtros + rslt;
            break;
    }
    return rslt;
}

/** Funcion para mostrar los dueños ordenados por marca.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamaño de el array de clientes.
 * \param marca int marca de el auto por la cual se va a hordenar.
 * \return void
 *
 */
void mostrarDueniosPorMarca(eDuenio clientes[], int tamClientes, eAutomovil ingresos[], int tamIngresos, int marca)
{
    int auxIdDuenio;
    printf("------------DUEÑOS DE AUTOMOVIL DE MARCA AUDI--------------\n");
    printf("ID_DUENIO\tNOMBRE\tAPELLIDO\tDIRECCION\tNUM_TARJETA_CREDITO\n");
    printf("-------------------------------------------------------------\n");
    for(int i = 0; i < tamIngresos; i++)
    {
        if(ingresos[i].marca == marca)
        {
            auxIdDuenio = ingresos[i].idDuenio;
            for(int j = 0; j < tamClientes; j++)
            {
                if(clientes[j].idDuenio == auxIdDuenio)
                {
                    mostrarDuenio(clientes[j]);
                    break;
                }
            }
        }

    }
}

/** Funcion para mostrar la recaudacion total por marca de automovil.
 *
 */
void recaudacionTotalPorMarca()
{
    printf("---------RECAUDACION TOTAL POR MARCA--------------\n");
    printf("\nRecaudacion total Alpha Romeo: $%d\n",acumAlphaRomeo);
    printf("Recaudacion total Ferrari: $%d\n",acumFerrari);
    printf("Recaudacion total Audi: $%d\n",acumAudi);
    printf("Recaudacion total Otros: $%d\n\n",acumOtros);
}

/** Funcion para calcular y mostrar la recaudacion total de el estacionamiento.
 *
 */
void recaudacionEstacionamiento()
{
    printf("---------RECAUDACION TOTAL POR MARCA--------------\n");
    printf("\nRecaudacion total Alpha Romeo: $%d\n\n",(acumAlphaRomeo + acumFerrari + acumAudi + acumOtros));
}


/** Funcion para mostrar los ingresos ordenados por hora de entrada y patente.
 *
 * \param ingresos[] eAutomovil array de ingresos.
 * \param tamIngresos int tamaño de el array de ingresos.
 * \param clientes[] eDuenio array de clientes.
 * \param tamClientes int tamañño de el array de clientes.
 *
 */
void mostrarIngresosOrdenados(eAutomovil ingresos[], int tamIngresos, eDuenio clientes[], int tamClientes)
{
    int flag = 0;
    eAutomovil auxAuto;
    printf("PATENTE\t\tMARCA\t\tID_DUENIO\tHORA_INGRESO\tNOMBRE\tAPELLIDO\n");
    printf("-----------------------------------------------------------------------------------\n");

    for(int i=0;i<tamIngresos;i++)
    {
        for(int j = i+1; j<tamIngresos-1;j++)
        {
            if(ingresos[j].horarioDeEntrada < ingresos[i].horarioDeEntrada)
            {
                auxAuto = ingresos[i];
                ingresos[i] = ingresos[j];
                ingresos[j] = auxAuto;
            }
            else
            {
                if(ingresos[j].horarioDeEntrada == ingresos[i].horarioDeEntrada)
                {
                    if(strcmp(ingresos[i].patente,ingresos[j].patente) > 0)
                    {
                        auxAuto = ingresos[i];
                        ingresos[i] = ingresos[j];
                        ingresos[j] = auxAuto;
                    }
                }
            }


        }
        mostrarIngreso(ingresos[i],clientes,tamClientes);

        if(ingresos[i].estado==0)
        {
            flag++;
        }
    }

    if(flag==tamIngresos)
    {
        printf("No hay Ingresos para mostrar!\n");
    }else
        {
            printf("\nLugares disponibles: %d\n", flag);
        }

}
