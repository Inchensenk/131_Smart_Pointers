// 131_Smart_Pointers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//https://www.youtube.com/watch?v=dpRozfXepnA

#include <iostream>
#include <string>
#include <memory> //содержит классы указателей auto_ptr//unique_ptr//shared_ptr
using namespace std;
/*
* 
* smart pointers
* auto_ptr - устарел, похож на unique_ptr
* unique_ptr- уникальный указатель
* shared_ptr - общий указатель, может хранить множество указателей на 1 объект

*/

template<typename T>
class SmartPointer
{
public:
    SmartPointer(T* ptr)
    {
        this->ptr = ptr;
        cout << "Constructor" << endl;
    }

    ~SmartPointer()
    {
        delete ptr;
        cout << "Destructor" << endl;
    }

    T& operator*()
    {
        return *ptr;
    }
private:
    T* ptr;
};

int main()
{
    setlocale(LC_ALL, "ru");
    //nen решается проблема, то есть возможность владения несколькими разными указателями одним и тем же объектом в динамической памяти
    shared_ptr<int> p1(new int(5));

    shared_ptr<int> p2(p1)

    /*
    //unique_ptr- уникальный умный указатель, поэтому невозможно одному уникальному указателю передать другой
    unique_ptr<int> p1(new int(5));
    //для того чтобы сменить владельца данных нужно использовать функцию std::move 
    unique_ptr<int> p2;
    //результат работы функции move присваиваем переменной p2? а параметром передаем первый указатель p1
    //p2 = move(p1);// но она не решает проблему
    // 
    //можно использовать собсвенную функцию уникальног указателя swap как аналог метода move

    p2.swap(p1);

    //метод get возвращает указатель в его сыром чистом виде
    //тоесть вытянем из unique_ptr простой приметивный указатель
    int* p = p1.get();
    */
    /*auto_ptr<int> ap1(new int(5));

    auto_ptr<int> ap2(ap1);*/

    /*
        //создается первый умный указатель, который указывает на область памяти с переменной 5
    SmartPointer<int> sp1 = new int(5);
    //создается второй умный указатель, который ссылается на первый умный указатель
    //при уничтожении деструктором первого указателя с данными выдет ошибка так как второй указатель ссылается на первый
    SmartPointer<int> sp2 = sp1;
    //эти проблемы решают *auto_ptr//*unique_ptr//* shared_ptr
    */
    
}

