#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {

    queue<int> cola;
    queue<int> stack;

    int personas;
    while(cin>>personas && personas != -1) {
        cola.push(personas);
    }

    int tiempo = 0;
    int max_cola = -1;
    int por_atender = 0;

    while(!cola.empty()) {
        por_atender += cola.front(); // 5
        cola.pop();
        max_cola = max(max_cola, por_atender);

        por_atender--;
        tiempo++;
    }

    cout<< tiempo + por_atender << " " << max_cola <<endl;

    return 0;
}