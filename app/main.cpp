#include "manager.hpp"

int main(){
	using namespace info_pair;
	Manager m{"../json/long.json"};
	m.run();
   return 0; 
}