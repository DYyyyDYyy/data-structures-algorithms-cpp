#include <bits/stdc++.h>
#include <iomanip>
#include "List.h"
using namespace std;

string formatStack(const vector<int>& stackParams) {
    if (stackParams.empty()) return "NULL";
    ostringstream os;
    for (int i = (int)stackParams.size() - 1; i >= 0; --i) {
        if (i != (int)stackParams.size() - 1) os << " ";
        os << stackParams[i];
    }
    return os.str();
}

void nonRecursiveDFS(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<bool> visited(n, false);
    vector<int> dfsnum(n, 0);
    vector<pair<int,int>> treeEdges;
    vector<string> protocol;
    int DFS = 0;

    create_empty_lists();

    visited[start] = true;
    dfsnum[start] = ++DFS;
    push(start);

    {
        ostringstream os;
        os << "Push " << start << " | Stack: " << str_stack(stack_head);
        protocol.push_back(os.str());
    }

    while (stack_head != NULL) {
        int cur = stack_head->key;
        bool found = false;
        int next = -1;

        for (int v = 0; v < n; v++) {
            if (adj[cur][v] && !visited[v]) {
                next = v;
                found = true;
                break;
            }
        }

        if (found) {
            visited[next] = true;
            dfsnum[next] = ++DFS;
            treeEdges.emplace_back(cur, next);
            push(next);

            ostringstream os;
            os << "Push " << next << " (from " << cur << ") | Stack: " << str_stack(stack_head);
            protocol.push_back(os.str());
        } else {
            pop();
            ostringstream os;
            os << "Pop " << cur << " | Stack: " << str_stack(stack_head);
            protocol.push_back(os.str());
        }
    }

    cout << "\n=== Результати (Нерекурсивний DFS — стек із List.cpp) ===\n";
    cout << "DFS-номери вершин:\n";
    for (int i = 0; i < n; i++)
        if (dfsnum[i] != 0) cout << "Вершина " << i << " -> DFSnum = " << dfsnum[i] << "\n";
        else cout << "Вершина " << i << " -> Недосяжна" << "\n";

    cout << "\nПротокол пошуку:\n";
    for (auto &line : protocol) cout << line << "\n";

    cout << "\nРебра каркасу (tree edges):\n";
    for (auto &e : treeEdges) cout << "(" << e.first << ", " << e.second << ")\n";

    cout << "=====================================\n\n";
}

void dfsRecursiveUtil(const vector<vector<int>>& adj, int u, vector<bool>& visited,
                      vector<int>& dfsnum, int& DFS, vector<pair<int,int>>& treeEdges,
                      vector<string>& protocol, vector<int>& displayStack) {

    visited[u] = true;
    dfsnum[u] = ++DFS;

    displayStack.push_back(u);

    {
        ostringstream os;
        os << "Enter " << u << " | Stack (Top->Bottom): " << formatStack(displayStack);
        protocol.push_back(os.str());
    }

    for (int v = 0; v < (int)adj.size(); ++v) {
        if (adj[u][v] && !visited[v]) {
            treeEdges.emplace_back(u, v);
            dfsRecursiveUtil(adj, v, visited, dfsnum, DFS, treeEdges, protocol, displayStack);
        }
    }

    {
        ostringstream os;
        os << "Exit " << u << "  | Stack before pop: " << formatStack(displayStack);
        protocol.push_back(os.str());
    }

    displayStack.pop_back();
}

void recursiveDFS(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<bool> visited(n, false);
    vector<int> dfsnum(n, 0);
    vector<pair<int,int>> treeEdges;
    vector<string> protocol;
    vector<int> displayStack;
    int DFS = 0;

    dfsRecursiveUtil(adj, start, visited, dfsnum, DFS, treeEdges, protocol, displayStack);

    cout << "\n=== Результати (Рекурсивний DFS) ===\n";
    cout << "DFS-номери вершин:\n";
    for (int i = 0; i < n; ++i) {
        if (dfsnum[i] != 0) cout << "Вершина " << i << " -> DFSnum = " << dfsnum[i] << "\n";
        else cout << "Вершина " << i << " -> Недосяжна" << "\n";
    }

    cout << "\nПротокол рекурсивного пошуку:\n";
    for (auto &line : protocol) cout << line << "\n";

    cout << "\nРебра каркасу (tree edges):\n";
    for (auto &e : treeEdges) cout << "(" << e.first << ", " << e.second << ")\n";
    cout << "=====================================\n\n";
}

void BFS(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<bool> visited(n, false);
    vector<int> bfsnum(n, 0);
    vector<pair<int,int>> treeEdges;
    int BFSN = 0;

    create_empty_lists();

    cout << "\n=== Результати (BFS — згідно з методичкою) ===\n";
    cout << "\nПротокол обходу:\n";
    cout << string(55, '-') << endl;
    cout << left << setw(10) << "Вершина"
         << setw(15) << "BFS-номер"
         << "Вміст черги" << endl;
    cout << string(55, '-') << endl;

    visited[start] = true;
    bfsnum[start] = ++BFSN;
    enqueue(start);

    cout << left << setw(10) << start
         << setw(15) << bfsnum[start]
         << str_queue() << endl;

    while (queue_front != NULL) {
        int cur = queue_front->key;

        for (int v = 0; v < n; ++v) {
            if (adj[cur][v] && !visited[v]) {
                visited[v] = true;
                bfsnum[v] = ++BFSN;
                treeEdges.emplace_back(cur, v);
                enqueue(v);

                cout << left << setw(10) << v
                     << setw(15) << bfsnum[v]
                     << str_queue() << endl;
            }
        }
        dequeue();
    }
    cout << string(55, '-') << endl;

    cout << "\nРебра каркасу (tree edges):\n";
    for (auto &e : treeEdges) cout << "(" << e.first << ", " << e.second << ")\n";

    cout << "=====================================\n\n";
}

vector<vector<int>> sampleGraph() {
    int n = 8;
    vector<vector<int>> adj(n, vector<int>(n,0));
    vector<pair<int,int>> edges = {
        {0,1},{0,2},{0,3},
        {1,4},
        {2,5},
        {4,6},
        {5,7},
        {1,2},{2,3},{3,4}
    };
    for (auto &e: edges) {
        adj[e.first][e.second] = 1;
    }
    return adj;
}

vector<vector<int>> inputGraphInteractive() {
    int n;
    cout << "Введіть кількість вершин n: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Невірне число. Спробуйте ще: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    vector<vector<int>> adj(n, vector<int>(n,0));
    cout << "Введіть кількість ребер m: ";
    int m; cin >> m;
    cout << "Далі введіть m пар вершин (0-indexed) u v для кожного направленого ребра.\n";
    for (int i=0;i<m;++i) {
        int u,v;
        cout << "edge " << i+1 << ": ";
        cin >> u >> v;
        if (u>=0 && u<n && v>=0 && v<n) {
            adj[u][v] = 1;
        } else {
            cout << "Невірні індекси, спроба пропущена.\n";
        }
    }
    return adj;
}

int main() {
    cout << "=== Lab 6: Обхід графа (DFS iterative, DFS recursive, BFS) ===\n";
    cout << "Підключено файли List.h / List.cpp (необхідні для лабораторної структури).\n\n";

    cout << "Оберіть граф:\n1) Використати прикладний граф (зразок 8 вершин)\n2) Ввести власний граф\nВаш вибір: ";
    int gchoice; cin >> gchoice;
    vector<vector<int>> adj;
    if (gchoice == 2) adj = inputGraphInteractive(); else adj = sampleGraph();

    int n = (int)adj.size();
    cout << "\nМатриця суміжності (виведення):\n";
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) cout << adj[i][j] << " ";
        cout << "\n";
    }

    cout << "\nОберіть метод:\n1) Нерекурсивний DFS\n2) Рекурсивний DFS\n3) BFS (Протокол таблицею)\nВаш вибір: ";
    int choice; cin >> choice;

    cout << "Вкажіть стартову вершину (0.." << n-1 << "): ";
    int start; cin >> start;
    if (start < 0 || start >= n) {
        cout << "Невірна вершина. Використовується 0.\n";
        start = 0;
    }

    if (choice == 1) {
        nonRecursiveDFS(adj, start);
    } else if (choice == 2) {
        recursiveDFS(adj, start);
    } else if (choice == 3) {
        BFS(adj, start);
    } else {
        cout << "Невірний вибір.\n";
    }

    cout << "Кінець програми.\n";
    return 0;
}