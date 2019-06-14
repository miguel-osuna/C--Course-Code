#include <iostream>
using namespace std;

int *create_array(size_t size, int init_value= 0) //Starts in 0 by default
{
    //We allocate a new pointer to be returned
    int *buffer_array {nullptr};
    buffer_array = new int[size];

    for(size_t i = 0; i < size; i++)
        *(buffer_array + i) = init_value;

    return buffer_array; //El apuntador apunta a memoria asignada en el heap, por lo tanto                          //no es considerada como una variable local
}

void print_array(const int *array, size_t size)
{
    for(size_t i = 0; i < size; i++)
        cout << array[i] << endl;
    return;
}

int main()
{
    size_t size {10};
    int init_value {20};
    int *new_array {nullptr};

    new_array = create_array(size, init_value);
    
    print_array(new_array, size);

    delete [] new_array; //After using the array, we have to free it for the storage
}