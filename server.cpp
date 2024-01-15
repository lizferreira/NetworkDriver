/*   SERVIDOR - NETWORK DRIVER   */
#include <iostream> //importar librerias necesarias
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    int socket_servidor, conexion_servidor, escucha_cliente, acepta_cliente, recibe_cliente; // definir las variables
    char buffer[1024];

    socket_servidor = socket(AF_INET, SOCK_STREAM, 0); // crear el socket del servidor

    if (socket_servidor < 0) // manejo de errores, en caso que devuelva un valor negativo imprime un mensaje de error
    {
        cerr << "Error al crear el socket del servidor!" << endl;
        return 1;
    }

    sockaddr_in direccion_servidor; // configurar direccion del servidor
    direccion_servidor.sin_family = AF_INET;
    direccion_servidor.sin_port = htons(1234);
    // direccion_servidor.sin_addr.s_addr = inet_addr("0.0.0.0"); // colocar una direccion especifica
    direccion_servidor.sin_addr.s_addr = INADDR_ANY;

    conexion_servidor = bind(socket_servidor, (struct sockaddr *)&direccion_servidor, sizeof(direccion_servidor)); // vincular el socket

    if (conexion_servidor < 0) // manejo de errores
    {
        cerr << "No se pudo conectar el socket al puerto!" << endl;
        close(socket_servidor);
        return 1;
    }

    escucha_cliente = listen(socket_servidor, 1); // escuchar las solicitudes del cliente
    cout << "El servidor esta esperando conexiones en el puerto.." << endl;

    if (escucha_cliente < 0) // manejo de errores
    {
        cerr << "Error al escuchar las solicitudes del cliente!" << endl;
        close(socket_servidor);
        return 1;
    }

    while (true) // bucle en donde el servidor acepta conexiones entrantes
    {
        sockaddr_in direccion_cliente; // aceptar solicitudes del cliente
        socklen_t len_cliente = sizeof(direccion_cliente);
        acepta_cliente = accept(socket_servidor, (struct sockaddr *)&direccion_cliente, &len_cliente);

        if (acepta_cliente < 0) // manejo de errores
        {
            cerr << "Error al aceptar la conexion del cliente!" << endl;
            close(socket_servidor);
            return 1;
        }

        memset(buffer, 0, sizeof(buffer)); // recibir datos del cliente
        recibe_cliente = recv(acepta_cliente, buffer, sizeof(buffer), 0);

        if (recibe_cliente < 0) // manejo de errores
        {
            cerr << "Error al recibir datos del cliente!" << endl;
        }
        else
        {
            cout << "Mensaje del cliente: " << buffer << endl;
        }

        const char *respuesta = "Mensaje recibido por el servidor!"; // enviar respuesta al cliente
        send(acepta_cliente, respuesta, strlen(respuesta), 0);
        close(acepta_cliente);
    }

    close(socket_servidor); // cierra el socket
    return 0;
}
