#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
#include<queue>


using namespace std;


class spam{
    int x,y,z;
    string a,b,c;
public:
    spam(int x, int y, int z, string a, string b, string c){
        this->x = x;
        this->y = y;
        this->z = z;
        this->a = a;
        this->b = b;
        this->c = c;
    }
    string conf(int t){
        if(t<y)return a;

        else if(y<=t && t<z) return b;

        else return c;
    }
    int getZ(){
        return x;
    }
};

vector< vector<int> > g; // Lista de Adjac�ncia

int *cor;
int *predescessor;
int *descoberta; // Tempo de descoberta
int *termino; // Tempo de t�rmino
int tempo; // "Rel�gio

// Algoritmo calcula a menor distancia para alcan�ar todos os vertices do grafo partindo de um vertice inicial.
vector<bool> bfs(int inicio)
{
    //para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.

    queue<int> Q; // Fila que define a ordem de acesso aos vertices.

    // Inicializa��o
    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.

    Q.push(inicio); // Enfileira a raiz.

    // Enquanto a fila n�o estiver vazia.
    while(!Q.empty())
    {
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
//        cout<<"vertice atual: "<<u<<endl;
        // Para todo vertice adjacente � "u".
        for(int i = 0; i < g[u].size(); i++)
        {
            // Se o vertice adjacente � "u" n�o tiver sido encontrado.
            if(cor[g[u][i]] == false)
            {
//                cout<<g[u][i]<<endl;
                Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
                p[g[u][i]] = u; // Define o pai do vertice adjacente como "u".
            }
        }
//        cout<<endl;
    }
    // *** OBS: O RETORNO DA FUN��O PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return cor; // Retorna o vetor peso.
}

int main(int argc, char *argv[])
{
    vector<spam> P;
    vector<string> pessoa;
    vector<vector<bool>> cores;
    int n,x;
    cin>>n;
    while(n!=0){
//        cout<<"entrou"<<endl;
        pessoa.resize(n + 1);
        g.resize(n+1);
        for (int i = 1; i < n+1; ++i) {
            x = -1;
            do {
                if (x != -1)g[i].push_back(x);
                cin >> x;
            } while (x != 0);
        }
//        cout<<"saiu dos nnumeros"<<endl;
        cin >> x;
//        cout<<"x inicial "<<x<<endl;
        int aux=0;
        while (x != 0) {
            int y, z;
            string a, b, c;
            cores.push_back(bfs(x));
//            cout<<"chegamos aqui"<<endl;
            cin>>y>>z>>a>>b>>c;
            spam pam(x,y, z, a, b, c);
//            cout<<"spam "<<x<<" "<<y<<" "<<z<<" "<<a<<" "<<b<<" "<<c<<" "<<endl;
            P.push_back(pam);
            cin >> x;

        }
//        puts("saiu dos spams");
        for (int i = 0; i < n; ++i)cin>>pessoa[i];
//        puts("pegou os nomes");
        int k=0;
        for (int i = 0; i < n; ++i) {
            cout<<pessoa[i]<<": ";
            for (int j = 0; j < P.size(); ++j){
                if(cores[j][i+1] == true) cout<<P[j].conf(g[i+1].size())<<" ";
                else cout<<P[j].conf(0)<<" ";
            }
            cout<<endl;
        }
        cin>>n;
        if(n == 0){
            cin>>n;
            if(n==0)return 0;
        }
        P.clear();
        pessoa.clear();
        cores.clear();
        g.clear();
    }
    cout<<endl;
    return 0;

}
