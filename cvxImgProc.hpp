//
//  cvxImgProc.hpp
//  RGB_RF
//
//  Created by jimmy on 2016-06-02.
//  Copyright © 2016 jimmy. All rights reserved.
//

#ifndef cvxImgProc_cpp
#define cvxImgProc_cpp

#include <stdio.h>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/features2d.hpp"
#include <opencv2/line_descriptor.hpp>

using std::vector;
using cv::Mat;

class CvxImgProc
{
public:
    // gradient orientation in [0, 2 * pi)
    static Mat gradientOrientation(const Mat & img, const int gradMagThreshold = 0);
    
    // centroid orientation (as in ORB) https://en.wikipedia.org/wiki/Image_moment
    // ouput: angles atan2(m01, m10)
    static void centroidOrientation(const Mat & img, const vector<cv::Point2d> & pts, const int patchSize,
                                    vector<float> & angles);
    
    // patchSize:  patch size to calcualte orientation
    // smoothSize: Gaussian kernal size in pixel
    // smooth orientation using Gaussian filter
    static void centroidOrientation(const Mat & img, const int patchSize, const int smoothSize, Mat & orientation);
    
    // put patches into a single image, patch has same size
    // rowNum: how many patches in a column
    static Mat groupPatches(const vector<cv::Mat> & patches, int colNum);
    
    // left side of line should be brighter than right side area
    static bool estimateLineOrientation(const Mat& gry_img, const cv::Point2d & startPoint,
                                        const cv::Point2d & endPoint,const int line_width);
    
    
};

#endif /* cvxImgProc_cpp */
