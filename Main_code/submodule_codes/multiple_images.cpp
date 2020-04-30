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


for (int i = 0; i <= fn.size()-22; i++) {
    cout << "number of files " << fn[i];
    cv::Mat im = cv::imread(fn[i]);


    if (!im.data)                              
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    data.push_back(im);
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", data[i]);                  

   // imshow("Display window", im);

 }
waitKey(0);
return 0;
}*/