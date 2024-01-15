*   CLIENTE - NETWORK DRIVER   */
#include <iostream> // importar librerias necesarias
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{

    int socket_cliente, conecta, envia; // definir variables
    char buffer[1024];

    socket_cliente = socket(AF_INET, SOCK_STREAM, 0); // crear el socket del cliente

    if (socket_cliente < 0) // si devuelve 0, crea el socket. si devuelve un valor negativo imprime un mensaje de error
    {
        cerr << "Error al crear el socket del cliente!" << endl;
        return 1;
    }

    sockaddr_in direccion_servidor; // definir la direccion del cliente
    direccion_servidor.sin_family = AF_INET;
    direccion_servidor.sin_port = htons(1234);
    direccion_servidor.sin_addr.s_addr = INADDR_ANY;

    conecta = connect(socket_cliente, (struct sockaddr *)&direccion_servidor, sizeof(direccion_servidor)); // solicitar conexion con el servidor
    if (conecta < 0)                                                                                       // manejo de errores
    {
        cerr << "Problemas de conexion.." << endl;
    }
    else
    {
        cout << "Conexion establecida!" << endl;
    }

    const char *mensaje = "Hola, servidor!"; // enviar datos al servidor
    envia = send(socket_cliente, mensaje, strlen(mensaje), 0);
    if (envia > 0) // manejo de errores
    {
        cout << "Mensaje enviado al servidor!" << endl;
    }

    memset(buffer, 0, sizeof(buffer)); // recibir datos del servidor
    ssize_t resp_servidor = recv(socket_cliente, buffer, sizeof(buffer), 0);

    if (resp_servidor <= 0) // manejo de errores
    {
        cerr << "Error al recibir los datos" << endl;
    }
    else
    {
        cout << "Respuesta del servidor: " << buffer << endl;
    }

    close(socket_cliente); // cerrar el socket
    return 0;
}
