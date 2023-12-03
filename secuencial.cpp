#include <opencv2/opencv.hpp>

#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // Carpeta con imágenes a probar
    string folderName = "Imagenes";

    string inputName;
    cin >> inputName;

    string outputName;
    cin >> outputName;

    // Rutas de archivos de entrada y salida
    string inputPath = folderName + "/" + inputName;
    string outputPath = "imagenesBlancoNegro/" + outputName;

    auto start = high_resolution_clock::now();

    // Carga la imagen
    Mat imagen = imread(inputPath);

    if (imagen.empty()) {
        cout << "No se pudo cargar la imagen, verificar el formato." << endl;
        return 1;
    }

    Mat grayImage(imagen.rows, imagen.cols, CV_8UC1); // Matriz para la imagen en escala de grises

    // Mostrar la imagen a color
    namedWindow("Imagen Original", WINDOW_NORMAL);
    imshow("Imagen Original", imagen);
    waitKey(0);

    // Convertir la imagen a escala de grises
    for (int r = 0; r < imagen.rows; r++) {
        for (int c = 0; c < imagen.cols; c++) {
            Vec3b intensity = imagen.at<Vec3b>(r, c);
            int grayValue = 0.3 * intensity.val[2] + 0.59 * intensity.val[1] + 0.11 * intensity.val[0];
            grayImage.at<uchar>(r, c) = grayValue; // Asignar el valor de gris al píxel correspondiente
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Cargando imagen..." << endl;
    cout << "Filas (altura): " << imagen.rows << " Columnas (ancho): " << imagen.cols << endl;
    cout << "Comenzando conversión..." << endl;
    cout << "Conversión terminada..." << endl;
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    // Mostrar la imagen en escala de grises
    namedWindow("Imagen en Blanco y Negro", WINDOW_NORMAL);
    imshow("Imagen en Blanco y Negro", grayImage);
    waitKey(0);

    // Guardar imagen en blanco y negro
    imwrite(outputPath, grayImage);

    return 0;
}