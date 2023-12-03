#include <opencv2/highgui.hpp>

#include <iostream>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;
using namespace chrono;

// Función para convertir una imagen a escala de grises utilizando la luminosidad
Mat convertirAGrises(const Mat& imagen);

int main() {
    // Solicitar al usuario el nombre de la imagen de entrada

    string nombreEntrada;
    cin >> nombreEntrada;

    string nombreSalida;
    cin >> nombreSalida;

    // Solicitar al usuario la cantidad de hilos a utilizar
    int numHilos;
    cin >> numHilos;

    // Rutas de las imágenes
    string rutaEntrada = "Imagenes/" + nombreEntrada;
    string rutaSalida = "imagenesBlancoNegro/" + nombreSalida;

    // Cargar la imagen desde el archivo de entrada
    Mat imagen = imread(rutaEntrada);

    if (imagen.empty()) {
        cout << "No se pudo cargar la imagen de entrada: " << rutaEntrada << endl;
        return 1;
    }

    // Convertir la imagen a escala de grises
    auto start = high_resolution_clock::now();
    Mat imagenGrises = convertirAGrises(imagen);
    auto stop = high_resolution_clock::now();
    
    int rows = imagen.rows;
    int cols = imagen.cols;

    // Mostrar el tiempo de ejecución en milisegundos
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Cargando imagen..." << endl;
    cout << "Filas (altura): " << rows <<" Columnas (ancho): " << cols << endl;
    cout << "Comenzando conversion..." << endl;
    cout << "Conversion Terminando..." << endl;

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    waitKey(0);

    // Mostrar la imagen original y la imagen en escala de grises
    imshow("Imagen Original", imagen);
    imshow("Imagen en Blanco y Negro", imagenGrises);

    waitKey(0);

    // Guardar la imagen en escala de grises
    imwrite(rutaSalida, imagenGrises);

    return 0;
}

// Función para convertir una imagen a escala de grises utilizando la luminosidad
Mat convertirAGrises(const Mat& imagen) {
    int rows = imagen.rows;
    int cols = imagen.cols;

    // Crear una matriz para la imagen en escala de grises
    Mat imagenGrises(rows, cols, CV_8UC1);

    // Obtener el número de hilos disponibles y asegurarse de no exceder el número de filas
    int numHilosDisponibles = omp_get_max_threads();
    int numHilos = min(numHilos, numHilosDisponibles);

#pragma omp parallel for num_threads(numHilos)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = imagen.at<Vec3b>(i, j);

            // Calcular el valor de gris ponderado por la luminosidad
            uchar valorGris = static_cast<uchar>(0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0]);

            // Asignar el nuevo valor al pixel en la imagen en escala de grises
            imagenGrises.at<uchar>(i, j) = valorGris;
        }
    }

    return imagenGrises;
}
