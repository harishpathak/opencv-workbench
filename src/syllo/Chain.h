#ifndef CHAIN_H_
#define CHAIN_H_
/// ----------------------------------------------------------------------------
/// @file Chain.h
/// @author Kevin DeMarco <kevin.demarco@gmail.com>
///
/// Time-stamp: <2013-11-01 17:02:21 syllogismrxs>
///
/// @version 1.0
/// Created: 01 Nov 2013
///
/// ----------------------------------------------------------------------------
/// @section LICENSE
/// 
/// The MIT License (MIT)  
/// Copyright (c) 2012 Kevin DeMarco
///
/// Permission is hereby granted, free of charge, to any person obtaining a 
/// copy of this software and associated documentation files (the "Software"), 
/// to deal in the Software without restriction, including without limitation 
/// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
/// and/or sell copies of the Software, and to permit persons to whom the 
/// Software is furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in 
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
/// DEALINGS IN THE SOFTWARE.
/// ----------------------------------------------------------------------------
/// @section DESCRIPTION
/// 
/// The Chain class ...
/// 
/// ----------------------------------------------------------------------------

#include <cv.h>

#include <yaml-cpp/yaml.h>

namespace syllo{
     
     class Chain {
     private:
     protected:
          YAML::Node config_;

          /** Function Headers */
          void DetectFace( cv::Mat &src, cv::Mat &dest);

          cv::CascadeClassifier face_cascade;
          cv::CascadeClassifier eyes_cascade;          
          cv::RNG *rng;

     public:
          Chain();
          Chain(const std::string &filename);
          int LoadFile(const std::string &filename);
          int Process(const cv::Mat &src, cv::Mat &dest);
     };

}
#endif
