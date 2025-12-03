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
        // Vetor 5x5 para cartão (B I N G O)
        vector<vector<string>> cartao(5, vector<string>(5, "  "));
        
        // Colunas: B(1-15), I(16-30), N(31-45), G(46-60), O(61-75)
        for (int col = 0; col < 5; col++) {
            // Gerar 5 números únicos para a coluna
            vector<int> numeros;
            int inicio = col * 15 + 1;
            int fim = inicio + 14;
            
            for (int i = inicio; i <= fim; i++) {
                numeros.push_back(i);
            }
            
            // Embaralhar
            for (int i = 0; i < 15; i++) {
                int j = rand() % 15;
                swap(numeros[i], numeros[j]);
            }
            
            // Colocar 5 números no cartão (1 por linha)
            for (int linha = 0; linha < 5; linha++) {
                cartao[linha][col] = to_string(numeros[linha]);
            }
        }
        
        // Centro vazio (N, linha 2, coluna 2)
        cartao[2][2] = "**";
        
        // Salvar em arquivo
        string nome = "cartao_" + to_string(id) + ".txt";
        ofstream arquivo(nome);
        
        arquivo << "CARTÃO " << id << "\n";
        arquivo << " B   I   N   G   O\n";
        arquivo << "===================\n";
        
        for (int linha = 0; linha < 5; linha++) {
            for (int col = 0; col < 5; col++) {
                if (cartao[linha][col].length() == 1) arquivo << " ";
                arquivo << cartao[linha][col] << "  ";
            }
            arquivo << "\n";
        }
        
        arquivo.close();
        cout << "Criado: " << nome << "\n";
    }
    
    cout << "\n" << quantidade << " cartões criados!\n";
    return 0;
}