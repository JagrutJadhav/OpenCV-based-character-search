/*#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace cv;
using namespace std;



class gray {
  public:
      Mat cvtgray(Mat frame) {
          Mat gray;
          cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
          
          return gray;
         
          
      }
};

class thresh {
public:
    Mat tr(Mat feed) {

        Mat dst;
        threshold(feed, dst, 150, 255 , 0);
        

        return dst;
    }
};



int main(int, char**)
{
    Mat frame;
    VideoCapture cap;
    gray obj;
    thresh obj2;
    int* threshold_value;
    int* max_BINARY_value;
    Mat r,j;
    cap.open(0);
    
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
       
        cap.read(frame);
        
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        } 
        r= obj.cvtgray(frame);
        j = obj2.tr(r);
      
        imshow("Live", j);
        if (waitKey(5) >= 0)
            break;
    }
    
    return 0;
}*/