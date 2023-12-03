# Tarea2SO

# Tarea 2 SO Brandon Reyes - Esteban Rivas
# En este repositorio se encuentran 3 codigos que ejemplifican maneras distintas de pasar imagenes de color a blanco y negro 

# Para el funcionamiento de estos codigos se deben subir las imagenes que se quieran modificar a la carpeta "imagenes" 
# Posteriormente las imagenes generadas quedaran guardadas en la carpeta "imagenesBlancoNegro"

Escribimos el comando "make" como primer paso, ya que asi preparamos automaticamente los comandos de GNU g++ para los 3 codigos, tal como esta escrito en el archivo Makefile

# En el primer caso, tenemos al codigo secuencial
Este codigo se ejecuta desde la terminal, una vez ubicados en la carpeta del repositorio, la forma de ejecucion es escribir los siguientes comandos por terminal (utilizando la imagen espacio.jog como ejemplo):
./Secuencial 
espacio.jpg espacioSinColor.jpg 

-> En este caso hay que ejecutar el codigo y por parametro pasar el nombre de la imagen que se modificara y el nombre de la imagen que se obtendra

# En este segundo caso, tenemos al codigo paralelo con OpenCV
Este codigo se ejecuta desde la terminal, una vez ubicados en la carpeta del repositorio, la forma de ejecucion es escribir los siguientes comandos por terminal (utilizando la imagen espacio.jog como ejemplo):
./Threads
espacio.jpg espacioSinColor.jpg 4

-> En este caso hay que ejecutar el codigo y por parametro pasar el nombre de la imagen que se modificara, el nombre de la imagen que se obtendra y ademas el numero de hilos que se usaran para ejecutar el codigo

# En este tercer caso, tenemos al codigo paralelo con OpenMP
Este codigo se ejecuta desde la terminal, una vez ubicados en la carpeta del repositorio, la forma de ejecucion es escribir los siguientes comandos por terminal (utilizando la imagen espacio.jog como ejemplo):
./OpenMP
espacio.jpg espacioSinColor.jpg 4

-> En este caso hay que ejecutar el codigo y por parametro pasar el nombre de la imagen que se modificara, el nombre de la imagen que se obtendra y ademas el numero de hilos que se usaran para ejecutar el codigo


Por ultimo, al final de cada caso se muestra, en la terminal, el progreso del programa, el ancho y largo, y el tiempo que demora en ejecutar el programa en milisegundos

# Conclusiones

Las versiones paralelas son mas eficientes que la version secuencial, sobre todo, la version paralela utilizando la API OpenMP