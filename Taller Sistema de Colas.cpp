#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstddef>

using namespace std;

int main()
{
    int seed = time(nullptr);
    srand(seed);

    // Variables para llevar el control de tiempo
    int hora = 9, minuto = 0, segundo = 0;

    int random_number[20] = {94, 73, 78, 72, 59, 63, 85, 66, 61, 23, 71, 26, 96, 73, 77, 9, 14, 88, 64, 82};
    int random_number2[20] = {36, 46, 34, 70, 97, 80, 40, 94, 55, 43, 15, 67, 78, 21, 22, 41, 35, 87, 35, 29};

    // Variables para los tiempos aleatorios
    int inter_arrival_time[20], service_time[20];
    
    // Variables para el tiempo de finalización del servicio anterior
    int previous_service_end_time = 0;

    // Variables para los tiempos de llegada y servicio
    int arrival_time = 0, service_start_time, service_end_time = 0;

    // Variables para el tiempo de espera y el tiempo ocioso del servidor
    int customer_wait_time, total_wait_time = 0, idle_time = 0, total_idle_time = 0;

   // Imprimir encabezado de la tabla
    cout << setw(10) << "Random"
         << setw(25) << "Interarrival"
         << setw(1) << "     " // Espacio en blanco
         << setw(1) << "Arrival Time"
         << setw(1) << "       " // Espacio en blanco
         << setw(20) << "Service Start"
         << setw(11) << "Random"
         << setw(26) << "Service Time"
         << setw(16) << "Service End"
         << setw(16) << "Wait Time"
         << setw(15) << "Idle Time" << endl;

    // Iterar para cada cliente
    for (int i = 0; i < 20; i++)
    {
        // Generar tiempo entre llegadas aleatorio
        if (random_number[i] >= 0 && random_number[i] <= 9)
        {
            inter_arrival_time[i] = 2;
        }
        else if (random_number[i] >= 10 && random_number[i] <= 34)
        {
            inter_arrival_time[i] = 4;
        }
        else if (random_number[i] >= 35 && random_number[i] <= 69)
        {
            inter_arrival_time[i] = 6;
        }
        else if (random_number[i] >= 70 && random_number[i] <= 89)
        {
            inter_arrival_time[i] = 8;
        }
        else if (random_number[i] >= 90 && random_number[i] <= 99)
        {
            inter_arrival_time[i] = 10;
        }

        // Calcular tiempo de llegada del cliente
        arrival_time = arrival_time + inter_arrival_time[i];

        // Calcular tiempo de servicio aleatorio
        if (random_number2[i] >= 0 && random_number2[i] <= 14)
        {
            service_time[i] = 1;
        }
        else if (random_number2[i] >= 15 && random_number2[i] <=31)
        {
    service_time[i] = 3;
}
else if (random_number2[i] >= 32 && random_number2[i] <= 61)
{
    service_time[i] = 5;
}
else if (random_number2[i] >= 62 && random_number2[i] <= 89)
{
    service_time[i] = 7;
}
else if (random_number2[i] >= 90 && random_number2[i] <= 99)
{
    service_time[i] = 9;
}

// Calcular tiempo de inicio de servicio del cliente
if (arrival_time > service_end_time)
{
    service_start_time = arrival_time;
}
else
{
    service_start_time = service_end_time;
}

// Calcular tiempo de finalización de servicio del cliente
service_end_time = service_start_time + service_time[i];

// Calcular tiempo de espera del cliente en cola
customer_wait_time = service_start_time - arrival_time;
if (customer_wait_time < 0)
{
    customer_wait_time = 0;
}

// Calcular tiempo ocioso del servidor
idle_time = service_start_time - previous_service_end_time;
if (idle_time < 0)
{
    idle_time = 0;
}

// Acumular los tiempos de espera e inactividad del servidor
total_wait_time += customer_wait_time;
total_idle_time += idle_time;

// Imprimir los resultados de este cliente
cout << setw(8) << random_number[i] << "\t"
     << setw(15) << inter_arrival_time[i];

segundo += inter_arrival_time[i];
if (segundo >= 60)
{
    minuto += segundo / 60;
    segundo %= 60;
}
if (minuto >= 60)
{
    hora += minuto / 60;
    minuto %= 60;
}

// Calcular la hora de llegada del cliente
int arrival_hour = hora + ((minuto + arrival_time) / 60) % 24;
int arrival_minute = (minuto + arrival_time % 60) % 60;

cout << setw(15) << arrival_hour << ":" << setw(2) << setfill('0') << arrival_minute << setfill(' ') << "\t"
     << setw(15) << arrival_hour << ":" << setw(2) << setfill('0') << service_start_time % 60 << setfill(' ') << "\t"
     << setw(8) << random_number2[i] << "\t"
     << setw(15) << service_time[i];

// Calcular la hora de finalización del servicio
int service_end_hour = hora + ((minuto + service_end_time) / 60) % 24;
int service_end_minute = (minuto + service_end_time % 60) % 60;

cout << "\t" << setw(15) << service_end_hour << ":" << setw(2) << setfill('0') << service_end_minute << setfill(' ')
     << setw(15) << customer_wait_time
     << setw(15) << idle_time << endl;

// Actualizar el tiempo
previous_service_end_time = service_end_time;


}

 // Imprimir el total
    cout << setw(48) << "Total"
         << setw(10) << ""
         << setw(15) << ""
         << setw(15) << ""
         << setw(10) << ""
         << setw(15) << ""
         << setw(15) << ""
         << setw(15) << total_wait_time << "\t"
         << setw(15) << total_idle_time << endl;

return 0;

}

