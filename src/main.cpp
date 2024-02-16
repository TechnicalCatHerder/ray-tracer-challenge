#include "tuple.h"


int main() {

	Tuple my_tuple(1.0f, 2.0f, 3.0f, 4.0f);
	Tuple my_vector = Vector(3.0f, 2.0f, 1.0f);

	my_vector.GetX();
	my_tuple.GetX();

	return 0;
}