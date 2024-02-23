#include "masivv.h"
 
Masiv::Masiv(int SIZE){
    size = SIZE;
    mas = new int[size];
}
Masiv::~Masiv(){
    delete[] mas;
}
Masiv::Masiv(Masiv &other){
    this->size = other.SizeG();
    this->sort = other.SortG();
    this->NAPRAVLEN = other.NAPRAVLENG();
    this->mas = new int[size];
    for (int i{0}; i < size; i++)
        this->mas[i] = other.ElementG(i);
}

void Masiv::mkmas(int OT, int DO){
    for (int i{0}; i < size; i++)
        mas[i]= OT + rand() % (DO - OT +1);
    sort = false;
}
void Masiv::Sort(bool napravlen)
{
    int temp;
    for (int i{0}; i < size-1;i++)
        for (int j{i+1}; j < size; j++)
            if (napravlen){
                if (mas[i] < mas[j]){
                    temp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = temp;
                }
            }
            else{
                if (mas[i] > mas[j]){
                    temp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = temp;
                }
            }
    sort = true;
    NAPRAVLEN = napravlen;
}
void Masiv::PushInSort(int x){
    int *newmas{new int[size+1]};
    if (sort){
        int res_search(search(x));
        for (int i{0}; i <= res_search; i++)
            newmas[i] = mas[i];
        newmas[res_search + 1] = x;
        for (int i{res_search + 2}; i <= size; i++)
            newmas[i] = mas[i-1];
    }
    else{
        for (int i{0}; i < size; i++)
            newmas[i] = mas[i];
        newmas[size + 1] = x;
    }
    delete[] mas;
    mas = newmas;
    size++;
}
int Masiv::SearchInSort(int x){
    if (sort){
        int res_search{search(x)};
        if ((res_search >= 0 ) && (mas[res_search] == x))
            return res_search;
        if ((res_search < size -1) && (mas[res_search + 1] == x))
            return res_search + 1;
    }
    else{
        for (int i{0}; i < size; i++){
            if (mas[i] = x)
                return i;
        }
    }
    return -1;
}
void Masiv::UnionSort(Masiv arr1, Masiv arr2){
    if (arr1.SortG() && arr2.SortG()){
        int *newmas{new int[arr1.SizeG() + arr2.SizeG()]};
        int k{0};
        if (arr1.NAPRAVLENG() == arr2.NAPRAVLENG()){
            int j{0};
            if (arr1.NAPRAVLENG()){
                for (int i{0}; i < arr1.SizeG(); i++){
                    while((arr1.ElementG(i) < arr2.ElementG(j)) && (j < arr2.SizeG())){
                        newmas[k] = arr2.ElementG(j);
                        j++;
                        k++;
                    }
                    newmas[k] = arr1.ElementG(i);
                    k++;
                }
                for (int i{j}; i < arr2.SizeG();i++){
                    newmas[k] = arr2.ElementG(i);
                    k++;
                }
            }
            else{
                for (int i{0}; i < arr1.SizeG(); i++){
                    while((arr1.ElementG(i) > arr2.ElementG(j)) && (j < arr2.SizeG())){
                        newmas[k] = arr2.ElementG(j);
                        j++;
                        k++;
                    }
                    newmas[k] = arr1.ElementG(i);
                    k++;
                }
                for (int i{j}; i < arr2.SizeG();i++){
                    newmas[k] = arr2.ElementG(i);
                    k++;
                }
            }
        }
        else{
            int j{arr2.SizeG() - 1};
            if (arr1.NAPRAVLENG()){
                for (int i{0}; i < arr1.SizeG(); i++){
                    while((arr1.ElementG(i) < arr2.ElementG(j)) && (j >= 0)){
                        newmas[k] = arr2.ElementG(j);
                        j--;
                        k++;
                    }
                    newmas[k] = arr1.ElementG(i);
                    k++;
                }
                for (int i{j}; i >= 0;i--){
                    newmas[k] = arr2.ElementG(i);
                    k++;
                }
                }
            else{
                for (int i{0}; i < arr1.SizeG(); i++){
                    while((arr1.ElementG(i) > arr2.ElementG(j)) && (j >= 0)){
                        newmas[k] = arr2.ElementG(j);
                        j--;
                        k++;
                    }
                    newmas[k] = arr1.ElementG(i);
                    k++;
                }
                for (int i{j}; i >= 0;i--){
                    newmas[k] = arr2.ElementG(i);
                    k++;
                }
            }
        }
    delete[] mas;
    mas = newmas;
    NAPRAVLEN = arr1.NAPRAVLENG();
    sort = true;
    size = arr1.SizeG() + arr2.SizeG();
    }
    else
        return;
}

int Masiv::SizeG(){
    return size;
}
bool Masiv::SortG(){
    return sort;
}
int Masiv::ElementG(int nomer){
    return mas[nomer];
}
bool Masiv::NAPRAVLENG(){
    return NAPRAVLEN;
}
void Masiv::ShowProperties(){
    cout << "\033[33m" << this << ":\n"
            << "\tКласс: Masiv\n"
            << "\tРазмер: " << size
            << "\n\tОтсортирован: ";
    if (sort){
        cout << "да\n"
                << "\tНаправление: ";
        if (NAPRAVLEN)
            cout << "от большего к меньшему\n" ;
        else
            cout << "от меньшего к большему\n" ;
    }
    else{
        cout << "нет\n" << "\tНаправление: -\n";
    }
    cout << "\033[0m";
}
void Masiv::ShowMas(){
    for (int j{1}; j < size; j++)
        cout << "========";
    cout << "===\n";
    for (int i{0}; i < size; i++)
        cout << mas[i] << "\t";
    cout << endl;
    for (int j{1}; j < size; j++)
        cout << "========";
    cout << "===\n";
}

int Masiv::search(int x){
    int sosed, start{0}, end{size-1};
    if (NAPRAVLEN){
        if (mas[0]<= x)
            return -1;
        if (mas[end] >= x)
            return end;
        while (start < end){
            sosed = (start + end)/2;
            if (mas[sosed] < x)
                end = sosed;
            else{
                if (mas[sosed] > x){
                    if (start == sosed)
                        start = sosed + 1;
                    else
                        start = sosed;
                }
                else
                    return sosed-1;
            }
        }
    }
    else{
        if (mas[0] >= x)
            return -1;
        if (mas[end] <= x)
            return end;
        while (start < end){
            sosed = (start + end)/2;
            if (mas[sosed] > x)
                end = sosed;
            else{
                if (mas[sosed] < x){
                    if (start == sosed)
                        start = sosed + 1;
                    else
                        start = sosed;
                }
                else
                    return sosed-1;
            }
        }
    }
    return sosed;
}



Masiv2::Masiv2(int n, int m){
    sizeN = n;
    sizeM = m;
    mas = new int*[sizeN];
    for (int i{0}; i < sizeN; i++)
        mas[i] = new int [sizeM];
}
Masiv2::~Masiv2(){
    for (int i = 0; i < sizeN; i++)
        delete[] mas[i];
    delete[] mas;
}
Masiv2::Masiv2(Masiv2 &other){
    this->sizeN = other.SizeNG();
    this->sizeM = other.SizeMG();
    this->sort = other.SortG();
    this->KEY = other.KEYG();
    this->NAPRAVLEN = other.NAPRAVLENG();
    this->NOMERKEY = other.NOMERKEYG();
    this->mas = new int*[sizeN];
    for (int i{0}; i < sizeN; i++)
        this->mas[i] = new int[sizeM];
    for (int i{0}; i < sizeN; i++)
        for (int j{0}; j < sizeM; j++)
            this->mas[i][j] = other.ElementG(i,j);
}

void Masiv2::mkmas(int OT, int DO){
    for (int i{0}; i < sizeN; i++)
        for (int j{0}; j < sizeM; j++)
            mas[i][j]= OT + rand() % (DO - OT +1);
    sort = false;
}
void Masiv2::Sort(bool key, int nomerkey, bool napravlen){
    if (key)
        if (nomerkey >= sizeM || nomerkey < 0)
            return;
        else
            PuzirSortSTR(nomerkey, napravlen);
    else
        if (nomerkey >= sizeN || nomerkey < 0)
            return;
        else
            PuzirSortSTO(nomerkey, napravlen);
    sort = true;
    NOMERKEY = nomerkey;
    KEY = key;
    NAPRAVLEN = napravlen;
}
void Masiv2::PushInSort(Masiv arr){
    int **newmas;
    if (sort){
        if (KEY && arr.SizeG() != sizeM)
            return;
        if (!KEY && arr.SizeG() != sizeN)
            return;
        if(KEY){
            newmas = new int*[sizeN + 1];
            for (int i{0}; i <= sizeN; i++)
                newmas[i] = new int [sizeM];
            int res_search{search(arr.ElementG(NOMERKEY))};
            for (int i{0}; i <= res_search; i++)
                for (int j{0}; j < sizeM; j++)
                    newmas[i][j] = mas[i][j];
            for (int j{0}; j < sizeM; j++)
                newmas[res_search + 1][j] = arr.ElementG(j);

            for (int i{res_search + 2}; i <= sizeN; i++)
                for (int j{0}; j < sizeM; j++)
                    newmas[i][j]=mas[i-1][j];

            for (int i = 0; i < sizeN; i++)
                delete[] mas[i];
            sizeN++;
        }
        else{
            newmas = new int*[sizeN];
            for (int i{0}; i < sizeN; i++)
                newmas[i] = new int [sizeM + 1];
            int res_search{search(arr.ElementG(NOMERKEY))};
            for (int j{0}; j <= res_search; j++)
                for (int i{0}; i < sizeN; i++)
                    newmas[i][j] = mas[i][j];
            for (int i{0}; i < sizeN; i++)
                newmas[i][res_search + 1] = arr.ElementG(i);

            for (int j{res_search + 2}; j <= sizeM; j++)
                for (int i{0}; i < sizeN; i++)
                    newmas[i][j]=mas[i][j-1];

            for (int i = 0; i < sizeN; i++)
                delete[] mas[i];
            sizeM++;
        }
    }
    else{
        if (arr.SizeG() == sizeM){
            newmas = new int*[sizeN + 1];
            for (int i{0}; i <= sizeN; i++)
                newmas[i] = new int [sizeM];
            for (int i{0}; i < sizeN; i++)
                for (int j{0}; j < sizeM; j++)
                    newmas[i][j] = mas[i][j];
            for (int j{0}; j < sizeM; j++)
                newmas[sizeN][j] = arr.ElementG(j);
            for (int i = 0; i < sizeN; i++)
                delete[] mas[i];
            sizeN++;
        }
        else{
            if (arr.SizeG() == sizeN){
                newmas = new int*[sizeN];
                for (int i{0}; i < sizeN; i++)
                    newmas[i] = new int [sizeM + 1];
                for (int j{0}; j < sizeM; j++)
                    for (int i{0}; i < sizeN; i++)
                        newmas[i][j] = mas[i][j];
                for (int i{0}; i < sizeN; i++)
                    newmas[i][sizeM] = arr.ElementG(i);
                for (int i = 0; i < sizeN; i++)
                    delete[] mas[i];
                sizeM++;
            }
        }
    }
    delete[] mas;
    mas = newmas;
}
int Masiv2::SearchInSort(int x){
    if (sort){
        int res_search{search(x)};
        if (KEY){
            if ((res_search >= 0 ) && (mas[res_search][NOMERKEY] == x))
                return res_search;
            if ((res_search < sizeN -1) && (mas[res_search + 1][NOMERKEY] == x))
                return res_search + 1;
        }
        else
        {
            if ((res_search >= 0 ) && (mas[NOMERKEY][res_search] == x))
                return res_search;
            if ((res_search < sizeM -1) && (mas[NOMERKEY][res_search + 1] == x))
                return res_search + 1;
        }
    }
    return -1;
}
void Masiv2::UnionSort(Masiv2 arr1, Masiv2 arr2){
    if (arr1.SortG() && arr2.SortG() && (arr1.KEYG() == arr2.KEYG()) && (arr1.NOMERKEYG() == arr2.NOMERKEYG()) && ((arr1.SizeNG() == arr2.SizeNG() && arr1.KEYG() == false)||(arr1.SizeMG() == arr2.SizeMG() && arr1.KEYG() == true))){
        int **newmas;
        KEY = arr1.KEYG();
        if (KEY){
            newmas = new int*[arr1.SizeNG() + arr2.SizeNG()];
            for (int i{0}; i < arr1.SizeNG() + arr2.SizeNG(); i++)
                newmas[i] = new int [arr1.SizeMG()];
        }
        else{
            newmas = new int*[arr1.SizeNG()];
            for (int i{0}; i < arr1.SizeNG(); i++)
                newmas[i] = new int [arr1.SizeMG() + arr2.SizeMG()];
        }
        int k{0};
        NOMERKEY = arr1.NOMERKEYG();
        if (arr1.NAPRAVLENG() == arr2.NAPRAVLENG()){
            int j{0};
            if (arr1.NAPRAVLENG()){
                if (KEY){
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr2.SizeMG(); c++)
                                newmas[k][c] = arr2.ElementG(j,c); 
                            j++;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeMG(); c++)
                            newmas[k][c] = arr1.ElementG(i,c); 
                        k++;
                    }
                    for (int i{j}; i < arr2.SizeNG(); i++){
                        for (int c{0}; c < arr2.SizeMG(); c++)
                            newmas[k][c] = arr2.ElementG(i,c);
                        k++;
                    }
                }
                else{
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((j < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) < arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr2.ElementG(c,j);
                            j++;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr1.ElementG(c,i);
                        k++;
                    }
                    for (int i{j}; i < arr2.SizeMG(); i++){
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr2.ElementG(c,i);
                        k++;
                    }
                }
            }
            else{
                if (KEY){
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) > arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr2.SizeMG(); c++)
                                newmas[k][c] = arr2.ElementG(j,c); 
                            j++;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeMG(); c++)
                            newmas[k][c] = arr1.ElementG(i,c); 
                        k++;
                    }
                    for (int i{j}; i < arr2.SizeNG(); i++){
                        for (int c{0}; c < arr2.SizeMG(); c++)
                            newmas[k][c] = arr2.ElementG(i,c);
                        k++;
                    }
                }
                else{
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((j < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) > arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr2.ElementG(c,j);
                            j++;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr1.ElementG(c,i);
                        k++;
                    }
                    for (int i{j}; i < arr2.SizeMG(); i++){
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr2.ElementG(c,i);
                        k++;
                    }
                }
            }
        }
        else{
            if (arr1.NAPRAVLENG()){
                if (KEY){
                    int j{arr2.SizeNG() - 1};
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((j >= 0) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr2.SizeMG(); c++)
                                newmas[k][c] = arr2.ElementG(j,c); 
                            j--;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeMG(); c++)
                            newmas[k][c] = arr1.ElementG(i,c); 
                        k++;
                    }
                    for (int i{j}; i >= 0; i--){
                        for (int c{0}; c < arr2.SizeMG(); c++)
                            newmas[k][c] = arr2.ElementG(i,c);
                        k++;
                    }
                }
                else{
                    int j{arr2.SizeMG() - 1};
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((j >= 0) && (arr1.ElementG(NOMERKEY,i) < arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr2.ElementG(c,j);
                            j--;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr1.ElementG(c,i);
                        k++;
                    }
                    for (int i{j}; i >= 0; i--){
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr2.ElementG(c,i);
                        k++;
                    }
                }
            }
            else{
                if (KEY){
                    int j{arr2.SizeNG() - 1};
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((j >= 0) && (arr1.ElementG(i,NOMERKEY) > arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr2.SizeMG(); c++)
                                newmas[k][c] = arr2.ElementG(j,c); 
                            j--;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeMG(); c++)
                            newmas[k][c] = arr1.ElementG(i,c); 
                        k++;
                    }
                    for (int i{j}; i >= 0; i--){
                        for (int c{0}; c < arr2.SizeMG(); c++)
                            newmas[k][c] = arr2.ElementG(i,c);
                        k++;
                    }
                }
                else{
                    int j{arr2.SizeMG() - 1};
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((j >= 0) && (arr1.ElementG(NOMERKEY,i) > arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr2.ElementG(c,j);
                            j--;
                            k++;
                        }
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr1.ElementG(c,i);
                        k++;
                    }
                    for (int i{j}; i >= 0; i--){
                        for (int c{0}; c < arr1.SizeNG(); c++)
                            newmas[c][k] = arr2.ElementG(c,i);
                        k++;
                    }
                }
            }
        }
        for (int i = 0; i < sizeN; i++)
                delete[] mas[i];
        if (KEY){
            sizeN = k;
            sizeM = arr1.sizeM;
        }
        else{
            sizeM = k;
            sizeN = arr1.sizeN;
        }
        delete[] mas;
        mas = newmas;
        NAPRAVLEN = arr1.NAPRAVLENG();
        sort = true;
    }
    else{
        return;
    }
}
void Masiv2::IntersectionSort(Masiv2 arr1, Masiv2 arr2){
    if (arr1.SortG() && arr2.SortG() && (arr1.KEYG() == arr2.KEYG()) && (arr1.NOMERKEYG() == arr2.NOMERKEYG()) && ((arr1.SizeNG() == arr2.SizeNG() && arr1.KEYG() == false)||(arr1.SizeMG() == arr2.SizeMG() && arr1.KEYG() == true))){
        for (int i = 0; i < sizeN; i++)
            delete[] mas[i];
        delete[] mas;
        int **newmas;
        int m{0};
        NOMERKEY = arr1.NOMERKEYG();
        NAPRAVLEN = arr1.NAPRAVLENG();
        KEY = arr1.KEYG();
        sort = true;
        if (arr1.NAPRAVLENG() == arr2.NAPRAVLENG()){
            int l{0};
            if (arr1.NAPRAVLENG()){
                if (KEY){
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((l < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(l,NOMERKEY)))
                            l++;
                        if ((l < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(l,NOMERKEY)))
                            m++,l++;
                    }
                    newmas = new int*[m];
                    for (int i{0}; i < m; i++)
                        newmas[i] = new int[arr1.SizeMG()];
                    for (int i{0},k{0},j{0}; i < arr1.SizeNG(); i++){
                        while((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(j,NOMERKEY)))
                            j++;
                        if ((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr1.SizeMG(); c++)
                                newmas[k][c] = arr1.ElementG(i,c); 
                            k++;
                            j++;
                        }
                    }
                    sizeN = m;
                    sizeM = arr1.SizeMG();
                }
                else{
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((l < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) < arr2.ElementG(NOMERKEY,l)))
                            l++;
                        if ((l < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,l)))
                            m++,l++;
                    }
                    newmas = new int*[arr1.SizeNG()];
                    for (int i{0}; i < arr1.SizeNG(); i++)
                        newmas[i] = new int[m];
                    for (int i{0},k{0},j{0}; i < arr1.SizeMG(); i++){
                        while((j < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) < arr2.ElementG(NOMERKEY,j)))
                            j++;
                        if ((j < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr1.ElementG(c,i); 
                            k++;
                            j++;
                        }
                    }
                    sizeN = arr1.SizeNG();
                    sizeM = m;
                }
            }
            else{
                if (KEY){
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((l < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) > arr2.ElementG(l,NOMERKEY)))
                            l++;
                        if ((l < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(l,NOMERKEY)))
                            m++,l++;
                    }
                    newmas = new int*[m];
                    for (int i{0}; i < m; i++)
                        newmas[i] = new int[arr1.SizeMG()];
                    for (int i{0},k{0},j{0}; i < arr1.SizeNG(); i++){
                        while((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) > arr2.ElementG(j,NOMERKEY)))
                            j++;
                        if ((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr1.SizeMG(); c++)
                                newmas[k][c] = arr1.ElementG(i,c); 
                            k++;
                            j++;
                        }
                    }
                    sizeN = m;
                    sizeM = arr1.SizeMG();
                }
                else{
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((l < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) > arr2.ElementG(NOMERKEY,l)))
                            l++;
                        if ((l < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,l)))
                            m++,l++;
                    }
                    newmas = new int*[arr1.SizeNG()];
                    for (int i{0}; i < arr1.SizeNG(); i++)
                        newmas[i] = new int[m];
                    for (int i{0},k{0},j{0}; i < arr1.SizeMG(); i++){
                        while((j < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) > arr2.ElementG(NOMERKEY,j)))
                            j++;
                        if ((j < arr2.SizeMG()) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr1.ElementG(c,i); 
                            k++;
                            j++;
                        }
                    }
                    sizeN = arr1.SizeNG();
                    sizeM = m;
                }
            }
        }
        else{
            if (arr1.NAPRAVLENG()){
                if (KEY){
                    int l{arr2.SizeNG() - 1};
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((l >= 0) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(l,NOMERKEY)))
                            l--;
                        if ((l >= 0) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(l,NOMERKEY)))
                            m++,l--;
                    }
                    newmas = new int*[m];
                    for (int i{0}; i < m; i++)
                        newmas[i] = new int[arr1.SizeMG()];
                    for (int i{0},k{0},j{arr2.SizeNG() - 1}; i < arr1.SizeNG(); i++){
                        while((j >= 0) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(j,NOMERKEY)))
                            j--;
                        if ((j>= 0) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr1.SizeMG(); c++)
                                newmas[k][c] = arr1.ElementG(i,c); 
                            k++;
                            j--;
                        }
                    }
                    sizeN = m;
                    sizeM = arr1.SizeMG();
                }
                else{
                    int l{arr2.SizeMG() - 1};
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((l>= 0) && (arr1.ElementG(NOMERKEY,i) < arr2.ElementG(NOMERKEY,l)))
                            l--;
                        if ((l >= 0) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,l)))
                            m++,l--;
                    }
                    newmas = new int*[arr1.SizeNG()];
                    for (int i{0}; i < arr1.SizeNG(); i++)
                        newmas[i] = new int[m];
                    for (int i{0},k{0},j{arr2.SizeMG() - 1}; i < arr1.SizeMG(); i++){
                        while((j >= 0) && (arr1.ElementG(NOMERKEY,i) < arr2.ElementG(NOMERKEY,j)))
                            j--;
                        if ((j >= 0) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr1.ElementG(c,i); 
                            k++;
                            j--;
                        }
                    }
                    sizeN = arr1.SizeNG();
                    sizeM = m;
                }
            }
            else{
                if (KEY){
                    int l{arr2.SizeNG() - 1};
                    for (int i{0}; i < arr1.SizeNG(); i++){
                        while((l >= 0) && (arr1.ElementG(i,NOMERKEY) > arr2.ElementG(l,NOMERKEY)))
                            l--;
                        if ((l >= 0) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(l,NOMERKEY)))
                            m++,l--;
                    }
                    newmas = new int*[m];
                    for (int i{0}; i < m; i++)
                        newmas[i] = new int[arr1.SizeMG()];
                    for (int i{0},k{0},j{arr2.SizeNG() - 1}; i < arr1.SizeNG(); i++){
                        while((j >= 0) && (arr1.ElementG(i,NOMERKEY) > arr2.ElementG(j,NOMERKEY)))
                            j--;
                        if ((j>= 0) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(j,NOMERKEY))){
                            for (int c{0}; c < arr1.SizeMG(); c++)
                                newmas[k][c] = arr1.ElementG(i,c); 
                            k++;
                            j--;
                        }
                    }
                    sizeN = m;
                    sizeM = arr1.SizeMG();
                }
                else{
                    int l{arr2.SizeMG() - 1};
                    for (int i{0}; i < arr1.SizeMG(); i++){
                        while((l>= 0) && (arr1.ElementG(NOMERKEY,i) > arr2.ElementG(NOMERKEY,l)))
                            l--;
                        if ((l >= 0) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,l)))
                            m++,l--;
                    }
                    newmas = new int*[arr1.SizeNG()];
                    for (int i{0}; i < arr1.SizeNG(); i++)
                        newmas[i] = new int[m];
                    for (int i{0},k{0},j{arr2.SizeMG() - 1}; i < arr1.SizeMG(); i++){
                        while((j >= 0) && (arr1.ElementG(NOMERKEY,i) > arr2.ElementG(NOMERKEY,j)))
                            j--;
                        if ((j >= 0) && (arr1.ElementG(NOMERKEY,i) == arr2.ElementG(NOMERKEY,j))){
                            for (int c{0}; c < arr1.SizeNG(); c++)
                                newmas[c][k] = arr1.ElementG(c,i); 
                            k++;
                            j--;
                        }
                    }
                    sizeN = arr1.SizeNG();
                    sizeM = m;
                }
            }
        }
        mas = newmas;
    }
    else{
        return;
    }
}

int Masiv2::SizeNG(){
    return sizeN;
}
int Masiv2::SizeMG(){
    return sizeM;
}
bool Masiv2::SortG(){
    return sort;
}
bool Masiv2::KEYG(){
    return KEY;
}
bool Masiv2::NAPRAVLENG(){
    return NAPRAVLEN;
}
int Masiv2::NOMERKEYG(){
    return NOMERKEY;
}
int Masiv2::ElementG(int nomerN, int nomerM){
    return mas[nomerN][nomerM];
}
void Masiv2::ShowProperties(){
    cout << "\033[33m" << this << ":\n"
            << "\tКласс: Masiv2\n"
            << "\tРазмер: " << sizeN << "x" << sizeM
            << "\n\tОтсортирован: ";
    if (sort){
        cout << "да\n"
                << "\tНаправление: ";
        if (NAPRAVLEN)
            cout << "от большего к меньшему\n" ;
        else
            cout << "от меньшего к большему\n" ;
        cout << "\tОбъект сортировки: ";
        if (KEY)
            cout << "cтрока\n" ;
        else
            cout << "столбец\n" ;
        cout << "\tНомер параметра сотрировки: " << NOMERKEY << endl;
    }
    else{
        cout << "нет\n" << "\tНаправление: -\n\tОбъект сортировки: -\n\tНомер параметра сотрировки: -\n";
    }
    cout << "\033[0m";
}
void Masiv2::ShowMas(){
    for (int j{1}; j < sizeM; j++)
        cout << "========";
    cout << "===\n";
    if (sort){
        if (KEY){
            for (int i{0}; i < sizeN; i++){
                for (int j{0}; j < NOMERKEY; j++)
                    cout << mas[i][j] << "\t";
                cout << "\033[1;31m" << mas[i][NOMERKEY] << "\033[39m" << "\t";
                for (int j{NOMERKEY + 1}; j < sizeM; j++)
                    cout << mas[i][j] << "\t";
                cout << endl;
            }
        }
        else{
            for (int i{0}; i < NOMERKEY; i++){
                for (int j{0}; j < sizeM; j++){
                    cout << mas[i][j] << "\t";
                }
                cout << endl;
            }
            cout << "\033[1;31m";
            for (int j{0}; j < sizeM; j++)
                    cout << mas[NOMERKEY][j] << "\t";
            cout << "\033[39m" << endl;
            for (int i{NOMERKEY + 1}; i < sizeN; i++){
                for (int j{0}; j < sizeM; j++){
                    cout << mas[i][j] << "\t";
                }
                cout << endl;
            }
        }
    }
    else{
        for (int i{0}; i < sizeN; i++){
            for (int j{0}; j < sizeM; j++){
                    cout << mas[i][j] << "\t";
            }
            cout << endl;
        }
    }
    for (int j{1}; j < sizeM; j++)
        cout << "========";
    cout << "===\n";
}

void Masiv2::PuzirSortSTR(int nomerkey, bool napravlen){
    int temp;
    for (int i{0}; i < sizeN-1;i++)
        for (int j{i+1}; j < sizeN; j++)
            if (napravlen){
                if (mas[i][nomerkey] < mas[j][nomerkey])
                    for (int k{0}; k < sizeM; k++){
                        temp = mas[i][k];
                        mas[i][k] = mas[j][k];
                        mas[j][k] = temp;
                    }
            }
            else
                if (mas[i][nomerkey] > mas[j][nomerkey])
                    for (int k{0}; k < sizeM; k++){
                        temp = mas[i][k];
                        mas[i][k] = mas[j][k];
                        mas[j][k] = temp;
                    }
}
void Masiv2::PuzirSortSTO(int nomerkey, bool napravlen){
    int temp;
    for (int i{0}; i < sizeM-1;i++)
        for (int j{i+1}; j < sizeM; j++)
            if (napravlen){
                if (mas[nomerkey][i] < mas[nomerkey][j])
                    for (int k{0}; k < sizeN; k++){
                        temp = mas[k][i];
                        mas[k][i] = mas[k][j];
                        mas[k][j] = temp;
                    }
            }
            else
                if (mas[nomerkey][i] > mas[nomerkey][j])
                    for (int k{0}; k < sizeN; k++){
                        temp = mas[k][i];
                        mas[k][i] = mas[k][j];
                        mas[k][j] = temp;
                    }
}
int Masiv2::search(int x){
    int sosed, start{0}, end;
    if (KEY){
        end = sizeN - 1;
        if (NAPRAVLEN){
            if (mas[0][NOMERKEY] <= x)
                return -1;
            if (mas[end][NOMERKEY] >= x)
                return end;
        }
        else{
            if (mas[0][NOMERKEY] >= x)
                return -1;
            if (mas[end][NOMERKEY] <= x)
                return end;
        }
        while(start < end){
            sosed = (start + end)/2;
            if (NAPRAVLEN && mas[sosed][NOMERKEY] < x)
            end = sosed;
            if (NAPRAVLEN && mas[sosed][NOMERKEY] >= x){
                if (start == sosed)
                    start = sosed + 1;
                else
                    start = sosed;
            }
            if (!NAPRAVLEN && mas[sosed][NOMERKEY] <= x){
                if (start == sosed)
                    start = sosed + 1;
                else
                    start = sosed;
            }
            if (!NAPRAVLEN && mas[sosed][NOMERKEY] > x)
                end = sosed;
        }
    }
    else{
        end = sizeM - 1;
        if (NAPRAVLEN){
            if (mas[NOMERKEY][0] <= x)
                return -1;
            if (mas[NOMERKEY][end] >= x)
                return end;
        }
        else{
            if (mas[NOMERKEY][0] >= x)
                return -1;
            if (mas[NOMERKEY][end] <= x)
                return end;
        }
        while(start < end){
            sosed = (start + end)/2;
            if (NAPRAVLEN && mas[NOMERKEY][sosed] < x)
                end = sosed;
            if (NAPRAVLEN && mas[NOMERKEY][sosed] >= x){
                if (start == sosed)
                    start = sosed + 1;
                else
                    start = sosed;
            }
            if (!NAPRAVLEN && mas[NOMERKEY][sosed] <= x){
                if (start == sosed)
                    start = sosed + 1;
                else
                    start = sosed;
            }
            if (!NAPRAVLEN && mas[NOMERKEY][sosed] > x)
                end = sosed;
        }
    }
    return sosed;
}



Time::Time(){
    srand(time(0));
}
