#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

//	Класс Книга
class Book
{
    //закрытые поля класса
    //
    string name;	//	название книги
    string author;	//	автор
    double cost;	//	стоимость

public:

    //конструкторы

    Book(void)	// инициализирующий конструктор
    {			// без параметров name (Название)
        name = "Без названия";
        author = "Автор не указан";
        cost = 0;
        cout << " Создан новый объект класса с именем: " << name << "\n" << endl;
    }

    Book(string Name)	// инициализирующий конструктор
    {					// только Название
        if (Name.size() > 0) name = Name;
        else name = "Без названия";

        author = "Автор не указан";
        cost = 0;
        cout << " Создан новый объект класса с именем: " << name << "\n" << endl;
    }
    // инициализирующий конструктор
    // полностью
    //
    Book(string Name, string Author, double Cost)
    {
        if (Name.size() > 0) name = Name;
        else name = "Без названия";

        if (Author.size() > 0) author = Author;
        else author = "Автор не указан";

        if (Cost >= 0) cost = Cost;
        else cost = 0;

        cout << " Создан новый объект класса с именем: " << name
             << " автор: " << author << " стоимость: " << cost << "\n" << endl;
    }
    // копирующий конструктор
    //
    Book(const Book& ob)
    {
        name = ob.name;
        author = ob.author;
        cost = ob.cost;

        cout << " Скопирован объект класса с именем: " << name
             << " автор: " << author << " стоимость: " << cost << "\n" << endl;
    }

    ~Book()	// деструктор
    {
        cout << " Уничтожен объект класса с именем: " << name
             << " автор: " << author << " стоимость: " << cost << "\n" << endl;
    }


    // Функции (Методы)
    //

    // Вывод
    void print()
    {
        cout << "\n Вызвана функция вывода:\n"
             << "Класс с именем: " << name
             << " автор: " << author << " стоимость: " << cost << "\n" << endl;
    }
    //перзапись закрытых полей (сразу всех)
    //

    void SetBook(string Name, string Author, double Cost)
    {
        if ((Name.size() > 0) && (Author.size() > 0) && (Cost >= 0))
            cout << " Изменён старый объект класса с именем: " << name
                 << " автор: " << author << " стоимость: " << cost << "\n"
                 << " на новый объект класса с именем: " << Name
                 << " автор: " << Author << " стоимость: " << Cost << "\n" << endl;


        if (Name.size() > 0) name = Name;
        else cout << " Недопустимое значение для поля name: " << Name << "\n" << endl;

        if (Author.size() > 0) author = Author;
        else cout << " Недопустимое значение для поля author: " << Author << "\n" << endl;

        if (Cost >= 0) cost = Cost;
        else cout << " Недопустимое значение для поля cost: " << Cost << "\n" << endl;
    }

    //перзапись закрытого поля name
    //
    void Name(string str)
    {

        if (str.size() > 0)
        {
            cout << " Изменён старый объект класса с именем: " << name
                 << " author: " << author << " стоимость: " << cost << "\n"
                 << " на новый объект класса с именем: " << str
                 << " author: " << author << " стоимость: " << cost << "\n" << endl;

            name = str;
        }
        else cout << " Недопустимое значение для поля name: " << str << "\n" << endl;
    }
    //перзапись закрытого поля author
    //
    void Author(string x)
    {

        if (x.size() > 0)
        {
            cout << " Изменён старый объект класса с именем: " << name
                 << " количество: " << author << " стоимость: " << cost << "\n"
                 << " на новый объект класса с именем: " << name
                 << " количество: " << x << " стоимость: " << cost << "\n" << endl;

            author = x;
        }
        else cout << " Недопустимое значение для поля author: " << x << "\n" << endl;
    }


    //перзапись закрытого поля cost
    //
    void Cost(int x)
    {

        if (x >= 0)
        {
            cout << " Изменён старый объект класса с именем: " << name
                 << " автор: " << author << " стоимость: " << cost << "\n"
                 << " на новый объект класса с именем: " << name
                 << " автор: " << author << " стоимость: " << x << "\n" << endl;

            cost = x;
        }
        else cout << " Недопустимое значение для поля cost: " << x << "\n" << endl;
    }

    // считывание закрытых полей
    //

    string Name()		//Name связан с закрытым полем name
    {
        return name;
    }

    string Author()			//Author связан с закрытым полем author
    {
        return author;
    }

    int Cost()			//Cost связан с закрытым полем cost
    {
        return cost;
    }
};

int main()
{
    setlocale(0, "");
    // 1 - работа с массивом объектов класса
    //Создание массива объектов класса
    cout << "\nОбъявление массива объектов класса:\n";
    Book Lib[10];

    //Заполнение массива
    cout << "\nЗаполнение массива объектов класса:\n";
    Lib[0].SetBook("Мы", "Замятин", 500);
    Lib[1].SetBook("Заводной апельсин", "Стерджес", 100);
    Lib[2].SetBook("Три товарища", "Ремарк", 800);
    Lib[3].SetBook("1984", "Оруэлл", 200);
    Lib[4].SetBook("О дивный новый мир", "Хаксли", 50);
    Lib[5].SetBook("Преступление и наказание", "Достоевский", 1000);
    Lib[6].SetBook("Убить пересмешника", "Харпер Ли", 900);
    Lib[7].SetBook("Скотный двор", "Оруэлл", 10);
    Lib[8].SetBook("Теория всего", "Хоккинг", 250);
    Lib[9].SetBook("451 градус по фаренгейту", "Брэдберри", 210);
//Вывод массива
    cout << "\n\nВывод значений массива Lib:\n";
    for (int i = 0; i < 10; i++)
        Lib[i].print();


    //2 - работа с одиночнымы объектами класса 
    //

    cout << "\n1-Объявление без параметров:\n";
    Book Sad;				//1-Объявление без параметров

    cout << "\n2-Объявление с параметром name (имя), но с некорректным значением:\n";
    Book Error1("");		//2-Объявление с параметром name (имя), но с некорректным значением

    cout << "\n3-Объявление с параметром name (имя), но с допустимым значением:\n";
    Book G("велосипед");	//3-Объявление с параметром name (имя), но с допустимым значением

    cout << "\n4-Объявление со всеми параметрами, но с некорректным значением:\n";
    Book Error2("We", "", -100.0);	//4-Объявление со всеми параметрами, но с некорректным значением

    cout << "\n5-Объявление со всеми параметрами, но с допустимыми значениями:\n";
    Book H("сборник стихов", "не придумал", 3215);			//5-Объявление со всеми параметрами, но с допустимыми значениями

    Book K;

    cout << "\n6-копирование объекта класса:\n";
    K = H;						//6-копирование объекта класса

    cout << "\n7-преждевременное удаления объекта класса:\n";
    K.~Book();			//7-преждевременное удаления объекта класса


    cout << "\n8-Перезапись закрытого поля author для объекта класса:\n";
    H.Author("Серебкин");				//8-Перезапись закрытого поля author для объекта класса

    cout << "\n9-Неправильная перезапись поля author для объекта класса:\n";
    H.Author("");				//9-Неправильная перезапись поля author для объекта класса

    cout << "\n10-Перезапись закрытого поля name для объекта класса:\n";
    H.Name("Велосипе3.0");				//10-Перезапись закрытого поля name для объекта класса

    cout << "\n11-Неправильная перезапись поля name для объекта класса:\n";
    H.Name("");							//11-Неправильная перезапись поля name для объекта класса

    cout << "\n12-Перезапись закрытого поля cost для объекта класса:\n";
    H.Cost(10000);							//12-Перезапись закрытого поля cost для объекта класса

    cout << "\n13-Неправильная перезапись поля cost для объекта класса:\n";
    H.Cost(-100);							//13-Неправильная перезапись поля cost для объекта класса


    //14-Получение значение закрытого поля name
    cout << "\n14-Получение значение закрытого поля name:\n";
    cout << "H.Name=" << H.Name() << " \n";

    //15-Получение значение закрытого поля Author
    cout << "\n15-Получение значение закрытого поля Author:\n";
    cout << "H.Author=" << H.Author() << " \n";

    //16-Получение значение закрытого поля cost
    cout << "\n16-Получение значение закрытого поля cost:\n";
    cout << "H.Cost=" << H.Cost() << " \n";
    
    Book* a;							//17-Объявление ссылки на объект класса
    cout << "\n17-Объявление ссылки на объект класса:\n";
    a = new Book("Python", "", 0);

    cout << "\n18-Объявление ссылки на объект класса:\n";		//18-Перезапись закрытого поля через ссылку на объект
    a->Author("Кто-то");


    cout << "\n18-Объявление ссылки на объект класса:\n";		//18-Получение значение закрытого поля через ссылку на объект
    cout << "a->Author=" << a->Author() << " \n";

    cout << "\n19-преждевременное удаления объекта класса:\n";	//19-преждевременное удаления объекта класса
    delete a;

    system("pause");
    cout << " \n";

    cout << "\n20-Удаление всех объектов, после работы программы:\n";

    return 0;
}


