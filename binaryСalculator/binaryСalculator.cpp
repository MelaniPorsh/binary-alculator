// binaryСalculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <string> 

int charToBinary(char c) {
    return c - '0';
}

char binaryToChar(int binary) {
    return char(binary + '0');
}

std::string addBinary(std::string a, std::string b) {
    std::string result = "";
    int carry = 0;

    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        int bitA = charToBinary(a[i]);
        int bitB = charToBinary(b[i]);
        int sum = bitA + bitB + carry;
        carry = sum / 2;
        result = binaryToChar(sum % 2) + result;
    }

    if (carry == 1) {
        result = "1" + result;
    }

    return result;
}

std::string subtractBinary(std::string a, std::string b) {
    std::string result = "";
    bool borrow = false;

    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        int bitA = charToBinary(a[i]);
        int bitB = charToBinary(b[i]);

        if (borrow) {
            bitA--;
        }

        if (bitA < bitB) {
            bitA += 2;
            borrow = true;
        }
        else {
            borrow = false;
        }

        result = binaryToChar(bitA - bitB) + result;
    }

    return result;
}


std::string divideBinary(std::string a, std::string b) {
    std::string quotient = "";
    std::string remainder = a;

    while (remainder.length() >= b.length()) {
        std::string aux = remainder.substr(0, b.length());
        remainder = remainder.substr(b.length());

        int q = 0;
        while (subtractBinary(aux, b) != "0" && aux.length() > 0) {
            aux = subtractBinary(aux, b);
            q++;
        }

        quotient += binaryToChar(q);
    }

    return quotient;
}

int main() {
    std::string num1 = "101";
    std::string num2 = "11";

    std::cout << "Number 1: " << num1 << std::endl;
    std::cout << "Number 2: " << num2 << std::endl;

    std::cout << "Sum: " << addBinary(num1, num2) << std::endl;
    std::cout << "Difference: " << subtractBinary(num1, num2) << std::endl;
    std::cout << "Quotient: " << divideBinary(num1, num2) << std::endl;

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
