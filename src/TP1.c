#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.c"
#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
    //variables
    int opcion;
    float km;
    float precioAerolineas;
    float precioLatam;

    float descuento;
    float interes;
    float btc;

    float precioDebitoAerolineas;
    float precioDebitoLatam;
    float precioCreditoAerolineas;
    float precioCreditoLatam;
    float precioBtcAerolineas;
    float precioBtcLatam;
    float precioUnitarioAerolineas;
    float precioUnitariosLatam;
    float diferenciaPrecio;

    int flagKm;
    int flagPrecio;

    flagKm=0;
    flagPrecio=0;

    km=0;
    precioAerolineas=0;
    precioLatam=0;

    descuento=0.90; // descuento del 10% - (precio * 0.90)
    interes=1.25;   // interes del 25%- (precio * 1.25)
    btc=4606954.55; // valor BTC- (precio / btc)


    do{

        // crear menu con las opciones.
    	printf("\nSelecione una opcion. \n\n");
        printf("\n1. Ingresar Kilometros: km = %.f\n", km);
		printf("2. Ingresar precio de vuelos: Aerolineas = %.f", precioAerolineas);
		printf(" Latam = %.f\n", precioLatam);
		printf("3. Calcular todos los costos: \n");
		printf("4. Informar resultados \n");
		printf("5. Carga forzada de datos \n");
		printf("6. Salir  \n\n");
		scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
            	// bandera para que solo se pueda ingresar una vez los kilometros mientras que sea un numero valido.
		if(flagKm == 0)
		{
			//pedir los kilometros
			km=PedirFlotante("\nIngrese Kilometros: ");
			while(km < 1)
			{
				//mensaje error + volver a pedir kilometros
				km=PedirFlotante("\nError. Ingrese Kilometros: ");
			}
			flagKm=1;
		}else{
			//msj error al volver a querer cargar los Kilometros ya cargados
			printf("\nError. Ya se ingresaron los Kilometros. \n");
		}

            break;

            case 2:
            	//bandera para que los precios solo se puedan ingresar una vez mientras que los precio sean validos
		if(flagPrecio ==0)
		{
			//pedir precio aerolineas
			precioAerolineas=PedirFlotante("-Precio vuelo Aerolineas: ");
			while(precioAerolineas <1)
			{
				// mensaje de error + volver a pedir precio aerolineas valido
				precioAerolineas=PedirFlotante("\nError. Ingrese Precio vuelo Aerolineas: \n");
			}
			//pedir precio latam
			precioLatam = PedirFlotante("-Precio vuelo Latam: ");
			while(precioLatam <1)
			{
				// mensaje de error + volver a pedir precio Latam valido
				precioLatam = PedirFlotante("\nError. Ingrese Precio vuelo Latam: \n\n");
			}
			flagPrecio=1;
		}else{
			//msj de error al querer volver a ingresar los precios ya cargados
			printf("\nError. Ya se ingresaron los precios de los vuelos.\n");
		}
		break;

            case 3:
                // mensaje de error en caso que falten cargar datos mayor a 0
            	MostrarErrorParaCalcular (precioLatam, precioAerolineas, km);
                //verificar que se hayan ingresado todos los datos positivos
                if(precioLatam > 0 && precioAerolineas >0 && km > 0)
                {
			//calcular precio con debito Aerolineas
			precioDebitoAerolineas = CalcularMultiplicacion(precioAerolineas, descuento);
			// calcular precio on debito latam
			precioDebitoLatam = CalcularMultiplicacion(precioLatam, descuento);
			//calcular precio con credito Aerolineas
			precioCreditoAerolineas = CalcularMultiplicacion(precioAerolineas, interes);
			// calcular precio con credito Latam
			precioCreditoLatam =CalcularMultiplicacion(precioLatam, interes);
			// calcular precio btc Aerolineas
			precioBtcAerolineas = CalcularDivision(precioAerolineas, btc);
			//calcular precio btc Latam
			precioBtcLatam = CalcularDivision(precioLatam, btc);
			//calcular precio unitario Aerolineas
			precioUnitarioAerolineas = CalcularDivision(precioAerolineas, km);
			//calcular precio unitario Latam
			precioUnitariosLatam = CalcularDivision(precioLatam, km);
			//calcular la diferencia - resta
			if(precioLatam > precioAerolineas)
			{
				diferenciaPrecio = CalcularResta(precioLatam, precioAerolineas);
			}else{
				diferenciaPrecio = CalcularResta(precioAerolineas, precioLatam);
			}
			//msj avisando al usuario que se hicieron todos los calculos
			printf("\nSe calcularon todos los costos con exito..\n");
                }

            break;

            case 4:
                /// mensaje de error en caso que falten cargar datos mayor a 0
            	MostrarErrorParaInformar (precioLatam, precioAerolineas, km);
                //verificar que se hayan ingresado los datos mayor que 0
                if(precioLatam > 0 && precioAerolineas >0 && km > 0)
                {
                    //Informar los resultados
                    printf("\nLatam: \n");
                    printf("a)Precio con tarjeta de débito: $ %.2f\n", precioDebitoLatam);
                    printf("b)Precio con tarjeta de crédito: $ %.2f\n", precioCreditoLatam);
                    printf("c)Precio pagando con bitcoin: $ %.8f\n", precioBtcLatam);
                    printf("d)Precio unitario: $ %.2f \n\n", precioUnitariosLatam);

                    printf("Aerolineas: \n");
                    printf("a)Precio con tarjeta de débito: $ %.2f\n", precioDebitoAerolineas);
                    printf("b)Precio con tarjeta de crédito: $ %.2f\n", precioCreditoAerolineas);
                    printf("c)Precio pagando con bitcoin: $ %.8f\n", precioBtcAerolineas);
                    printf("d)Precio unitario: $ %.2f \n\n", precioUnitarioAerolineas);

                    printf("La diferencia de precio es: $ %.2f \n", diferenciaPrecio);
                }

            break;

            case 5:
                // muestra los resultados forzados con los datos hard-codeado ya en la funcion.
                ResultadosCargaForzada();

            break;
            case 6:
                //al presionar 6 directamente rompe y sale del menu
            break;
            default:
                //mensaje de error al ingresar una opcion no valida del 1 al 6
                printf("\n\nError. Ingrese una opcion valida: \n\n");
            break;
        }
    }while(opcion != 6);

    return EXIT_SUCCESS;
}
