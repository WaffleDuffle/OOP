/* Să se scrie un program care execută operațiile de adunare, scădere și înmulțire între două matrice. Operația se va alege în funcție de o valoare de test citită de la tastatură.

Se citesc de la tastatură:

doi întregi, m și n, reprezentând dimensiunile primei matrice
m x n întregi, reprezentând elementele primei matrice
doi întregi, q și p, reprezentând dimensiunile celei de-a doua matrice
q x p întregi, reprezentând elementele celei de-a doua matrice
un întreg, test, reprezentând valoarea în funcție de care se execută diverse funcții:
adunare matrice - se afișează pe ecran elementele matricei obținută prin adunarea celor două matrice de intrare.
scădere matrice -  se afișează pe ecran elementele matricei obținută prin scăderea celei de-a doua matrice din prima matrice.
înmulțire matrice - se afișează pe ecran elementele matricei obținută prin înmulțirea primei matrice cu cea de-a doua matrice. */

#include <iostream>
class Matrice{
    private:
        int linii;
        int coloane;
        int *mat = new int[linii*coloane];
    public:
        Matrice(int linii, int coloane):linii(linii), coloane(coloane){
            
            for(int i = 0 ; i < linii ; ++i)
                for(int j = 0 ; j < coloane ; ++j)
                    std::cin >> *(mat + i*coloane + j);
        }
        void afisare(){
            for(int i = 0 ; i < linii ; ++i, std::cout << std::endl)
                for(int j = 0 ; j < coloane ; ++j)
                    std::cout << *(mat + i*coloane + j) << " ";
        }
        Matrice operator+(const Matrice &mat2){
            Matrice m3(linii,coloane);
            for(int i = 0 ; i < linii ; ++i)
                for(int j = 0 ; j < coloane ; ++j){
                    *(m3.mat + i*coloane + j) = *(mat + i*coloane + j) + *(mat2.mat + i*coloane + j);
                }
                return m3;
        }
        
        Matrice operator-(const Matrice &mat2){
            Matrice m3(linii,coloane);
            for(int i = 0 ; i < linii ; ++i)
                for(int j = 0 ; j < coloane ; ++j){
                    *(m3.mat + i*coloane + j) = *(mat + i*coloane + j) - *(mat2.mat + i*coloane + j);
                }
                return m3;
        }
        Matrice operator*(const Matrice &mat2){
            Matrice m3(linii, mat2.coloane);
            for(int i = 0 ; i < linii ; ++i)
                for(int j = 0 ; j < coloane ; ++j){
                    *(m3.mat + i*mat2.coloane + j) = 0;
                    for(int k = 0 ; k < coloane ; ++k){
                        
                        *(m3.mat + i*mat2.coloane + j) += *(mat + i*coloane + k) * *(mat2.mat + k*mat2.coloane + j);
                    }
                }
                return m3;
        }
};

int main(){
    int test, m, n, q, p;
    std::cin >> m >> n;
    Matrice M1(m, n);
    
    std::cin >> q >> p;
    Matrice M2(q, p);
    std::cin >> test;
    switch(test){
        case 1:{
                Matrice M3 = M1 + M2;
                M3.afisare();
                break;
        }
        case 2:{
                Matrice M3 = M1 - M2;
                M3.afisare();
                break;
        }
        case 3:{
                Matrice M3 = M1 * M2;
                M3.afisare();
                break;
        }
    }
    
    return 0;
}
