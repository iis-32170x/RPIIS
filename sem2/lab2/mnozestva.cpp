#include <stdio.h> //стандартные функции ввода/вывода 

#include <stdlib.h> //функции динамического управления памятью, генерации случайных чисел, целой арифметики, поиска,
                    //сортировки и преобразования типов данных.
#include <string.h>
#define OPENSET_SYMBOL '{'
#define CLOSESET_SYMBOL '}'
#define TERMSET_SYMBOL ';'
#define TERMNAME_SYMBOL ','
#define DEFNAME_SYMBOL '='

#ifndef STR_MAX_LENGTH   //директива препроцессора, которая проверяет, 
                           //не была ли уже определена символьная константа STR_MAX_LENGTH. 
                           // Если она не была определена, то код внутри условия будет выполнен.

#define STR_MAX_LENGTH 80  //если символьная константа STR_MAX_LENGTH не была определена ранее, 
                           //то она будет определена здесь со значением 80.

#else                     //если символьная константа STR_MAX_LENGTH уже была определена ранее, 
                          //то код после #else будет выполнен.

#error STR_MAX_LENGTH already define    
                                        // если символьная константа STR_MAX_LENGTH уже была определена ранее, 
                                       //то будет выдана ошибка компиляции с сообщением "STR_MAX_LENGTH already defined".
#endif


#ifndef TRUE
#ifndef FALSE
#define FALSE 0
#define TRUE 1
#else
#define TRUE (!FALSE)  //если только FALSE была определена ранее, то TRUE определяется как логическое отрицание FALSE.
#endif
#else
#ifndef FALSE
#define FALSE (!TRUE) //если только TRUE была определена ранее, то FALSE определяется как логическое отрицание TRUE.
#endif
#endif


//---------------------объявление структуры для представления множества---------------------------------------------

typedef struct { //С помощью typedef можно объявить любой тип, включая типы указателя, функции и массива.
    int u;
    char* name;
    struct _element_of_set* pFirst;
} set;

typedef set element; //set = element

//--------------------объявление структуры для представления и оргазации вхождения элемента во множество*-------------

typedef struct _element_of_set {
    element* pElement;
    struct _element_of_set* pNext;
} element_of_set;

//------------------------------------функции вывода множества или элемента-----------------------------------------
//                                           (прототипы) 
//                                   +функции чтения множества или элемента из заданного файла (прототипы)


void fprint_els(FILE*, void*, int, int);
void fprint_set(FILE*, set*);
void fprint_element(FILE*, element*);

int fscan_els(FILE*, void**, int);
int fscan_set(FILE*, set**);
int fscan_element(FILE*, element**);


void initialize_set(set*); // функция инициализации множества

int compare_elements(element*, element*); //функция сравнения двух элементов

element_of_set* add_element(set*, element*); //функция добавления элемента во множество 

element* find_element(set*, element*); //функция поиска элемента во множестве

element* get_next_element(set*, element_of_set*); //функция получения следующего элемента из множества

void* set_next_element(set*, element_of_set*, element*); //функция установки следующего элемента из множества

void go_next(set*, element_of_set**); //функция перехода к следующему вхождению

void remove_next_element(set*, element_of_set*); //функция исключения последующего элемента из множества

void destroy_elements(set*); //функция уничтожения элементов множества

void clear_set(set*); //функция очистки множества

set names; // множество прочитанных элементов 

//--------------------------------------------MAIN----------------------------------------------------

int main(int argc, char* argv[]) {
    int return_value = 0;
    FILE* input;
    set general_set;
    set* pSet = NULL;
    set copy;
    element_of_set* pEOSG = NULL;
    element_of_set* pEOS = NULL;
    element* pElement;
    if (argc == 2) if ((input = fopen(argv[1], "r")) != NULL) {
        /* инициализация и чтение данных из файла */
        initialize_set(&names);
        initialize_set(&general_set);
        if ((return_value = fscan_set(input, &pSet)) == 0) return_value--;
        else {
            add_element(&general_set, pSet);
            while ((return_value = fscan_set(input, &pSet)) > 0) add_element(&general_set, pSet);
        }
        fclose(input);
        /* уничтожение кратных вхождений
        и вывод результата */
        if (return_value == 0) do {
            if ((pSet = get_next_element(&general_set, pEOSG)) != NULL) {
                initialize_set(&copy);
                do {
                    if ((pElement = get_next_element(pSet, pEOS)) != NULL) {
                        if (find_element(&copy, pElement) == NULL) add_element(&copy, pElement);
                    }
                    go_next(pSet, &pEOS);
                } while (pEOS != NULL);
                fprint_set(stdout, &copy);
                clear_set(&copy);
            }
            go_next(&general_set, &pEOSG);
        } while (pEOSG != NULL);
        else printf("Syntax error.\n");
        destroy_elements(&names);
        return_value = 1;
    }
    return return_value;
}
