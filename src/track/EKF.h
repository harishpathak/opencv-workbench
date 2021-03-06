#ifndef EXTENDED_KALMAN_FILTER_H_
#define EXTENDED_KALMAN_FILTER_H_
/// ----------------------------------------------------------------------------
/// @file EKF.h
/// @author Kevin DeMarco <kevin.demarco@gmail.com>
///
/// Time-stamp: <2015-10-05 13:26:08 syllogismrxs>
///
/// @version 1.0
/// Created: 16 Jan 2013
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
/// The EKF class ...
/// 
/// ----------------------------------------------------------------------------

#include <Eigen/Dense>

namespace syllo {
     class EKF {
     protected:
	  Eigen::MatrixXf F_; // System dynamics
	  Eigen::MatrixXf B_; // Control matrix
	  Eigen::MatrixXf H_; // Measurement matrix
	  
	  Eigen::MatrixXf R_; // Measurement variance
	  Eigen::MatrixXf Q_; // Process variance
	  
	  // Matrices / vectors for Kalman step
	  Eigen::MatrixXf x_; // Estimated state
	  Eigen::MatrixXf P_; // State variance matrix
	  Eigen::MatrixXf K_; // Kalman gain
	  Eigen::MatrixXf eye_;// = Eigen::Matrix<float, 2, 2>::Identity();

	  double dt_;

     public:
	  EKF();
	  EKF(const Eigen::MatrixXf &F, const Eigen::MatrixXf &B, 
	      const Eigen::MatrixXf &H, const Eigen::MatrixXf &Q, 
	      const Eigen::MatrixXf &R, double dt);
	  
	  int setModel(const Eigen::MatrixXf &F, const Eigen::MatrixXf &B, 
		       const Eigen::MatrixXf &H, const Eigen::MatrixXf &Q, 
		       const Eigen::MatrixXf &R, double dt);
	  
	  int init(const Eigen::MatrixXf &x0, const Eigen::MatrixXf &P0);

	  int predict(const Eigen::MatrixXf &u);
	  int update(const Eigen::MatrixXf &z);

	  Eigen::MatrixXf state();
	  Eigen::MatrixXf covariance();
     };
}


#endif
