#include <iostream>
#include <vector>

using namespace std;

// número de soluções possíveis 

int solucoes = 0;

// função que faz exibição do tabuleiro NxN
void mostraTabuleiro(vector<vector<int >> & tab, int N)
{
    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 1)
            {
                cout << "R\t";
            }
            else
            {
                cout << "-\t";
            }
            
        }
        cout <<endl << endl;
    }
}


// função que verifica se é possível colocar a rainha em determinada posição
bool verificaPosicao(vector<vector<int >> & tab, int N, int linha, int coluna)
{

    // verifição de ataue na linha e na coluna
    for (int i = 0; i < N; i++)
    {
        if (tab[linha][i] == 1)
            return false;
    }


    for (int i = 0; i < N; i++)
    {
        if (tab[i][coluna] == 1)
            return false;
    }

    // verificação de ataque na diagonal principal, posição superior e inferior

    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
    {
        if (tab[i][j] == 1)
            return false;
    }

    for (int i = linha, j = coluna; i < N && j < N; i++, j++)
    {
        if (tab[i][j] == 1)
            return false;
    }
    

    // verificação de ataque na diagonal secundária, posição superior e inferior

    for (int i = linha, j = coluna; i >= 0 && j < N; i--, j++)
    {
        if (tab[i][j] == 1)
            return false;
    }

    for (int i = linha, j = coluna; i < N && j >= 0; i++, j--)
    {
        if (tab[i][j] == 1)
            return false;
    }

    // retorna true caso a posição esteja adequada para colocar a rainha

    return true;
}


// função  que executa o problema se o retorno for True é possível resolver e False caso não consiga

void execucao(vector<vector<int >> & tab, int N, int coluna)
{
    if (coluna == N)
    {
       cout << "Solução N° : " << solucoes + 1 <<": " << endl;
       mostraTabuleiro(tab, N);
       solucoes ++;
       return;
    }

    for (int i = 0; i < N; i++)
    {
        if (verificaPosicao(tab, N, i, coluna))
        {
            tab[i][coluna] = 1;

            execucao(tab, N, coluna + 1);

            tab[i][coluna] = 0;
        }

        /*
        return;: função void exige um retorno mesmo que vazio;
        vereficaPosicao: retorna se é possivel inserir a rainha na posição desejada;
        tab[i][coluna]: caso a rainha seja inserida é colocado 1;
        execucao: faz uma chamada recursiva na excução do "jogo";
        tab[i][coluna]: remove a rainha caso a posução não seja adquada [backtracking].
        */
    }
}


//função principal chamada de funções 

int main(int argc, char const *argv[])
{
    // N: número de rainhas, tab: vetor que gera o tabuleiro;

    int N = 8;
    vector<vector< int >> tab;

    for (int i = 0; i < N; i++)
    {
        vector<int> linha(N);
        tab.push_back(linha);
    }

    execucao(tab, N, 0);

    cout <<"Foram realizadas " << solucoes << " soluções para essa entrada!" << endl; 
    
    return 0;
}



