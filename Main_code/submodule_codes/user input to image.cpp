/*#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace cv;
using namespace std;

class concati{
public:
	Mat merge(Mat img,Mat img1) {
		Mat result;
		cv::hconcat(img, img1, result);

		return result;
	}
};

int main() {

	String input,concat,letter;
	vector<char> let = { 'a', 'b','c', 'd', 'e', 'f', 'g', 'h','i', 'j','k','l', 'm', 'n','o','p','q', 'r','s', 't', 'u','v','w','x','y','z' };
	cv::String path("C:/Users/Admin/Desktop/c++ practice/images/");
	vector<cv::String> fn;
	vector<cv::Mat> data;
	cv::glob(path, fn, true);
	Mat image, pano,image1;
	concati cat;
	int flag;
	std::cout << "Enter the word you want to search" << endl;
	cin >> input;

	

	for (int i = 0; i <= input.size()-1; i++)
	{
		flag = 0;
		//cout << input[i] << endl;
		for (int k = 0; k <= let.size()-1 ; k++) {
			if (input[i] == let[k])
			{
			
				concat = path + input[i]+input[i] + ".jpg";
				cout <<concat<<endl;
				flag = 1;
				break;
			}
		}
		

		if (flag == 0){
			input[i] = toupper(input[i]);
			concat = path + input[i] + ".jpg";
			cout << concat << endl;
		}
		//cout << input[i] << endl;

		if (i == 0) {
			image = imread(concat);
			//resize(image, image, cv::Size(40, 40));
		}
		else if (i == 1) {
			image1 = imread(concat);
			//resize(image1, image1, cv::Size(40, 40));
			pano = cat.merge(image, image1);
			
		}
		else {
			image1 = imread(concat);
			//resize(image1, image1, cv::Size(40, 40));
			pano = cat.merge(pano, image1);
			
		}
		
	}



	
namedWindow("Display window", WINDOW_AUTOSIZE);

imshow("Display window", pano);
waitKey(0);
return 0;
}*/