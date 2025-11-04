#include <bits/stdc++.h>

using namespace std;

void OrdenarPrioridade(deque<int>& prioridade)
{
    sort(prioridade.begin(),prioridade.end(), [](auto&a,auto&b)
        {
            return a > b;
        }
    );
}

bool VerificaPilha(stack<int>& pilha,int valor,bool val)
{
    int valor_true = pilha.top();
    pilha.pop();

    if(valor_true!=valor) return false;
    else return val;
}
bool VerificaFila(queue<int>& fila,int valor,bool val)
{
    int valor_true = fila.front();
    fila.pop();

    if(valor_true!=valor) return false;
    else return val;
}
bool VerificaPrio(deque<int>& prioridade,int valor,bool val)
{
    int valor_true = prioridade.front();
    prioridade.pop_front();

    if(valor_true!=valor) return false;
    else return val;
}

int main(){


    int n;
    while(cin >> n)
    {
        stack<int> pilha;
        queue<int> fila;
        deque<int> prioridade;

        bool pilha_val = true;
        bool fila_val = true;
        bool prio_val = true;
        for(int i=0;i<n;i++)
        {
            int tipo,valor;
            cin >> tipo >> valor;

            if(tipo==1)
            {
                pilha.push(valor);
                fila.push(valor);
                prioridade.push_back(valor);
            }
            else
            {
                OrdenarPrioridade(prioridade);
                pilha_val = VerificaPilha(pilha,valor,pilha_val);
                fila_val = VerificaFila(fila,valor,fila_val);
                prio_val = VerificaPrio(prioridade,valor,prio_val);
            }
        }

        if(!pilha_val && !fila_val && !prio_val) cout << "impossible" << endl;
        else
        {
            if(pilha_val && !fila_val && !prio_val) cout << "stack" << endl;
            else
            {
                if(!pilha_val && fila_val && !prio_val) cout << "queue" << endl;
                else
                {
                    if(!pilha_val && !fila_val && prio_val) cout << "priority queue" << endl;
                    else cout << "not sure" << endl;
                }
            }
        }
    }

    return 0;
}