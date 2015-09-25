#ifndef ENTITY_H_
#define ENTITY_H_
/// ---------------------------------------------------------------------------
/// @file Entity.h
/// @author Kevin DeMarco <kevin.demarco@gmail.com>
///
/// Time-stamp: <2015-09-25 17:00:22 syllogismrxs>
///
/// @version 1.0
/// Created: 25 Sep 2015
///
/// ---------------------------------------------------------------------------
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
/// ---------------------------------------------------------------------------
/// @section DESCRIPTION
/// 
/// The Entity class ...
/// 
/// ---------------------------------------------------------------------------
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"

#include <opencv_workbench/wb/Point.h>

namespace wb {

     class Entity {
     public:
          Entity();

          void set_id(int id) { id_ = id; }
          int id() { return id_; }
          
          void compute_metrics();

          cv::Point centroid();
          cv::Rect rectangle();

          void set_centroid(cv::Point p) { centroid_ = p; }

          // Point related
          std::vector<wb::Point> & points() { return points_; }
          int size() { return points_.size(); }
          void add_point(wb::Point &p) { points_.push_back(p); }
          void remove_point(wb::Point &p);
               
          // Age related functions
          void inc_age();
          void dec_age();
          int age() { return age_; }
          void set_age(int age) { age_ = age; }          
          bool is_visible();
          bool is_dead();
          
     protected:
          int id_;          
          std::vector<wb::Point> points_;
          cv::Point centroid_;
          cv::Point est_centroid_;
          cv::Rect rectangle_;
          int age_;
     private:
     };

}

#endif
