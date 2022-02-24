# Класс Книга
class Book:
    # условно закрытые поля класса
    __name = ""  # имя книга
    __author = ""  # автор
    __cost = 0.0  # стоимость

    # Инициализатор

    # полностью
    def __init__(self, name=None, author=None, cost=None):
        # начальное задание значений, если вход. параметры будут некорректны
        self.__name = "без имени"
        self.__author = "автор не указан"
        self.__cost = 0.0

        if name is not None:
            if isinstance(name, str):  # является ли name - строк. типом
                if len(name) > 0:
                    self.__name = name

        if author is not None:
            if isinstance(author, str):  # является ли author - строк. типом
                if len(author) > 0:
                    self.__author = author

        if cost is not None:
            if isinstance(cost, float):  # является ли cost - веществ. типом
                if cost >= 0:
                    self.__cost = cost

        print(" Создан новый объект класса с именем: ", self.__name,
              " : ", self.__author, " стоимость: ", self.__cost)

    # деструктор
    def __del__(self):
        print(" Уничтожен объект класса с именем: ", self.__name,
              " автор: ", self.__author, " стоимость: ", self.__cost)

    # Функции (Методы)

    # Вывод
    def print(self):
        print("\n Вызвана функция вывода:\n"
              , "Класс с именем: ", self.__name,
              " автор: ", self.__author, " стоимость: ", self.__cost)

    # перзапись закрытых полей (сразу всех)
    def SetBook(self, Name, Author, Cost):
        if isinstance(Name, str) and isinstance(Author, int) and isinstance(Cost, float):
            if len(Name) > 0 and Author >= 0 and Cost >= 0:
                print(" Изменён старый объект класса с именем: ", self.__name,
                      " автор: ", self.__author, " стоимость: ", self.__cost, "\n",
                      "на новый объект класса с именем: ", Name,
                      " автор: ", Author, " стоимость: ", Cost)

            if len(Name) > 0:
                self.__name = Name
            else:
                print(" Недопустимое значение для поля name: ", Name)

            if len(Author) > 0:
                self.__author = Author
            else:
                print(" Недопустимое значение для поля author: ", Author)

            if Cost >= 0:
                self.__cost = Cost
            else:
                print(" Недопустимое значение для поля cost: ", Cost)
        else:
            print(" Введены недопустимые значения для полей класса ")

    # перзапись закрытого поля name и
    def Name(self, x=None):
        if x != None:
            if isinstance(x, str):
                if (len(x) > 0):
                    print(" Изменён старый объект класса с именем: ", self.__name,
                          " : ", self.__author, " стоимость: ", self.__cost, "\n",
                          " на новый объект класса с именем: ", x,
                          " автор: ", self.__author, " стоимость: ", self.__cost)

                    self.__name = x
                else:
                    print(" Недопустимое значение для поля name: ", x)
            else:
                print(" Недопустимое значение для поля name: ", x)
        else:
            # считывание закрытого поля name
            return self.__name

    # перзапись закрытого поля author
    def Author(self, x=None):
        if x != None:
            if isinstance(x, int):
                if (x > 0):
                    print(" Изменён старый объект класса с именем: ", self.__name,
                          " автор: ", self.__author, " стоимость: ", self.__cost, "\n",
                          " на новый объект класса с именем: ", self.__name,
                          " автор: ", x, " стоимость: ", self.__cost)

                    self.__author = x
                else:
                    print(" Недопустимое значение для поля author: ", x)
            else:
                print(" Недопустимое значение для поля author: ", x)
        else:
            # считывание закрытого поля author
            return self.__author

    # перзапись закрытого поля cost
    def Cost(self, x=None):
        if x != None:
            if isinstance(x, float):
                if (x > 0):
                    print(" Изменён старый объект класса с именем: ", self.__name,
                          " автор: ", self.__author, " стоимость: ", self.__cost, "\n",
                          " на новый объект класса с именем: ", self.__name,
                          " автор: ", self.__author, " стоимость: ", x)

                    self.__cost = x
                else:
                    print(" Недопустимое значение для поля cost: ", x)
            else:
                print(" Недопустимое значение для поля cost: ", x)
        else:
            # считывание закрытого поля cost
            return self.__cost


# Пример работы с классом

# 1 - работа с массивом объектов класса

# Создание 10 объектов
A1 = Book("Мы", "Замятин", 500.0)
A2 = Book("Заводной апельсин", "Стерджес", 100.0)
A3 = Book("Три книгаища", "Ремарк", 800.0)
A4 = Book("1984", "Оруэлл", 200.0)
A5 = Book("О дивный новый мир", "Хаксли", 50.0)
A6 = Book("Преступление и наказание", "Достоевский", 1000.0)
A7 = Book("Убить пересмешника", "Харпер Ли", 900.0)
A8 = Book("Скотный двор", "Оруэлл", 10.0)
A9 = Book("Теория всего", "Хоккинг", 250.0)
A10 = Book("451 градус по фаренгейту", "Брэдберри", 210.0)

# Заполнение массива
Mas = [A1, A2, A3, A4, A5, A6, A7, A8, A9, A10]

# Вывод массива
for i in range(10):
    Mas[i].print()

# 2 - работа с одиночными объектами класса

print("\n1-Объявление без параметров:")
F = Book()

print("\n2-Объявление с параметром name (имя), но с некорректным значением:")
Error1 = Book("")

print("\n3-Объявление с параметром name (имя), но с допустимым значением:")
G = Book("korona")

print("\n4-Объявление со всеми параметрами, но с некорректным значением:")
Error2 = Book("Скейтборд", "", -100.0)

print("\n5-Объявление со всеми параметрами, но с допустимыми значениями:")
H = Book("sabaka", "sa", 3215.0)

print("\n6-полная перезапись полей объекта")
F.SetBook("велосипед", "сантехник", 3215.0)

print("\n7-копирование объекта")
K = F
K.print()

print("\n8-преждевременное удаления объекта класса:")
K.__del__()

print("\n9-Перезапись закрытого поля author для объекта класса:")
H.Author("www")

print("\n10-Неправильная перезапись поля author для объекта класса:")
H.Author("")

print("\n11-Перезапись закрытого поля name для объекта класса:")
H.Name("Велосипед 2.0")

print("\n12-Неправильная перезапись поля name для объекта класса:")
H.Name("")

print("\n13-Перезапись закрытого поля cost для объекта класса:")
H.Cost(10000.0)

print("\n14-Неправильная перезапись поля cost для объекта класса:")
H.Cost(-100.0)

print("\n15-Получение значение закрытого поля name:")
print("H.Name=", H.Name())

print("\n16-Получение значение закрытого поля author:")
print("H.author=", H.Author())

print("\n17-Получение значение закрытого поля cost:")
print("H.Cost=", H.Cost())

print("\nПауза, введите любой текст:")
input()  # пауза

print("\n\n18-Удаление всех объектов, после работы программы:\n")
