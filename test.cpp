#include <iostream>

class MyClass
{
private:
    int sizeOf;
public:
    int* data;

    MyClass(int size)
    {
        this->sizeOf = size;
        this->data = new int[size];

        for (int i = 0; i < size; ++i)
        {
            data[i] = i;
        }
        std::cout << "Constructor " << this << std::endl;
    }

    MyClass(const MyClass& other) //Конструктор копирования
    {
        this->sizeOf = other.sizeOf;

        this->data = new int[other.sizeOf];
        for (int i = 0; i < other.sizeOf; ++i)
        {
            this->data[i] = other.data[i];
        }
        std::cout << "Constructor copy" << this << std::endl;
    }
    ~MyClass()
    {
        std::cout << "Destructor" << this << std::endl;
        delete[] data;
    }
};

int main()
{
    MyClass a(10);
    MyClass b(a);

    return 0;
}