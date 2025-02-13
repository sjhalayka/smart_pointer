// https://www.geeksforgeeks.org/smart-pointers-cpp/


#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


class person
{
public:
	string name = "Test";
	int age = 123;
};


// A test function taking in a pointer as a parameter, like many C functions do
void test_function(person* persons, size_t num_persons)
{
	if (num_persons > 0)
		cout << persons[0].name << endl;
}


int main(void)
{
	size_t array_size = 100;

	// C++ raw pointer method
	person* raw_ptr = new person[array_size];
	cout << raw_ptr[0].age << endl;
	test_function(&raw_ptr[0], array_size);
	delete[] raw_ptr; // Manual release required

	// Smart pointer method
	unique_ptr<person[]> smart_ptr = make_unique<person[]>(array_size);
	cout << smart_ptr[0].age << endl;
	test_function(&smart_ptr[0], array_size);

	// Vector method
	vector<person> vp(array_size);
	cout << vp[0].age << endl;
	test_function(&vp[0], array_size);

	// Both u_ptr and vector will automatically release their memory here,
	// as they go out of scope
	return 0;
}

