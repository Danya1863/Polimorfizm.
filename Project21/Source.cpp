#include <iostream>
#include "Header.h"
#include "Header1.h"

using namespace std;
using namespace Military;
using namespace Transport;

int main()
{
	Base obj(200, 200, 5000, 9000);
	obj.Print();
	Vehicle* obj2 = nullptr;
	obj2 = new Truck(150, 100, 2500, 1050);
	cout << endl;
	obj2->Print();
	obj2->leave(obj);
	cout << endl;
	obj.Print();
	cout << endl;
	obj2->Print();
	obj2->arrive(obj);
	cout << endl;
	obj.Print();
	cout << endl;
	obj2->Print();
}