#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // количество вершин в одном подмножестве
    int n=0;
    cin >> n;
    
    // матрица
    vector< vector<int> > graph(n, vector<int>(n));
    
    for (int i=0; i<n;i++) {
        for (int j=0; j<n; j++) cin >> graph[i][j];
    }
    
    int sum=0;
    
    int maxNum;
    int maxI, maxJ;
    
    // поиск максимумов, удаление столбцов и строк
    while(graph.size()>0) {
        maxNum=graph[0][0];
        maxI=0;
        maxJ=0;
        for (int i=0; i<graph.size();i++) {
            for (int j=0; j<graph[i].size(); j++) {
                if (graph[i][j]>maxNum) {
                    maxNum = graph[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        sum+=maxNum;
        for (int i=0; i<graph.size();i++) {
            graph[i].erase(graph[i].begin()+maxJ);
        }
        graph.erase(graph.begin()+maxI);
    }
    
    cout<< sum << endl;

    return 0;
}
