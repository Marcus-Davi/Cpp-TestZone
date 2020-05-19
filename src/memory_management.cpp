// Inspired by the Cherno
#include <iostream>



class AllocationMetrics 
{
	private:
	static uint32_t TotalAllocated;
	static uint32_t TotalFreed;
	static uint32_t TotalAllocated_;

	public:
static void	Accum(size_t size){
		TotalAllocated+=size;
}
static void Freed(size_t size){
		TotalFreed+= size;
}
static uint32_t getTotalAllocated(){return TotalAllocated;};
static uint32_t getTotalFreed(){return TotalFreed;};
static uint32_t getCurrentUsage(){return TotalAllocated - TotalFreed;};
};

uint32_t AllocationMetrics::TotalFreed = 0;
uint32_t AllocationMetrics::TotalAllocated = 0;

void* operator new(size_t size){

	// std::cout << "Allocating " << size << " bytes \n";
	AllocationMetrics::Accum(size);
	return malloc(size);
}
void * operator new[](size_t size){
	
		AllocationMetrics::Accum(size);
return malloc(size);
}
void operator delete(void* memory, size_t size){

	// std::cout << "Freeing " << size << "bytes \n";
		AllocationMetrics::Freed(size);
	//std::cout << "delete () \n";
	free(memory);
}
void operator delete[](void* memory){ //Como rastrear dessa aqui ?
		//std::cout << "delte [] 1 \n";
		free(memory);
}
void operator delete[](void* memory, size_t size){


		AllocationMetrics::Freed(size);
	std::cout << "delete [] \n";
	free(memory);

}

struct Object {
		int x,y,z;
};

void PrintMemoryUsage(){
		std::cout << "Memory Usage = " << AllocationMetrics::getCurrentUsage() << " bytes \n";
}
int main(){
	std::cout << "Memory management test" << std::endl;
	PrintMemoryUsage();
	std::string str = "Marcus";
	Object* obj = new Object;
	PrintMemoryUsage();
	float* float_array = new float[100];
	PrintMemoryUsage();
	delete(obj);
	PrintMemoryUsage();
	delete[] float_array;
	PrintMemoryUsage();
}



