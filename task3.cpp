// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     // количество вершин в одном подмножестве
//     int n=0;
//     cin >> n;
    
//     // матрица
//     vector< vector<int> > graph(n, vector<int>(n));
    
//     for (int i=0; i<n;i++) {
//         for (int j=0; j<n; j++) cin >> graph[i][j];
//     }
    
//     int sum=0;
    
//     int maxNum;
//     int maxI, maxJ;
    
//     // поиск максимумов, удаление столбцов и строк
//     while(graph.size()>0) {
//         maxNum=graph[0][0];
//         maxI=0;
//         maxJ=0;
//         for (int i=0; i<graph.size();i++) {
//             for (int j=0; j<graph[i].size(); j++) {
//                 if (graph[i][j]>maxNum) {
//                     maxNum = graph[i][j];
//                     maxI = i;
//                     maxJ = j;
//                 }
//             }
//         }
//         sum+=maxNum;
//         for (int i=0; i<graph.size();i++) {
//             graph[i].erase(graph[i].begin()+maxJ);
//         }
//         graph.erase(graph.begin()+maxI);
//     }
    
//     cout<< sum << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> bipartiteGraph;
vector<int> match;
int n;
vector<char> usedVertices;

vector<int> sortedSet(vector< vector<int> > matrix) {
    vector<int> sorted;
    for (int i=0; i<n;i++) {
        int max=matrix[i][0];
        int maxJ=i=0;
        for (int j=1; j<n; j++) {
            if (matrix[i][j]>max) {
                max=matrix[i][j];
                maxJ=j;
            }
        }
        sorted.push_back(maxJ);
    }
    return sorted;
}

bool kuhnAlgorithm(int x) {
    if (usedVertices[x])  return false;
    usedVertices[x] = true;
    for (size_t i=0; i<bipartiteGraph[x].size(); i++) {
        int to = bipartiteGraph[x][i];
        if (match[to] == -1 || kuhnAlgorithm (match[to])) {
            match[to] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    // количество вершин в каждом подмножестве
    cin >> n;
    
    if (n<2) return -1;
    
    // матрица
    vector< vector<int> > matrix(n, vector<int>(n));
    
    for (int i=0; i<n;i++) {
        for (int j=0; j<n; j++) cin >> matrix[i][j];
    }
    
    bipartiteGraph = vector< vector <int> >(n, vector<int>(1));
    
    vector<int> order = sortedSet(matrix);
    
    // Алгоритм Куна
    match.assign(n, -1);
    for (int i=0; i<n; i++) {
        // iota(bipartiteGraph[i].begin(), bipartiteGraph[i].end(), 0);
        bipartiteGraph[i][0] = 0;
        usedVertices.assign(n, false);
        kuhnAlgorithm(order[i]);
    }
    
    int sum=0;
    
    // int maxNum;
    // int maxI, maxJ;
    
    // поиск максимумов, удаление столбцов и строк
    // while(matrix.size()>0) {
    //     maxNum=matrix[0][0];
    //     maxI=0;
    //     maxJ=0;
    //     for (int i=0; i<matrix.size();i++) {
    //         for (int j=0; j<matrix[i].size(); j++) {
    //             if (matrix[i][j]>maxNum) {
    //                 maxNum = matrix[i][j];
    //                 maxI = i;
    //                 maxJ = j;
    //             }
    //         }
    //     }
    //     sum+=maxNum;
    //     for (int i=0; i<matrix.size();i++) {
    //         matrix[i].erase(matrix[i].begin()+maxJ);
    //     }
    //     matrix.erase(matrix.begin()+maxI);
    // }
    
    cout<< sum << endl;

    return 0;
}
