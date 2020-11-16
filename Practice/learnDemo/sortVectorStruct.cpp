#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <cmath>
#include <gflags/gflags.h>
#include <set>
#include <mutex>
#include <limits>
#include <vector>
#include <algorithm>
#include "spline.h"

// DEFINE_double(dheading, 0.5, "the heading value");

using namespace std;

typedef struct PathPoint_
{
    double x;
    double y;
    double z;
}PathPoint;

int main(int argc, char** argv)
{
    vector<PathPoint> aaa;
	PathPoint temp;
	temp.x=1;
	temp.y=1;
	aaa.push_back(temp);
	temp.x=2;
	temp.y=1;
	aaa.push_back(temp);	
	temp.x=3;
	temp.y=1;
	aaa.push_back(temp);

    temp.x=0.5;
	temp.y=1;
	aaa.push_back(temp);

     temp.x = 2.4;
	temp.y = 1;
	aaa.push_back(temp);

    static auto comp = [](const PathPoint& pointA, const PathPoint& pointB) {
        return pointA.x < pointB.x;
    };


	sort(aaa.begin(),aaa.end(), comp);//升序排列
    cout<<"Less Sort:"<<endl;
    vector<double> vx;
    vector<double> vy;
	for (auto &element : aaa)
	{
		cout<<element.x<<"	"<< element.y<<endl;
        vx.push_back(element.x);
        vy.push_back(element.y);
	}

    tk::spline s;
    s.set_points(vx, vy);    // currently it is required that X is already sorted
    
    double x=10.05;
    printf("spline at %f is %f\n", x, s(x));
    //gflags的使用
//	gflags::ParseCommandLineFlags(&argc, &argv, true);
//	Eigen::Quaternion<double> q;
//	yaw2Quaternionon(FLAGS_dheading, q);
//	double heading = 0.0;
//	Quaternionon2yaw(q, heading);
//	printf("heading = %f, dheading=%f\n", heading, FLAGS_dheading);
//	 gflags::ShutDownCommandLineFlags();


	return 0;
}
 
