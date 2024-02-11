#include "symmetric_difference.hpp"
using namespace std;


int main() {
    cout << "Введите путь к файлу, содержащий множества: " << endl;
    string file_path;
    cin >> file_path;
    set<int> result = symmetric_difference(file_path);
    cout << "Симметрическая разность множеств: ";
    for (int num : result) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}