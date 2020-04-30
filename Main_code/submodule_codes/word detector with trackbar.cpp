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


class concati {
public:
    Mat merge(Mat img, Mat img1) {
        Mat result;
        cv::hconcat(img, img1, result);

        return result;
    }

    Mat concatimage(String input, int divide) {
        String concat, letter;
        vector<char> let = { 'a', 'b','c', 'd', 'e', 'f', 'g', 'h','i', 'j','k','l', 'm', 'n','o','p','q', 'r','s', 't', 'u','v','w','x','y','z' };
        cv::String path("C:/Users/Admin/Desktop/c++ practice/images/");
        vector<cv::String> fn;
        vector<cv::Mat> data;
        cv::glob(path, fn, true);
        Mat image, pano, image1;
        int flag;




        for (int i = 0; i <= input.size() - 1; i++)
        {
            flag = 0;
            //cout << input[i] << endl;
            for (int k = 0; k <= let.size() - 1; k++) {
                if (input[i] == let[k])
                {

                    concat = path + input[i] + input[i] + ".jpg";
                    //cout << concat << endl;
                    flag = 1;
                    break;
                }
            }


            if (flag == 0) {
                input[i] = toupper(input[i]);
                concat = path + input[i] + ".jpg";
                //cout << concat << endl;
            }
            //cout << input[i] << endl;

            if (i == 0) {
                image = imread(concat);
                //resize(image, image, cv::Size(40, 40));
            }
            else if (i == 1) {
                image1 = imread(concat);
                //resize(image1, image1, cv::Size(40, 40));
                pano = merge(image, image1);

            }
            else {
                image1 = imread(concat);
                //resize(image1, image1, cv::Size(40, 40));
                pano = merge(pano, image1);

            }

        }
        if (divide != 0) {
            resize(pano, pano, cv::Size(pano.cols / divide, pano.rows / divide));
        }
        return pano;
    }
};


class thresh {
public:
    Mat tr(Mat feed, int pos) {

        Mat dst;
        threshold(feed, dst, pos, 255, 0);
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
    String input;
    VideoCapture cap;
    gray obj;
    int threshmax = 200, threshval;
    int dividemax = 3, divide;
    thresh obj2;
    std::cout << "Enter the word you want to search" << endl;
    cin >> input;
    Mat r, j, img, templ, result;
    cap.open(0);
    concati cat;
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    threshval = 120;
    divide = 1;


    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {

        cap.read(frame);

        createTrackbar("Threshold", "Live", &threshval, threshmax);
        createTrackbar("Rectangle size", "Live", &divide, dividemax);
        templ = cat.concatimage(input, divide);
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        r = obj.cvtgray(frame);
        j = obj2.tr(r, threshval);
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
        imshow("Live", j);
        if (waitKey(5) >= 0)
            break;
    }

    return 0;
}*/