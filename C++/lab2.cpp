#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Quest1
{
public:
    int _m{}, _n{};
    int** _d_2d_array{};
    // вектора заводятся на случай если минимальных будет несколько
    vector<int> _min_row;
    vector<int> _min_col;
    int _compztz = 1;
    static void setupForConsole()
    {
        Quest1 q1;
        q1.inputMAndN();
        q1.createDynamic2DArray();
        q1.fillDynamic2DArray(30);
        q1.printDynamic2DArray();
        q1.findMinElementIndex();
        q1.printIndicesOfMinElements();
        q1.sowZeroElements(2);
        q1.printDynamic2DArray();
        q1.findCompFromZeroToZero();
        q1.replaceOddAndEvenIndicesByHalf();
        q1.printDynamic2DArray();
        q1.deleteDynamic2DArray();
    }
    void inputMAndN()
    {
        cout << "Введите размер m: ";
        cin >> _m;
        cout << "Введите размер n: ";
        cin >> _n;
    }
    void createDynamic2DArray()
    {
        _d_2d_array = new int* [_m];
        for (int i=0; i < _m; i++)
            _d_2d_array[i] = new int [_n];
    }

    void deleteDynamic2DArray() const
    {
        for (int i=0; i < _m; i++)
            delete [] _d_2d_array[i];
    }
    void fillDynamic2DArray(int size=99) const
    {
        for (int i=0; i < _m; i++)
            for (int j=0; j < _n; j++)
                _d_2d_array[i][j] = rand() % size + 1;
    }
    void printDynamic2DArray() const
    {
        cout << "Массив " << _m << "x" << _n << ":" << endl;
        for (int i=0; i < _m; i++)
        {
            for (int j=0; j < _n; j++)
                cout << setw(3) << _d_2d_array[i][j];
            cout << endl;
        }
    }

    void findMinElementIndex()
    {
        int min_el = 9999;
        for (int i=0; i < _m; i++)
            for (int j=0; j < _n; j++)
            {
                if (_d_2d_array[i][j] < min_el)
                {
                    _min_row.clear();
                    _min_col.clear();
                    _min_row.push_back(i);
                    _min_col.push_back(j);
                    min_el = _d_2d_array[i][j];
                }
                else if (_d_2d_array[i][j] == min_el)
                {
                    _min_row.push_back(i);
                    _min_col.push_back(j);
                }
            }
    }
    void printIndicesOfMinElements()
    {
        cout << "Значение минимальных элементов: " <<
             _d_2d_array[_min_row[0]][_min_col[0]] << endl;
        cout << "Индексы минимальных элементов: " << endl;
        cout << "Строка" << " Столбец" << endl;
        for (int i=0; i < _min_col.size(); i++)
        {
            cout << setw(6) << _min_row[i]+1;
            cout << setw(8) << _min_col[i]+1;
            cout << endl;
        }
        cout << endl;
    }

    // сеем 2 нулевых элемента c разными координатами
    void sowZeroElements(int count_zeros=2) const
    {
        int row, col, flag=0;
        for(int i=0; i < count_zeros; i++)
            while (flag < 2)
            {
                row = rand() % _m;
                col = rand() % _n;
                if (_d_2d_array[row][col] != 0)
                {
                    flag++;
                    _d_2d_array[row][col] = 0;
                }
            }
    }
    // можно начать и с другого нуля (стандартное значение 0)
    void findCompFromZeroToZero(int start_zero=1)
    {
        int end_zero = start_zero + 1;
        int zero_counter = 0;
        // поиск координат нулей
        for (int i=0; i < _m; i++)
            for (int j=0; j < _n; j++)
            {
                if (_d_2d_array[i][j] == 0)
                    zero_counter++;
                if (zero_counter == 1 && _d_2d_array[i][j] != 0)
                    _compztz *= _d_2d_array[i][j];
            }
        cout << "Результат переменожения значений между " <<
             start_zero << " и " << end_zero <<" нулем " << "\n" <<_compztz << endl;
    }
    void replaceOddAndEvenIndicesByHalf()
    {
        int tmp_number;
        int tmptmp;
        int hidden_index=0;
        int row, col;
        for (int i=0; i < _m; i++)
            for (int j=0; j < _n; j++)
                if ((i*_n + j) % 2 == 0)
                {
                    tmp_number = i*_n+j - hidden_index;
                    row = tmp_number / _n;
                    col = tmp_number % _n;
                    tmptmp = _d_2d_array[row][col];
                    _d_2d_array[row][col] = _d_2d_array[i][j];
                    _d_2d_array[i][j] = tmptmp;
                    hidden_index++;
                }
    }
};
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Quest1::setupForConsole();
    return 0;
}