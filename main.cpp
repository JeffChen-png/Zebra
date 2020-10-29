#include <iostream>
#include "AVL.h"

using namespace avl;
using namespace std;
using namespace atl;

int main() {

    Image img1;
    LoadImage("/home/rustam/zebra.jpg",false, img1);

    Image hsv_img;
    RgbToHsv(img1, hsv_img);

    Image img2;

    //EqualizeImageHistogram(img, atl::NIL ,0.8, 0.8, img2);

    //DetectLinePeak(img, LinePeakDetectionMethod::MaximalPixel, 128.0f, );

    SaveImageToJpeg(img2,"/home/rustam/zebra_mode.jpg", NIL, false);


    return 0;
}