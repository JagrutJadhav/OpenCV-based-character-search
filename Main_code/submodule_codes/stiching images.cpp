/*#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace cv;
using namespace std;



int main(){

cv::String path("C:/Users/Admin/Desktop/c++ practice/images//*.jpg");
vector<cv::String> fn;
vector<cv::Mat> data;
cv::glob(path, fn, true);
Mat image;



Mat pano;

cv::hconcat(imread(fn[1]), imread(fn[2]),pano);
cout << "stitching completed successfully\n" << "oooooooooo" << " saved!";
namedWindow("Display window", WINDOW_AUTOSIZE);
imshow("Display window", pano);
waitKey(0);
return 0;
}*/