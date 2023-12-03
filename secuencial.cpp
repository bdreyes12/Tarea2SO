#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("./paisaje.jpg", IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se pudo cargar la imagen. Verifica la ruta o el formato." << endl;
        return -1;
    }

    Mat grayImage(image.rows, image.cols, CV_8UC1); // Matriz para la imagen en escala de grises

    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b intensity = image.at<Vec3b>(r, c);
            int grayValue = 0.3 * intensity.val[2] + 0.59 * intensity.val[1] + 0.11 * intensity.val[0];
            grayImage.at<uchar>(r, c) = grayValue; // Asignar el valor de gris al píxel correspondiente
        }
    }

    imwrite("imagen_escala_gris.jpg", grayImage);
    cout << "Imagen en escala de grises generada y guardada como imagen_escala_gris.jpg" << endl;
    return 0;

}