#include <iostream>
#include <xmmintrin.h>

#include <chrono>

#define N_OPTS 4*50000000



void print(__m128 pkt){

	std::cout << "{" << pkt[0] <<  "," << pkt[1] << ","  << pkt[2] <<   "," << pkt[3] <<  "}" << std::endl;

}






int main(){
	float *array = new float[N_OPTS]();
	float *res = new float[N_OPTS];
	float *res_sse = new float[N_OPTS];
__m128* a = (__m128*)array;
__m128* res_ = (__m128*)res_sse;

for(int i=0;i<N_OPTS;++i){
array[i] = 10 * (float) rand() / (float) RAND_MAX;
	//std::cout << "array = " << array[i] << std::endl;
}

// normal
std::chrono::steady_clock::time_point start,end;

start = std::chrono::steady_clock::now();
for(int i=0;i<N_OPTS;++i){
	res[i] = array[i]*array[i];
	//std::cout << "res = " << res[i] << std::endl;
}
end = std::chrono::steady_clock::now();

std::cout << "Normal duration = " << std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count() << "[ms]" << std::endl;


// sse support
start = std::chrono::steady_clock::now();
int N_4 = N_OPTS / 4;
for(int i=0;i<N_4;++i){
	*res_ = _mm_mul_ps(*a,*a);
	a++;
	res_++;
}
end = std::chrono::steady_clock::now();

std::cout << "SSE duration = " << std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count() << "[ms]" << std::endl;

// so printa 
for(int i=0;i<N_OPTS;++i){
//	std::cout << "res_sse = " << res_sse[i] << std::endl;
}





}





