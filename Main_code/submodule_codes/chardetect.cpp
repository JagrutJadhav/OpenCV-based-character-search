/*#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace cv;
using namespace std;

int match_method = 0;

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
        threshold(feed, dst, 100, 255, 0);
        return dst;
    }
    Mat tem(Mat img, Mat Tem) {
        gray obj;
        Mat result;
        Tem = obj.cvtgray(Tem);
        Tem.convertTo(Tem, CV_32F);
        img.convertTo(img, CV_32F);
        /// Localizing the best match with minMaxLo
        int result_cols = img.cols - Tem.cols + 1;
        int result_rows = img.rows - Tem.rows + 1;

        result.create(result_rows, result_cols, CV_32F);

        /// Do the Matching and Normalize
        matchTemplate(img, Tem, result, match_method);
        normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

        return result;
    }

};



int main(int, char**)
{
    Mat frame;

    VideoCapture cap;

    gray obj;
    thresh obj2;

    Mat r, j, img, templ, result;
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
        Mat image = imread("C:/Users/Admin/Desktop/c++ practice/images/try1.jpg");
        resize(image, templ, cv::Size(image.cols/1, image.rows/1));


        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        r = obj.cvtgray(frame);
        j = obj2.tr(r);
        img = obj2.tem(j, templ);

        /// Localizing the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        Point matchLoc;

        minMaxLoc(img, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

        /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
        if (match_method == cv::TM_SQDIFF || match_method == cv::TM_SQDIFF_NORMED)
        {
            matchLoc = minLoc;
        }
        else
        {
            matchLoc = maxLoc;
        }

        /// Show me what you got
        rectangle(frame, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
        rectangle(img, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);


        //imshow(result_window, result);



        imshow("img", frame);
        //imshow("img", result);
        imshow("Live", j);
        if (waitKey(5) >= 0)
            break;
    }

    return 0;
}*/