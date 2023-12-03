#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <chrono>
#include <thread>
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;
using namespace chrono;

// Convierte una parte de la imagen a blanco y negro
void convertToGrayscale(const Mat& input, Mat& output, int startRow, int endRow) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < input.cols; j++) {
            Vec3b pixel = input.at<Vec3b>(i, j);
            uchar luminosity = static_cast<uchar>(0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0]);
            output.at<uchar>(i, j) = luminosity;
        }
    }
}

int main() {
    // Carpeta con imagenes a probar
    string folderName = "Imagenes";

    string inputName;
    cin >> inputName;

    string outputName;
    cin >> outputName;

    // Rutas de archivos de entrada y salida
    string inputPath = folderName + "/" + inputName;
    string outputPath = "imagenesBlancoNegro/" + outputName;

    // Carga la imagen 
    Mat imagen = imread(inputPath);

    if (imagen.empty()) {
        cout << "No se pudo cargar la imagen de entrada: " << inputPath << endl;
        return 1;
    }

    // Obtiene dimensiones de la imagen
    int rows = imagen.rows;
    int cols = imagen.cols;

    int numThreads;
    cin >> numThreads;
    auto start = high_resolution_clock::now();

    // Convierte la imagen a blanco y negro utilizando threads
    Mat grayImg(rows, cols, CV_8UC1);

    // Vector que almacena los threads
    vector<thread> threads;

    // Divide la tarea por threads
    int rowsPerThread = rows / numThreads;
    int startRow = 0;
    int endRow = rowsPerThread;

    for (int i = 0; i < numThreads; i++) {
        threads.emplace_back(convertToGrayscale, ref(imagen), ref(grayImg), startRow, endRow);
        startRow = endRow;
        endRow = (i == numThreads - 2) ? rows : endRow + rowsPerThread;
    }

    // Espera a los threads 
    for (auto& t : threads) {
        t.join();
    }

    // Muestra imagen original y la imagen generada
    imshow("Imagen Original", imagen);
    imshow("Imagen en Blanco y Negro", grayImg);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << "Cargando imagen..." << endl;
    cout << "Filas (altura): " <<rows<<" Columnas (ancho): " << cols << endl;
    cout << "Comenzando conversion..." << endl;
    cout << "Conversion Terminando..." << endl;

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    waitKey(0);

    // Guarda imagen en blanco y negro
    imwrite(outputPath, grayImg);
    
    return 0;
}