#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSteps = 0;

vector<int> transformNumberToArrayOfNumbers(int num) {
    string numString = to_string(num);
    vector<int> array;

    for (int i = 0; i < numString.size(); i++) {
        array.push_back(numString[i] - '0'); // Convertendo o caractere para número
    }

    return array;
}

int getBiggerNumberInArray(const vector<int>& array) {
    int bigger = 0;

    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] > bigger) {
            bigger = array[i];
        }
    }

    return bigger;
}

int subtractDigits(int num) {
    if (num == 0) return countSteps;

    vector<int> array = transformNumberToArrayOfNumbers(num);
    int bigger = getBiggerNumberInArray(array);

    countSteps++;
    num -= bigger;

    return subtractDigits(num);
}

int main() {
    int num;
    cin >> num;

    int result = subtractDigits(num);
    cout << result << endl;

    return 0;
}

// Esta solução utilizou recursão, não passou em todos os casos de teste.