#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


float PedirFlotante(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

float CalcularMultiplicacion(float n1, float n2)
{
    float multiplicacion;
    multiplicacion= n1 * n2;
    return multiplicacion;
}

float CalcularDivision (float n1, float n2)
{
   float division;
   division= n1 / n2;
   return division;
}

float CalcularResta (float n1, float n2)
{
    float resta;
    resta= n1 - n2;
    return resta;
}

void MostrarErrorParaCalcular (int n1, int n2, int n3)
{
    if(n1 < 1 || n2 <1 || n3 < 1)
    {
    printf("\n\nError. No se ingresaron todos los datos para calcular. \n\n");
    }
}

void MostrarErrorParaInformar (int n1, int n2, int n3)
{
    if(n1 < 1 || n2 <1 || n3 < 1)
    {
    printf("\n\nError. No se ingresaron todos los datos para informar. \n\n");
    }
}

void ResultadosCargaForzada()
{
    float km=7090, precioAerolineas=162965, precioLatam=159339;
    float descuento=0.90, interes= 1.25, btc = 4606954.55;

    float debAer, debLat, credAer, credLat, btcAer, btcLat;
    float uniAer, uniLat, difPrecio;

    debAer = CalcularMultiplicacion(precioAerolineas, descuento); //calcular precio con debito Aerolineas
    debLat = CalcularMultiplicacion(precioLatam, descuento); // calcular precio on debito latam
    credAer = CalcularMultiplicacion(precioAerolineas, interes); // calcular precio con credito Aerolineas
    credLat =CalcularMultiplicacion(precioLatam, interes); // calcular precio con credito Latam
    btcAer = CalcularDivision(precioAerolineas, btc);// calcular precio btc Aerolineas
    btcLat = CalcularDivision(precioLatam, btc); //calcular precio btc Latam
    uniAer = CalcularDivision(precioAerolineas, km); //calcular precio unitario Aerolineas
    uniLat = CalcularDivision(precioLatam, km); //calcular precio unitario Latam
    difPrecio = CalcularResta(precioAerolineas, precioLatam); //calcular la diferencia - resta

    printf("\nKmsIngresados: %.f\n\n", km);

    printf("Latam: \n");
    printf("a)Precio con tarjeta de débito: $ %.2f\n", debLat);
    printf("b)Precio con tarjeta de crédito: $ %.2f\n", credLat);
    printf("c)Precio pagando con bitcoin: $ %.8f\n", btcLat);
    printf("d)Precio unitario: $ %.2f\n\n", uniLat);

    printf("Aerolineas: \n");
    printf("a)Precio con tarjeta de débito: $ %.2f\n", debAer);
    printf("b)Precio con tarjeta de crédito: $ %.2f\n", credAer);
    printf("c)Precio pagando con bitcoin: $ %.8f\n", btcAer);
    printf("d)Precio unitario: $  %.2f\n\n", uniAer );

    printf("La diferencia de precio es: $  %.2f\n", difPrecio);

}
