<h1>Лабораторная работа №1</h1>
<h2>Вариант 24</h2>
- Цель - Вставка элемента в список/ удаление элемента из списка/ cортировка списка/ поиск элемента в списке/
объединение двух списков/ пересечение двух списков; <br/>
- Задача - Реализовать библиотеку обработки двунаправленного (двусвязного) списка;<br/>
<hr/>
<h3>Список ключевых понятий и определений</h3>
- <b><em>Структура данных</em></b> — это способ организации данных. В зависимости от того, какими данными мы хотим манипулировать и что с ними делать,
— должны выбрать ту или иную структуру данных, которая идеально подходит для нашего случая.<br/>
- <b><em>Свя́зный спи́сок</em> — базовая динамическая структура данных в информатике, состоящая из узлов, содержащих данные и ссылки на следующий и/или предыдущий узел списка.<br/>
- <b><em>Двусвязный (двунаправленный) список</em></b> — это разновидность связного списка, при которой переход по элементам возможен в обоих направлениях (как вперед, так и назад), в отличие от односвязного (однонаправленного) списка.<br/>
- <b><em>Ссылка</em></b> - в каждой ссылке связного списка могут храниться данные, называемые элементом.<br/>
- <b><em>Следующая ссылка</em></b> - в каждой ссылке связного списка содержится ссылка на следующую ссылку (<i>Next</i>).<br/>
- <b><em>Предыдущая ссылка</em></b> - в каждой ссылке связного списка содержится ссылка на предыдущую ссылку (<i>Prev</i>).<br/>
<hr/>
<h3>Алгоритм выполнения индивидуального задания</h3>
Основной и главной задачей данной лабораторной работы является реализация полностью функционирующей библиотеки для работы
с такой структурой данных как двунаправленный (он же двусвязный список).<br/>
Для начала нужно понять то, что двунаправленный список является раширенной версией односвязного списка, т.е. основным их отличием
является количество полей основной структуры узлов, несущих информацию. Он будет иметь вид:<br/>

![DCS](https://github.com/iis-32170x/RPIIS/assets/144940569/6ca20134-855f-4f22-8574-4c08cd444ca5)

  Структура и конструктор узлов списка (здесь используется struct, т.к. все его поля по умолчанию public, и в дальнейшем нам не
  придётся менять модификатор доступа) будут выглядеть так:
<code>
{ // Структура узла из трёх полей
    struct Node {
        int value;
        Node* next;
        Node* prev;

        // Конструктор узлов
        Node(int v, Node* n, Node* p) {
            value = v;
            next = n;
            prev = p;
        }
    };
</code>
Для создания основного класса списка, в private будут описаны такие свойства, как счётчик элементов, указатель на  головной 
элемент (head), а также указатель на хвост (tail) на выше описанную структуру.
<code>
class LinkedList {

private:
    Node* head;
    Node* tail;
    int elementCount;
    ...
</code>
В результате каждому объекту класса списка будет доступен адрес на его головной и хвостовой узлы, и общее число узлов. В то же время
каждый узел будет знать своих соседей по адресам (next и prev) и иметь некоторое хранимое значение (в данной реализации тип int).<br/>
Во избежание заполнения начального списка мусором, создадим конструктор со значениями по умолчанию:
<code>
LinkedList() {
        head = nullptr;
        tail = nullptr;
        elementCount = 0;
    }
</code>
<hr/>
<h4>Описание основных методов библиотеки</h4>
Метод для получения информации о длине списка (количестве его узлов).<br/>
<code>int LinkedList::GetSize() const {
    return elementCount;
}</code><br/>
<hr/>
Метод, проверяющий список на наличие узлов.<br/>
<code>bool LinkedList::CheckEmpty() const {
    return elementCount == 0;
}</code><br/>
<hr/>
Метод, добавляющий узел в начало списка.<br/>
<code>void LinkedList::pushFront(int value) {
    Node* newNode = new Node(value, head, nullptr);
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    elementCount++;
}</code><br/>
<hr/>
Метод, удаляющий узел из начала списка.<br/>
<code>void LinkedList::popFront() {
    if (head != nullptr) {
        Node* oldHead = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete oldHead;
        elementCount--;
    }
}</code><br/>
<hr/>
Деструктор списка.<br/>
<code> LinkedList::~LinkedList() {
     while (!CheckEmpty()) {
         popFront();
     }
 }</code><br/>
 <hr/>
Метод, добавляющий элемент в конец списка.<br/>
<code>void LinkedList::pushBack(int value) {
    Node* newNode = new Node(value, nullptr, tail);
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    elementCount++;
}</code><br/>
<hr/>
Метод, удаляющий элемент из конца списка.<br/>
<code>void LinkedList::popBack() {
    if (tail != nullptr) {
        Node* oldTail = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete oldTail;
        elementCount--;
    }
}</code><br/>
<hr/>
Метод, добавляющий новый узел, после заданного узла (через метод getNode).<br/>
<code>void LinkedList::insertAfter(Node* elem, int value) {
    if (elem == tail) {
        pushBack(value);
    }
    else {
        Node* n = new Node(value, elem->next, elem);
        elem->next->prev = n;
        elem->next = n;
        elementCount++;
    }
}</code><br/>
<hr/>
Метод, позволяющий узнать адрес заданного узла по его индексу (дпнная библиотека отсчитывает индкы от 0).<br/>
<code>Node* LinkedList::getNode(int index) {
    Node* n = head;
    for (int i = 0; i < index && n != nullptr; i++) {
        n = n->next;
    }
    return n;
}</code><br/>
      <hr/>
Метод, добавляющий новый узел перед заданным узлом.<br/>
<code>void LinkedList::insertBefore(Node* elem, int value) {
    if (elem == head) {
        pushFront(value);
    }
    else {
        Node* n = new Node(value, elem, elem->prev);
        elem->prev->next = n;
        elem->prev = n;
        elementCount++;
    }
}</code><br/>
      <hr/>
Метод сортировки списка (BubbleSort).<br/>
<code>void LinkedList::Sort() {
    if (CheckEmpty()) {
        return;
    }
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->value > current->next->value) {
                std::swap(current->value, current->next->value);
                sorted = false;
            }
            current = current->next;
        }
    }
}</code><br/>
      <hr/>
Метод слияния (объединения) двух списков, в новый список.<br/>
<code>LinkedList LinkedList::merge(LinkedList& otherList) const {
    LinkedList mergedList;
    Node* currentOther = otherList.head;
    Node* currentThis = head;

    // Первый список
    while (currentThis != nullptr) {
        mergedList.pushBack(currentThis->value);
        currentThis = currentThis->next;
    }
    
    // Второй список
    while (currentOther != nullptr) {
        mergedList.pushBack(currentOther->value);
        currentOther = currentOther->next;
    }

    return mergedList;
}</code><br/>
<hr/>
Метод пересечения двух списков, в новый список.<br/>
<code>    LinkedList LinkedList::intersection(LinkedList& otherList) const {
        LinkedList intersectedList;

        Node* currentOther = otherList.head;
        while (currentOther != nullptr) {
            Node* currentThis = head;
            while (currentThis != nullptr) {
                if (currentThis->value == currentOther->value) {
                    intersectedList.pushBack(currentThis->value);
                    break;
                }
                currentThis = currentThis->next;
            }
            currentOther = currentOther->next;
        }

        return intersectedList;
    }
}</code><br/>
<hr/>
Метод удаления узла по его адресу.<br/>
<code>void LinkedList::erase(Node* elem) {
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    delete elem;
    elementCount--;
}</code><br/>
<hr/>
Метод, позволяющий узнать значение первого узла.<br/>
<code>int LinkedList::getFront() const {
    return head->value;
}</code><br/>
<hr/>
Метод, позволяющий узнать значение последнего узла.<br/>
<code>int LinkedList::getBack() const {
    return tail->value;
}</code><br/>
<hr/>
Метод, позволяющий узнать значение заданного узла.<br/>
<code>int LinkedList::getValue(int index) {
    Node* node = getNode(index);
    if (node != nullptr) {
        return node->value;
    }
}</code><br/>
<hr/>
Метод вывода списка и его просмотра.<br/>
<code>void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}</code>
<hr/>
<h3>Тестирование основных функций библиотеки</h3>
Тестирование функций библиотеки основывается на использовании Google C++ Testing Framework, который по умолчанию встроен 
в последние версии Visual Studio. Далее приведена структура и вид созданных тестов для разных функций библиотеки, а также демонстрируется 
общий результат тестирования всех методов.
<h4>Разбор простого приимера для лучшего понимания работы Frameworkа</h4>
<code>
  TEST(LinkedListTest, PushFrontTest) { //Начало теста -> Название группы тестов -> Имя теста
	LinkedList list;   // Создаём двунаправленный и добавляем в него элементы, учитывая последовательность
	list.pushFront(2); // Порядок: 2
	list.pushFront(1); // Порядок: 1 2 - т.к. вставка вперёд

	EXPECT_EQ(list.GetSize(), 2); // Сравниваем число узлов списка, с приведённым -> 2=2
	EXPECT_EQ(list.getFront(), 1); // Сравниваем значение первого узла списка с приведённым -> 1=1
	EXPECT_EQ(list.getBack(), 2); // Сравниваем значение последнего узла списка с приведённым -> 2=2
 // Если тест будет успешно пройден, то мы получим соответствующий результат
}
</code>
Общий вид тестов:

![Снимок экрана (51)](https://github.com/iis-32170x/RPIIS/assets/144940569/321ac5eb-85f3-4f6e-952d-136a8d2ab649)

![Снимок экрана (52)](https://github.com/iis-32170x/RPIIS/assets/144940569/e24c3d19-2180-403f-a1f4-7d944789e8fa)

![Снимок экрана (53)](https://github.com/iis-32170x/RPIIS/assets/144940569/b08fa3a4-dde7-41e7-a676-0845843c167c)

![Снимок экрана (54)](https://github.com/iis-32170x/RPIIS/assets/144940569/68747074-544d-44e7-b668-c379dfa97fb2)

Результат тестов:

![Снимок экрана (55)](https://github.com/iis-32170x/RPIIS/assets/144940569/5c9f8781-71b0-4b2a-bef8-ca686083f639)


<hr/>
<h2>Вывод</h2>
Реализовал библиотеку обработки динамической структуры двунаправленный список.
<hr/>
<h3>Использованные источники</h3>
- [Олимпиадное программирование в УлГТУ| Двусвязный список](https://www.youtube.com/watch?v=A7NJbC66AFE&t=98s)

    
