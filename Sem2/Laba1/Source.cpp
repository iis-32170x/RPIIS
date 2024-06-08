#include <stdio.h>;
#include <iostream>;
#include<windows.h>;
#include<ctime>;
using namespace std;


struct comp { //Структура с именем comp
	int data; //Кикие то данные(могут быть любими, к примеру можно написать int key; char Data; или добавить еще какие то данные)
	comp* next;//Указатель типа comp на следующий эелемент

};

//struct comp1 { //Структура с именем comp
//	int data1; //Кикие то данные(могут быть любими, к примеру можно написать int key; char Data; или добавить еще какие то данные)
//	comp1* next1;//Указатель типа comp на следующий эелемент
//};

void s_push(comp**, int);
void s_delete_key(comp**, int);
void s_print(comp*);
void s_create(comp*, int);
void s_sort(comp*);
void s_together(comp*,comp*,comp*,int,int);
void s_intersection(comp*,comp*,comp*, int,int);

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N = 0, D = 0, K = 0,Z=0;
	comp* top = NULL;
	comp* top1 = NULL;
	comp* top2 = NULL;
	int c = 123;
	while (c != 0)
	{
		cout << "1-stek, 2-chitka, 3-delete, 4-zadanie, 5-sort, 6-together, 7-intersection, 0-exit" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
		{
			cout << "kolvo elementov" << endl;
			cin >> D;
			for (int i = 0; i < D; i++) {

				s_push(&top, D);

			}
			system("pause");//ставим на паузу
			system("cls");
			K = K + D;
			break;
		}
		case 2:
		{
			s_print(top);//выводим
			system("pause");//ставим на паузу
			system("cls");
			break;
		}
		case 3:
		{
			s_print(top);
			cout << endl;
			cout << "chislo dlya ydaleniya" << endl;
			cin >> N;
			s_delete_key(&top, N);
			printf_s("\n");//переводим на новую строку
			s_print(top);//выводим
			system("pause");//ставим на паузу
			system("cls");
			K--;
			break;
		}
		
		case 5:
		{
			cout << "Было" << endl;
			s_print(top);
			cout <<endl<< "Стало" << endl;
			s_sort(top);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			cout << "Было" << endl;
			s_print(top);
			cout << endl << "Стало" << endl;
			s_together(top,top1,top2,Z,K);
			system("pause");
			system("cls");
			break;

		}
		case 7:
		{
			cout << "1-ый список" << endl;
			s_print(top);
			cout << endl;
			s_intersection(top,top1,top2,Z,K);
			system("pause");
			system("cls");
			break;


		}
		}
	}
}


void s_push(comp** top, int D) { //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
	comp* q; //Создаем новый указатель q, который приравниваем к вершине стека. По сути это и есть наш новый элемент
	q = new comp(); //выделяем память для нового элемента
	

	cin >> q->data; //Записываем D в Data элемента

	if (top == NULL) { //Если вершины нет, тоесть стек пустой
		*top = q; //вершиной стека будет новый элемент
	}
	else //если стек не пустой
	{
		q->next = *top; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
		*top = q; //Пишем, что вершиной теперь является новый элемент
	}
}


void s_delete_key(comp** top, int N) {//функция которая принимает вершину top и число которое нужно удалить
	comp* q = *top; //создаем указатель типа comp и приравниваем(ставим) его на вершину стека
	comp* prev = NULL;//создаем указатель на предыдуший элемент, с начала он будет пустым
	while (q != NULL) {//пока указатель q не путой, мы его будем проверять, если он все же пусть цикл заканчивается
		if (q->data == N) {//если Data элемента равна числу, которое нам нужно удалить
			if (q == *top) {//если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
				*top = q->next;//передвигаем вершину на следующий элемент
				prev = NULL; //запоминаем текущую ячейку как предыдущую
				free(q);//очищаем ячейку
				q->data = NULL; //Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения, а дословно "Чение памяти невозможно" или числа  "-2738568384" или других, в зависимости от компилятора.
				q->next = NULL;
				q = *top;//перемещаем указатель q на следующий элемент
			}
			else//если элемент последний или находится между двумя другими элементами
			{
				prev->next = q->next;//Проводим связь от предыдущего элемента к следующему

				free(q);//очищаем ячейку 
				q->data = NULL;//обнуляем переменные
				q->next = NULL;
				q = prev->next;

			}
		}// если Data элемента НЕ равна числу, которое нам нужно удалxить
		else {
			prev = q; //запоминаем текущую ячейку как предыдущую

			q = q->next;//перемещаем указатель q на следующий элемент
		}

	}
}

void s_print(comp* top) { //принимает указатель на вершину стека		
	comp* q = top; //устанавливаем q на вершину
	while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
		printf_s("%i", q->data);//выводим на экран данные ячейки стека
		cout << ' ';
		q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
	}
}

void s_create(comp* top, int N) {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		comp* q; //Создаем новый указатель q, который приравниваем к вершине стека. По сути это и есть наш новый элемент
		q = new comp(); //выделяем память для нового элемента
		cin >> q->data;
	}
}

void s_sort(comp* top) {
	comp* q = NULL;
	comp* q1;
	double temp;
	while (top->next != q) {
		for (q1 = top; q1->next != q; q1 = q1->next) {
			if (q1->data > (q1->next)->data) {
				temp = q1->data;
				q1->data = (q1->next)->data;
				(q1->next)->data = temp;
			}
		}
		q = q1;
	};
	s_print(top);
	cout << endl;
}
void s_together(comp* top, comp* top1, comp* top2, int Z, int K) {
	cout << "kolvo elementov" << endl;
	cin >> Z;
	for (int i = 0; i < Z; i++) {

		s_push(&top1, Z);

	}
	/*cout << "2-ой список" << endl;
	s_print(top1);*/
	/*comp* top = NULL;
	comp* top1 = NULL;*/
	comp* q = top;
	comp* q1 = top1;
	comp* prev1 = NULL;
	q = top;
	q1 = top1;
	for (int i = 0; i < K; i++)
	{

		{

			comp* q2;
			q2 = new comp();
			q2->data = q->data;
			q = q->next;

			if (top2 == NULL) {
				top2 = q2;
			}
			else
			{

				q2->next = top2;
				top2 = q2;
			}

		}

	}
	cout << "1-ый список" << endl;
	s_print(top2);
	
	cout << endl << "2-ой список" << endl;
	s_print(top1);
	comp* q2 = top2;
	int kol = 0;
while (q1) {
	if (q2 == NULL)
		break;

		for (int j = 1; j < K + 1; j++)
		{
		
			if (q2 == NULL)
			{
				j = K + 1;
				continue;
			}
			while (q1 != NULL)
			{
				if (q2 == NULL)
				{
					j = K + 1;
					break;
				}

				if ((q2->data) == (q1->data))
				{
					kol++;
					q2 = q2->next;

					if (q1 == top1)
					{
						
						
						free(q1);
						q1->data = NULL;
						q1 = top1;
						prev1 = NULL;
						continue;
					}

					else
					{
						if (q1->next == NULL)
						{
							free(q1);
							q1->data = NULL;
							prev1->next = NULL;
							q1 = top1;
							
						
							continue;

						}
						prev1->next = q1->next;
						free(q1);
						q1->data = NULL;
						q1 = top1;
						q1 = prev1;
						
						continue;

					}
				}








				prev1 = q1;
				q1 = q1->next;

			};
			prev1 = NULL;
			q1 = top1;
			/*prev1 = NULL;*/
			if (q2 == NULL)
				break;
			q2 = q2->next;
			if (q2 == NULL)
				break;


		}


	}
cout << endl;


cout << endl << "together" << endl;
q1 = top1;
q1->next = NULL;
prev1 = NULL;
		for (int i = 0;i< (K - kol); i++)
		{
			comp* q2= top2;
			q2 = new comp();
			if (q1 == NULL)
				break;
			q2->data = q1->data;
			
			q1 = q1->next;
		}
		s_print(top2);
		
		
	
}
void s_intersection(comp* top, comp* top1,comp* top2, int Z, int K) {

	cout << "kolvo elementov" << endl;
	cin >> Z;
	for (int i = 0; i < Z; i++) {

		s_push(&top1, Z);

	}
	system("cls");
	cout << "1-ый список" << endl;
	s_print(top);
	cout <<endl<< "2-ой список" << endl;
	s_print(top1);
	/*system("pause");
	system("cls");*/
	/*comp* top = NULL;
	comp* top1 = NULL;*/
	comp* q = top;
	comp* q1 = top1;
	comp* prev1 = NULL;
	q = top;
	q1 = top1;
	while (q) {

		for (int j = 1; j < K+1; j++)
		{
			if (q->next == NULL)
			{
			}
			else if (q != top)
				q = q->next;
			if (q == NULL)
			{
				j = K + 1;
				continue;
			}
			while(q1!=NULL)
			{
				if(q ==NULL)
				{
					j = K + 1;
					break;
				}
				
				if ((q->data) == (q1->data))
				{
					
					comp* q2;
					q2 = new comp();
					q2->data = q->data;
					q = q->next;
					
					if (top2 == NULL) { 
						top2 = q2; 

						if (q1 == top1) 
						{
							top1 = q1->next;
							prev1 = NULL;
							free(q1);
							q1->data = NULL;
							q1->next = NULL;
							q1 = top1;
							continue;
						}

						else
						{
							if (q1->next == NULL)
							{
								free(q1);
								q1->data = NULL;
								q1->next = NULL;
								
								
								break;

							}
							prev1->next = q1->next;
							free(q1);
							q1->data = NULL;
							q1->next = NULL;
							
						}
						

					}
					else 
					{
				
						q2->next = top2; 
						top2 = q2;
					}
					
				}
			
				
				q1 = q1->next;
			}
			q1 = top1;
			if (q == NULL)
				break;
			
			
		}
	}	
	/*cout << "1-ый список" << endl;
	s_print(top);
	cout << endl << "2-ой список" << endl;
	s_print(top1);*/
	cout<<endl << "Пересечение ";
	s_print(top2);

}
