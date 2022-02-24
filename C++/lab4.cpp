#include <iostream>
#include <vector>
using namespace std;

vector<int> _min_row;
vector<int> _min_col;

template <typename T>
T** createArray(const int& n, const int& m)
{
    T** array = new T*[m];
    for (int i=0; i < m; i++)
        array[i] = new T[n];

    return array;
}

template <typename T>
T* createArray(const int& n)
{
    T* array = new T[n];
    for (int i = 0 ; i < n; i++) array[i] = 0;
    return array;
}

// вывод массива
template <typename T>
void PrintArray(T** array, const int& n, const int& m) {
    for (int i = 0 ; i < n; i++){ for (int j = 0 ; j < m; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void PrintArray(T* array, const int& n)
{
    for (int i = 0 ; i < n; i++)
        cout << array[i] << "\t";
    cout << endl;
}

template <typename T>
void findMinElementIndex(T** array, const int& n, const int& m) {
    int min_el = 9999;
    for (int i=0; i < m; i++)
        for (int j=0; j < n; j++)
        {
            if (array[i][j] < min_el)
            {
                _min_row.clear();
                _min_col.clear();
                _min_row.push_back(i);
                _min_col.push_back(j);
                min_el = array[i][j];
            }
            else if (array[i][j] == min_el)
            {
                _min_row.push_back(i);
                _min_col.push_back(j);
            }
        }
}

template <typename T>
void findMinElementIndex(T* array, const int& n) {
    int i, min;
    for(i = 0; i < n; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    cout  << "Minimum Element\n" << min;
}

template <typename T>
T** fillArray(T** array, const int& n, const int& m, int size=99) {
    for (int i=0; i < m; i++)
        for (int j=0; j < n; j++)
            array[i][j] = rand() % size + 1;
    return array;
}

template <typename T>
T* fillArray(T* array, const int& n, int size=99) {
    for (int i =0; i < n; i++)
        array[i] = rand() % size + 1;
    return array;
}

template <typename T>
T** sowZeroElements(T** array, const int& n, const int& m, int count_zeros=2)
{
    int row, col, flag=0;
    for(int i=0; i < count_zeros; i++)
        while (flag < 2)
        {
            row = rand() % m;
            col = rand() % n;
            if (array[row][col] != 0)
            {
                flag++;
                array[row][col] = 0;
            }
        }
    return array;
}

template <typename T>
T* sowZeroElements(T* array, const int& n, int count_zeros=2)
{
    int row, flag=0;
    for(int i=0; i < count_zeros; i++)
        while (flag < 2)
        {
            row = rand() % n;
            if (array[row] != 0)
            {
                flag++;
                array[row]= 0;
            }
        }
    return array;
}

template <typename T>
void findCompFromZeroToZero(T** array, const int& n, const int& m, int start_zero=1)
{
    int _compztz = 1;
    int end_zero = start_zero + 1;
    int zero_counter = 0;
    // поиск координат нулей
    for (int i=0; i < m; i++)
        for (int j=0; j < n; j++)
        {
            if (array[i][j] == 0)
                zero_counter++;
            if (zero_counter == 1 && array[i][j] != 0)
                _compztz *= array[i][j];
        }
    cout << "Результат переменожения двумерного значений между " <<
         start_zero << " и " << end_zero <<" нулем " << "\n" <<_compztz << endl;
}

template <typename T>
void findCompFromZeroToZero(T* array, const int& n, int start_zero=1)
{
    int _compztz = 1;
    int end_zero = start_zero + 1;
    int zero_counter = 0;
    // поиск координат нулей
    for (int i=0; i < n; i++)
    {
        if (array[i]== 0)
            zero_counter++;
        if (zero_counter == 1 && array[i]!= 0)
            _compztz *= array[i];
    }
    cout << "Результат переменожения одномерного значений между " <<
         start_zero << " и " << end_zero <<" нулем " << "\n" <<_compztz << endl;
}

int main()
{
    int n = 5;
    int m = 5;
    int* array = createArray<int>(n);
    double** array2d = createArray<double>(n, m);

    array = fillArray(array, n);
    array2d = fillArray(array2d, n, m);

    array = sowZeroElements(array, n);
    array2d = sowZeroElements(array2d, n, m);

    findCompFromZeroToZero(array, n);
    findCompFromZeroToZero(array2d, n, m);

    PrintArray(array, n);
    cout << endl;
    PrintArray(array2d, n, m);
}