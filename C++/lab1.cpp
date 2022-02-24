#include <iostream>
#include <vector>

class Quest1
{
    public:
        int _number;
        int _index;
        int _count = 0;
        int _digit;
        std::vector<int> _divider_arr;
        static void setupForConsole()
        {
            Quest1 q1;
            q1.inputNumberAndIndex();
            q1.digitCount();
            q1.sliceDigitByIndex();
            std::cout << "Число по индексу " << q1._index << ": " << q1._digit << std::endl;

            q1.inputDividers();
            q1.checkDivisibility();
        }

        void inputNumberAndIndex()
        {
            std::cout << "Введите число: ";
            std::cin >> _number;
            std::cout << "Введите индекс: ";
            std::cin >> _index;
        }

        void inputDividers()
        {
            int count;
            std::cout << "Введите количество делителей: ";
            std::cin >> count;
            int tmp_div;

            for (int i=0; i < count; i++)
            {
                std::cout << "Введите " << i+1 << " делитель: ";
                std::cin >> tmp_div;
                _divider_arr.push_back(tmp_div);
            }
        }
        void digitCount()
        {
            int tmp_number;
            tmp_number = _number;
            while (tmp_number > 0)
            {
                tmp_number /= 10;
                _count++;
            }
        }

        void sliceDigitByIndex()
        {
            int tmp_number;
            tmp_number = _number;
            if (_count >= _index)
            {
                for (int i=0; i < _count - _index; i++)
                {
                    tmp_number /= 10;
                }
            }
            _digit = tmp_number % 10;
        }

        void checkDivisibility()
        {
            for (int divider : _divider_arr)
            {
                if (_number % divider == 0)
                {
                    std::cout << _number << " делится на " << divider << std::endl;
                }
                else
                {
                    std::cout << _number << " не делится на " << divider << std::endl;
                }
            }
        }
};
class Quest2
{
public:
    int _start=10, _stop=100;
    int _array1[90];
    int _array2[90];
    int _size=90;
    std::vector<int> _vector_2_8;
    std::vector<int> _vector_3_4;
    static void setupForConsole()
    {
        Quest2 q2;
        q2.fillArrays();
        q2.findLastDigit();
        std::cout << "При умножении на 2 - конец 8:" << std::endl;
        for (int number: q2._vector_2_8)
        {
            std::cout << number << " ";
        }
        std::cout << "\n" <<std::endl;
        std::cout << "При умножении на 3 - конец 4: " << std::endl;
        for (int number: q2._vector_3_4)
        {
            std::cout << number << " ";
        }
    }
    void fillArrays()
    {
        for (int i=0; i < _size; i++)
        {
            _array1[i] = (i + _start);
            _array2[i] = (i + _start);
        }
    }
    void findLastDigit()
    {
        for (int i=0; i < _size; i++)
        {
            if (_array1[i]*2 % 10 == 8)
            {
                _vector_2_8.push_back(_array1[i]);
            }
            if (_array2[i]*3 % 10 == 4)
            {
                _vector_3_4.push_back(_array2[i]);
            }
        }
    }
};

int main()
{
    Quest1::setupForConsole();
    Quest2::setupForConsole();
    return 0;
}
