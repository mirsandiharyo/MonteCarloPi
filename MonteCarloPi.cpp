/*
 * MonteCarlo.cpp
 *
 *  Created on: Jun 13, 2020
 *      Author: mirsandiharyo
 */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"

/**
 * \brief Estimate the value of Pi using Monte Carlo method.
 * The code will generate a large number of random points and
 * see how many fall inside the circle enclosed by the unit square.
*/

int main()
{
	int point_x = 0;
	int point_y = 0;
	int distance = 0;
	int tot_point = 0;
	int tot_inside = 0;
	int tot_sample = 0;
	int diameter = 400;
	int radius = 0.5*diameter;
	long double pi = 0;
	long double pi_exact = 3.14159265358979;
	cv::Mat frame(cv::Size(diameter,diameter),CV_8UC3,cv::Scalar(255,255,255));
	cv::circle(frame,cv::Point(radius,radius),radius,cv::Scalar(0,0,0),2);

	std::cout << "Estimate the value of Pi using Monte Carlo method." << std::endl;
	std::cout << "Please enter the total sample size: ";
	std::cin >> tot_sample;

	while(tot_point < tot_sample)
	{
	    /*
	     * \brief Generate a random point and calculate the distance from center
	     */
		tot_point++;
		point_x = rand()%diameter-radius;
		point_y = rand()%diameter-radius;
		distance = sqrt(pow(point_x,2)+pow(point_y,2));
		point_x = point_x+radius;
		point_y = point_y+radius;

	    /*
	     * \brief Draw the circle and points
	     */
		if(distance < radius){
			tot_inside++;
			cv::circle(frame,cv::Point(point_x,point_y),1,cv::Scalar(0,0,255),2);
		}
		else{
			cv::circle(frame,cv::Point(point_x,point_y),1,cv::Scalar(255,0,0),2);
		}
		imshow("Estimate the value of pi using Monte carlo method",frame);
		cv::waitKey(1);

	    /*
	     * \brief Estimate the value of pi
	     */
		pi = (4*double(tot_inside))/(double(tot_point));
		if(tot_point%100 == 0)
			std::cout << "Pi = " << pi << std::endl;
	}
	std::cout << "Final value of Pi = " << pi << std::endl;
	std::cout << "Error = " << fabs(100*(pi - pi_exact)/pi_exact) << "%" << std::endl;

	return 0;
}
