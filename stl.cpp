// Standard Template Library - STL

#include <vector> //exemplo1, exemplo2
#include <cstdio> //exemplo2
#include <map> // exemplo3, exemplo4

using namespace std;

void exemplo1() {
    // vector<tipo> variável;
    // push_back(valor);

    vector<double> exemp;
    exemp.push_back(0.2);
    exemp.push_back(1.4);
    exemp[2] = 0.3;

    for (int i = 0; i < exemp.size(); i++) {
        printf("%f", exemp[i]);
    }

    // não acesse um elemento além do tamanho do vetor
    printf("Além do tamanho>>>%f", exemp[4]);
}

void exemplo2() {
    vector<int> vet;
    vector<int>::iterator p;

    for (int i=0; i <=4; i++) {
        vet.push_back(i);
    }

    for (p = vet.begin(); p != vet.end(); p++) {
        printf("%d", *p);
    }
}

void exemplo3() {
    // map<TChave, TData> m
    map<char, int> m;
    map<char, int>::iterator p;

    // m.size()
    // m.empty()
    // m.insert(E)
    // m.erase(C)
    // m.find(C)
    // m1 == m2 (true caso m1 e m2 possuam os mesmos elementos)

    m.insert(pair<char, int>('c', 2));
    m.insert(make_pair('b', 4));
    m['a'] = 5;

    printf("%d\n", m['b']);

    for (p = m.begin(); p != m.end(); p++) {
        printf("%c %d\n", p -> first, p -> second);
    }
}

void exemplo4() {
    map<const char*, int> months;

    months["january"] = 31;
    months["february"] = 31;
    months["march"] = 31;

    printf("june -> %d", months["june"]);
}

int main() {
    // vetores
    exemplo1();

    // iteradores
    exemplo2();

    // Map
    exemplo3();
    exemplo4();

    return 0;
}