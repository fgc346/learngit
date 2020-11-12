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

DEFINE_double(dheading, 0.5, "the heading value");

using namespace std;
 //const double kAngle = dheading;
void yaw2Quaternionon(const double heading,  Eigen::Quaternion<double>  &q)
{
	Eigen::AngleAxisd rotation_vector(heading, Eigen::Vector3d(0,0,1));
	Eigen::Quaternion<double> temp_q(rotation_vector);
	q = temp_q;
}

void Quaternionon2yaw(const Eigen::Quaternion<double> &q, double &heading)
{
			// roll (x-axis rotation)
	    double roll = 0.0;
		double sinr_cosp = +2.0 * (q.w() * q.x() + q.y() * q.z());
		double cosr_cosp = +1.0 - 2.0 * (q.x() * q.x() + q.y() * q.y());
                 roll = atan2(sinr_cosp, cosr_cosp);

		// pitch (y-axis rotation)
	    double pitch = 0.0;
		double sinp = +2.0 * (q.w() * q.y() - q.z() * q.x());
		if (fabs(sinp) >= 1)
		pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
		else
		pitch = asin(sinp);

		// yaw (z-axis rotation)
		double siny_cosp = +2.0 * (q.w() * q.z() + q.x() * q.y());
		double cosy_cosp = +1.0 - 2.0 * (q.y() * q.y() + q.z() * q.z());
		heading = atan2(siny_cosp, cosy_cosp);
}
class A
{
public:
    std::set<std::string>* mpSetName;
    std::mutex* mpmuxPlate;
    std::string strID;
    A(std::set<std::string>* pSetName, std::mutex* pmuxPlate)
    {
        mpSetName = pSetName;
        mpmuxPlate = pmuxPlate;
    }
};

int main(int argc, char** argv)
{

    std::cout << " std::numeric_limits<double>::min()= " << std::numeric_limits<double>::min()/(-180) << std::endl;
//	gflags::ParseCommandLineFlags(&argc, &argv, true);
//	Eigen::Quaternion<double> q;
//	yaw2Quaternionon(FLAGS_dheading, q);
//	double heading = 0.0;
//	Quaternionon2yaw(q, heading);
//	printf("heading = %f, dheading=%f\n", heading, FLAGS_dheading);
//	 gflags::ShutDownCommandLineFlags();
    std::set<string> setName;
    std::mutex mux;

    {

//        std::unique_lock<std::mutex> lock(*(a1.mpmuxPlate));
        A a1(&setName,&mux);
        std::string strA("aaa");
        a1.mpSetName->insert(strA);
        a1.strID = "nihao";
    }

    {
        A a2(&setName,&mux);
        //std::unique_lock<std::mutex> lock(*a2.mpmuxPlate);
        a2.mpSetName->insert("bbb");
    }
    //a2.mpSetName->insert("bbb");
    //printf("mpSetName.size = %d\n", (int)a2.mpSetName->size());
    printf("hello,world,setName.size=%d\n",/*a1.strID.data()*/ (int)setName.size());
	return 0;
}
 
