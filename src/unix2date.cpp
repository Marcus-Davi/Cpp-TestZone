#include <iostream>
#include <ctime>
#include "boost/date_time/posix_time/posix_time.hpp"



int main()
{
    
boost::posix_time::ptime my_posix_time = ros::Time::now().toBoost();
std::string iso_time_str = boost::posix_time::to_iso_extended_string(my_posix_time)

}