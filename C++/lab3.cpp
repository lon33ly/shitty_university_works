#include <iostream>

using namespace std;

void vowconsCount(char *str)
{
    int i, vowCount=0, consCount=0, strlen=0;
    for(i=0; str[i]; i++){
        if(str[i] == 'a'|| str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u'
           ||str[i] == 'A'|| str[i] == 'E'|| str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U' ){
            vowCount++;
        }
        else if((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )){
            consCount++;
        }
        strlen++;
    }
    double vow_percent, cons_percent;

    cout<<"Количество гласных:"<<vowCount<<endl;
    cout<<"Количество согласных:"<<consCount<<endl;
    vow_percent = (vowCount / (strlen/100.0));
    cons_percent = (consCount / (strlen/100.0));
    cout<<"В процентах гласных:"<<vow_percent<<endl;
    cout<<"В процентах согласных:"<<cons_percent<<endl;
}

void ShortestWord(string text)
{
    string tmpWord = "";
    string minWord = text;

    for(int i=0; i < (int)text.length(); i++)
    {
        if(text[i] != ' ')
            tmpWord += text[i];
        else
        {
            // We got a new word, try to update answer
            if(tmpWord.length() < minWord.length())
                minWord=tmpWord;
            tmpWord = "";
        }
    }

    if(tmpWord != "")
        if(tmpWord.length() < minWord.length())
            minWord=tmpWord;

    cout << "Кратчайшее слово: " << minWord << endl;
    cout << "Длина кратчайшего слова: " << minWord.length() << endl;
}

int main()
{
    char str [] = "Never gonna give you up!";
    string text = "Sometimes you need to lose yourself";

    cout << "Строка для подсчета гласных/согласных: "
         << str
         << endl;
    cout << "Строка для поиска кратчайшего слова: "
         << text
         << endl;
    vowconsCount(str);
    ShortestWord(text);
}

