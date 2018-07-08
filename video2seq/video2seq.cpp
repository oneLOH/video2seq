// video2seq.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void main() {
    VideoCapture cap("E://multiquads.mp4");
    if ( !cap.isOpened() ) {
        return ;
    }

    int imgIndex(0);
    for ( ; ; ) {
        Mat frame;
        cap >> frame;
        if ( frame.empty() ) {
            break;
        }
        char *imageSaveName = new char[64];
        sprintf( imageSaveName, "E:\\Data\\test8\\%05d.jpg", imgIndex );
        imwrite( imageSaveName, frame );
        delete[] imageSaveName;
        imgIndex++;
        cout << imgIndex << endl;
    }
    cout << "total frames: " << imgIndex << endl;
}