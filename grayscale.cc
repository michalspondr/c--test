/*
   Grayscale palette generator

   This application generates a square image of grayscale boxes
   msize - width/height of generated image
   blockcount - number of boxes in a row/column

   Build:
   g++ -std=c++11 grayscale.cc -o grayscale -lopencv_core -lopencv_highgui -lopencv_imgproc

 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

int main( int argc, char** argv )
{
    // UPDATE THIS
    const unsigned int msize=800;
    const double blockcount = 16;   // should be a multiple of 256 if you want colors 0 and 255

	Mat image = Mat(Size(msize, msize), CV_8UC1);

    double color=0;

    // create x times y boxes
    for (int x=0; x<msize; x+=msize/blockcount) {
        for (int y=0; y<msize; y+=msize/blockcount) {

            // color the box
            for (int i=x; i < (x+(msize/blockcount)); ++i) {
                for (int j=y; j < (y+(msize/blockcount)); ++j) {
                    image.at<uchar>(i,j) = color;
                }
            }
            color += 256/(blockcount*blockcount);

        }
    }

    // write image to a file
	imwrite("grayscale.png", image);

    std::string name = std::to_string((int)(blockcount*blockcount)) + " shades of gray";

    // show the window of generated palette
	namedWindow( name, CV_WINDOW_AUTOSIZE);
	imshow( name, image);
    waitKey(0);

	return 0;
}

