#include<iostream>
using namespace std;
class matrix{
    int  **pptr; // pointer to matrix
    int d1, d2; // dimensions
    public:
        matrix(int p, int q){
            this->d1 = p;
            this->d2 = q;
            // allocating memory for the matrix:
            // a complete knowledge is in my yellow nb
            pptr = new int * [d1];
            for(int i=0; i<d1; i++){
                pptr[i] = new int[d2];
            }

        }
        void get_element(int i, int j, int value){
            pptr[i][j] = value;
        }
        int put_element(int m, int n){
            return pptr[m][n];
            
        }
        
        void display_matrix(){
            for(int i=0; i<d1; i++){
                for(int j=0; j<d2; j++){
                    cout << pptr[i][j] << " ";
                }    
                cout << "\n";
            }
        }
        
        ~matrix(){
            // deleting dynamically allocating memory
            for(int i=0; i<d1; i++){
                delete pptr[i];
            }
            delete pptr;
        }

};

int main() {
    int r, c;
    cout << "Enter the size of matrix: " << endl;
    cin >> r >> c;

    matrix obj(r, c);

    cout << "Enter the elements of matrix: " << endl;
    int value;
    // filling the matrix
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> value;
            obj.get_element(i, j, value);
        }
    }
    cout << "the matrix is: " << endl;
    obj.display_matrix();
        // for accessing an element and displaying it
        cout << "element at pptr[1][2] is: " << obj.put_element(1, 2);
    return 0;
}
