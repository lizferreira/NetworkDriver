# NetworkDriver
Implementación de un controlador de red en C++ que utiliza sockets para facilitar la comunicación eficiente entre un servidor y un cliente a través de una red (protocolo TCP). 

## Descripcion:
Este proyecto implementa un controlador de red en C++ que utiliza sockets para facilitar la comunicación eficiente entre un servidor y un cliente a través de una red.
## Caracteristicas:
### Caracteristicas generales:
1. Comunicacion cliente-servidor: Establece una conexión bidireccional entre un servidor y un cliente mediante sockets.
2. Manejo de errores: Incluye manejo básico de errores para situaciones como la creación del socket, la vinculación del servidor, la escucha de solicitudes y la aceptación de conexiones.
3. Uso de sockets: Utiliza la librería de sockets para la comunicación, con funciones como socket, bind, listen, accept, send, y recv.
### Caracteristicas del servidor:
1. Espera de conexiones entrantes: El servidor está en un bucle infinito esperando y aceptando conexiones entrantes de clientes.
2. Recepcion y envio de datos: Recibe datos del cliente utilizando la función recv y envía una respuesta predefinida al cliente usando la función send.
3. Cierre del socket: Cierra adecuadamente el socket del servidor al finalizar el programa.
### Caracteristicas del cliente: 
1. Creación y conexión del socket del cliente: Crea un socket del cliente y se conecta al servidor utilizando la función connect.
2. Envío y recepción de datos: Envía datos al servidor utilizando la función send y recibe datos del servidor utilizando recv.
3. Cierre del socket del cliente: Cierra adecuadamente el socket del cliente al finalizar el programa.

![arquitectura](/../main/imagenes/arquitectura_servidor_cliente.jpg)

> Del lado del servidor, primero se debe crear un socket, que se puede crear mediante la funcion socket(). Luego se configura la direccion del servidor para posteriormente vincular al puerto utilizando bind(). 
Una vez creado el socket y conectado la direccion ip y el puerto, se llama a la funcion listen() para eschuchar las solicitudes de conexion de otros programas (cliente). Cuando un cliente solicita una conexion con el servidor, necesita utilizar la funcion accept() para aceptar la solicitud de conexion y devolver un nuevo socket.
Una vez establecida la conexion, el servidor y el cliente pueden enviar y recibir datos entre ellos, lo que se puede lograr utilizando las funciones send() y recv().
Una vez completada la transferencia de datos, se debe cerrar la conexion con la funcion close().

### Tecnologias utilizadas
- Visual Studio Code
- g++ (compilador de c++)
- C/C++ (extension de vs code)
- C/C++ Compile Run (extension de vs code)
- Sistema Operativo Linux

### Librerias utilizadas de C++
- __iostream__ (biblioteca estandar de c++ para entrada y salida [cout, cerr])
- __cstring__ (para operaciones con cadenas)
- __netinet/in.h__ (para configurar la direccion del servidor)
- __sys/socket.h__ (funciones para programar con sockets [socket, bind, listen, accept, recv, etc.])
- __unistd.h__ (funciones relacionadas con el sistema operativo [close, etc])

### Documentaciones y guías:
> [c++](https://en.cppreference.com/w/)

> [Beej's Guide to Network Programming. Using Internet Sockets](https://beej.us/guide/bgnet/)


### Compilacion
Compilar el servidor
```
g++ server.cpp -o server
```
Compilar el cliente
```
g++ client.cpp -o client
```
### Ejecucion
1. Ejecuta el servidor
```
./server
```
2. Ejecuta el cliente (en otra terminal)
```
./client
```
