
class UnionFind {
    int tam;
    int parent[MAX];
    public: 
        UnionFind(int t) { // MakeSet
            tam = t;
            for (int i=0; i<=MAX; i++) {
                parent[i] = -1;
            }
        }
        void Init(int A, int B) {
            if (parent[A] == -1) {
                parent[A] = A;
            }
            if (parent[B] == -1) {
                parent[B] = B;
            }
        }
        int Find(int A) {
            if (parent[A] == A) {
                return A;
            } else {
                // Union find normal
                // return Find(parent[A]); 
                //Compresion de caminos
                return parent[A] = Find(parent[A]); 
            }
        }
        void Union(int A, int B) {
            int aRoot = Find(A);
            int bRoot = Find(B);
            parent[aRoot] = bRoot;
        }
        int Conexas() {
            int counter = 0;
            for (int i=0; i<tam; i++) {
                if (parent[i] == i) {
                    counter++;
                }
            }
            return counter;
        }
        bool SameComponent(int A, int B) {
            if (Find(A) == Find(B)) { // mismo padre
                return true;
            }
            return false;
        }
        void Print() {
            cout<<"-----------------------"<<endl;
            for(int i=0; i<=tam + 1; i++) {
                cout<< i <<"  ";
            }
            cout<<endl;
            for(int i=0; i<=tam + 1; i++) {
                cout<<parent[i] << "  ";
            }
            cout<<endl;
            cout<<"-----------------------"<<endl;
        }
};