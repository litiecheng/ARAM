/*
Copyright (c) 2014, Altran Research Medic@
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by Altran.
4. Neither the name of Altran nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY ALTRAN RESEARCH MEDIC@ ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ALTRAN RESEARCH MEDIC@ BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/





/**
*
* \file Intrinsics.hpp
* \brief Contains camera matrix and distorsion coefficients
* \author Alexandre Kornmann
* \version 1.0
* \date 10 avril 2014
* 
*/
#ifndef _INTRINSICS_HPP_
#define _INTRINSICS_HPP_


//std include
#include <string>
#include <fstream>
#include <iostream>
#include <ios>

//Open CV include
#include <opencv2/opencv.hpp>

//ARAM include
#include <ARAM/export.hpp>
#include <ARAM/typedef.hpp>
#include <ARAM/ARAMException.hpp>

namespace aram
{
	/**
	* Contains camera matrix and distorsion coefficients
	*/
	class ARAM_EXPORT Intrinsics
	{
	public :
		/**
		* Constructor
		*
		* \param[in] std::string file xml path file with parameters (openCV format)
		*/
		Intrinsics(const std::string);

		
		/**
		* Getter, called by constructor
		*
		* \param[in] std::string file xml path file with parameters (openCV format)
		*/
		void load(const std::string);


		/**
		* Getter
		*
		* \return cv::Mat & camera matrix
		*/
		const cv::Mat & cameraMatrix();


		/**
		* Getter
		*
		* \return cv::Mat & distorsion coefficients
		*/
		const cv::Mat & distorsionCoefficient();


		/**
		* \return bool true if camera matrix and distortion coefficients are filled
		*/
		bool valid();

		
		void argConvGLcpara2( double cparam[3][4], int width, int height, double gnear, double gfar, double m[16], bool invert);
		void glGetProjectionMatrix( cv::Size orgImgSize, cv::Size size,double proj_matrix[16],double gnear,double gfar,bool invert);

	private :
		cv::Mat _cameraMatrix; /**< camera matrix coefficients */ 
		cv::Mat _distorsionCoefficient; /**<distorsion coefficients */
	};
};

#endif