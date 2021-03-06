// Created on 2020/04/28.

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("/users/cocoblue/test.JPG", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "Can Not Read Image!" << endl;
        return -1;
    }
    Mat grad_x, grad_y, grad;
    Mat abs_grad_x, abs_grad_y;
    int scale = 1, delta = 0;

    Sobel(image, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
    Sobel(image, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    imshow("Before", image);
    imshow("After", grad);

    waitKey(0);
    return 0;
}