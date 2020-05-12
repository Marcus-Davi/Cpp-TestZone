#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
std::vector<size_t> get_cpu_times() {
    std::ifstream proc_stat("/proc/stat");
    proc_stat.ignore(5, ' '); // Skip the 'cpu' prefix.
    std::vector<size_t> times;
    for (size_t time; proc_stat >> time; times.push_back(time));
    return times;
}
bool get_cpu_times(size_t &idle_time, size_t &total_time) {
    const std::vector<size_t> cpu_times = get_cpu_times();
    if (cpu_times.size() < 4)
        return false;
    idle_time = cpu_times[3];
//    total_time = std::accumulate(cpu_times.begin(), cpu_times.end(), 0);
	total_time = 0;
	std::vector<size_t>::const_iterator  it;
	for(it = cpu_times.begin();it<cpu_times.end();++it){
	total_time += *it;	
	
	}
    return true;
}

int main(){

		size_t previous_idle= 0,previous_total= 0;
		std::vector<size_t > times = get_cpu_times();
		float delta_idle,delta_total;
//		for(int i=0;i<times.size();++i){
//		std::cout << times[i] << std::endl;
//		}
		size_t idle,total;

		//for(int i=0;i<10;++i)
		while(1)
		{
		
		get_cpu_times(idle,total);
		sleep(1);
		delta_idle = idle - previous_idle;
		delta_total = total - previous_total;
		if(previous_idle != 0)
		std::cout <<  1.0 - (delta_idle / delta_total ) << std::endl;
		previous_idle = idle;
		previous_total = total;
		
		
		}
}

