#include <iostream>

using namespace std;

int main()
{
	char name[] {"Miguel"};
	char *name_ptr1 {nullptr};
	char *name_ptr2 {nullptr};

	//Substracting pointer addresses to see the difference between the number
	name_ptr1 = &name[0];
	name_ptr2 = &name[sizeof(name) - 1];
	cout << "You name is: " << name_ptr2 - name_ptr1 << " characters long" << endl;

	//Cuando no derreferenciamos el arreglo o apuntador de caracteres, estos desplegan toda la cadena
	cout << &name[0] << endl;
	cout << name_ptr1 << endl;

	//Y cuando si derreferenciamos el arreglo o apuntador de tipo char, estos despliegan solo el contenido de la direccion de memoria
	cout << *&name[0] << endl;
	cout << *name_ptr1 << endl;

	return 0;
}