#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));
    
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <quantidade>\n";
        return 1;
    }
    
    int quantidade = atoi(argv[1]);
    
    if (quantidade < 1 || quantidade > 20) {
        cout << "Erro: 1 a 20 cartões\n";
        return 1;
    }
    
    // Para cada cartão
    for (int id = 1; id <= quantidade; id++) {
        // Vetor 5x5 para cartão
        vector<vector<string>> cartao(5, vector<string>(5, "  "));
        
        // Colunas: cada uma com 20 números (100/5 = 20)
        for (int col = 0; col < 5; col++) {
            // Gerar 20 números únicos para a coluna
            vector<int> numeros;
            int inicio = col * 20 + 1;      // 0:1-20, 1:21-40, 2:41-60, 3:61-80, 4:81-100
            int fim = inicio + 19;          // 20 números por coluna
            
            for (int i = inicio; i <= fim; i++) {
                numeros.push_back(i);
            }
            
            // Embaralhar
            for (int i = 0; i < 20; i++) {
                int j = rand() % 20;
                swap(numeros[i], numeros[j]);
            }
            
            // Colocar 5 números no cartão (1 por linha)
            for (int linha = 0; linha < 5; linha++) {
                cartao[linha][col] = to_string(numeros[linha]);
            }
        }
        
        // Centro vazio (linha 2, coluna 2)
        cartao[2][2] = "**";
        
        // Salvar em arquivo
        string nome = "cartao_" + to_string(id) + ".txt";
        ofstream arquivo(nome);
        
        arquivo << "CARTÃO " << id << " (1-100)\n";
        arquivo << " B   I   N   G   O\n";
        arquivo << "===============================\n";
        
        for (int linha = 0; linha < 5; linha++) {
            for (int col = 0; col < 5; col++) {
                // Formatar para ficar alinhado
                if (cartao[linha][col] == "**") {
                    arquivo << " **  ";
                } else {
                    int num = stoi(cartao[linha][col]);
                    if (num < 10) arquivo << "  ";
                    else if (num < 100) arquivo << " ";
                    arquivo << cartao[linha][col] << "  ";
                }
            }
            arquivo << "\n";
        }
        
        arquivo.close();
        cout << "Criado: " << nome << "\n";
    }
    
    cout << "\n" << quantidade << " cartões criados!\n";
    return 0;
}
