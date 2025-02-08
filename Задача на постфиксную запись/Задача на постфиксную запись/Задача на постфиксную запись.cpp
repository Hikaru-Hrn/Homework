#include <iostream>
using namespace std;
//задача 3 на решение примера в постфиксной записи. Якимов Максим 14123

struct variant
{
    union tag_value
    {
        int intValue;
        float floatValue
    } value;
    unsigned storedType;
};

void CheckString(string a) { //Функция для проверки коректности ввода, а именно чтобы были только символы и цифры
    int sym = 0;
    int num = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (isdigit(a[i])) {
            num++;
            continue;
        }
        else if (a[i] == '+' or a[i] == '-' or a[i] == '*') {
            sym++;
            continue;
        }
        else {
            cout << "Введены некорректные символы" << endl;
            exit(0); //если данные неверны программа завершается
        }
        
    }
    if (sym != num - 1) {
        cout << "Пример введен неверно" << endl;
        exit(0);
    }
}




int Func() {
    








}

int main() {
    setlocale(LC_ALL, "RU");

    int size = 2;
    * arr = new variant[size];
    arr[0] = '+';
    arr[1] = 12;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
