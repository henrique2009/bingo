#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

vector<int> numeros, sorteados;

int main() {
    // Preparar números 1-100
    for (int i = 1; i <= 100; i++) numeros.push_back(i);
    shuffle(numeros.begin(), numeros.end(), default_random_engine(time(0)));
    
    while (!numeros.empty()) {
        system("clear");
        
        // MOSTRA ÚLTIMO NÚMERO
        cout << "BINGO - Último número: ";
        if (!sorteados.empty()) {
            cout << sorteados.back();
        } else {
            cout << "---";
        }
        cout << "\n\n";
        
        // Mostrar todos os números
        for (int i = 1; i <= 100; i++) {
            bool achou = false;
            for (int n : sorteados) if (n == i) achou = true;
            
            if (achou) cout << "\033[31m";
            else cout << "\033[32m";
            
            cout << setw(3) << i << "\033[0m ";
            if (i % 10 == 0) cout << "\n";
        }
        
        cout << "\nPressione Enter para próximo número...";
        cin.get();
        
        // Sortear
        int n = numeros.back();
        numeros.pop_back();
        sorteados.push_back(n);
        
        system("clear");
        
        // MOSTRA ÚLTIMO NÚMERO
        cout << "BINGO - Último número: " << n << "\n\n";
        
        for (int i = 1; i <= 100; i++) {
            bool achou = false;
            for (int s : sorteados) if (s == i) achou = true;
            
            if (achou) cout << "\033[31m";
            else cout << "\033[32m";
            
            cout << setw(3) << i << "\033[0m ";
            if (i % 10 == 0) cout << "\n";
        }
        
        cout << "\n\nSaiu o número: " << n << "\n";
    }
    
    cout << "\nFim! Todos os números sorteados.\n";
    return 0;
}
