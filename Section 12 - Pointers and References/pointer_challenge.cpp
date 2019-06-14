#include <iostream>
using namespace std;

int *apply_all(int *array1, size_t size1, int *array2, size_t size2);
void print(const int *const arr, size_t size);

int main()
{
	//In this first part, we ask the user for the size and content of his arrays
	size_t size1 {0};
	size_t size2 {0};
	int number {0};

	cout << "Please enter the size of your first array: ";
	cin >> size1;
	int array1[size1] {0};

	cout << "Please enter the numbers of your first array: " << endl;
	for(size_t i = 0; i < size1; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> number;
		array1[i] = number;
	}
	cout << endl;

	cout << "Please enter the size of your second array: ";
	cin >> size2;
	int array2[size2] {0};

	cout << "Please enter the numbers of your second array: " << endl;
	for(size_t i = 0; i < size2; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> number;
		array2[i] = number;
	}
	cout << endl;
	
	//We create a local scope array for the apply_all function
	int *new_array {nullptr};

	cout << "Displaying the users arrays" << endl;
	print(array1, size1);
	print(array2, size2);

	new_array = apply_all(array1, size1, array2, size2);
	print(new_array, size1 * size2);

	//We free the memory allocated for the pointer
	delete [] new_array;
	return 0;
}

//Si pasamos un apuntador a la funcion apply_all, e implementamos la funcion sizeof, nos dara el tamano del APUNTADOR, y no del ARREGLO
int *apply_all(int *array1, size_t size1, int *array2, size_t size2)
{
	int *new_array {nullptr};
	new_array = new int[size1 * size2];

	for(size_t i = 0; i < size1; i++)
		for(size_t j = 0; j < size2; j++)
			*(new_array + i + j + size1 * i) = *(array1 + i) * *(array2 + j);

	return new_array;
}

void print(const int *const arr, size_t size)
{
	for(size_t i = 0; i < size; i++)
		cout << "array[" << i << "] = " << arr[i] << endl; //It can also be *(array + i)
	cout << endl;
	return;
}