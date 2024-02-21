<h1>Лабораторная работа №1</h1>
<h2>Вариант 24</h2>
Цель - Вставка элемента в список/ удаление элемента из списка/ cортировка списка/ поиск элемента в списке/
объединение двух списков/ пересечение двух списков; <br/>
Задача - Реализовать библиотеку обработки двунаправленного (двусвязного) списка;<br/>
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
<h3>Алгоритм выполнения</h3>
  
![image](https://github.com/iis-32170x/RPIIS/assets/144939284/8e308fcf-b1ac-4f08-8db7-9f989a6c72a3)

1.Начинается все с обьявления двух классов Node, с его полями data(элементы списка) и ссылки на элементы prev и next.
  
  Класс Linklist - это и есть наш двунаправленный список, с его полями head(первый элемент), tail(последний)
  
  class Node:
  
    def __init__(self, data):
    
        self.data = data
        
        self.prev = None
        
        self.next = None

class LinkList:

    def __init__(self):
    
        self.head = None
        
        self.tail = None

2.Дальше мы создаем метод append который добавляет элементы в конец списка


def append(self, data):

    new_node = Node(data)
    if self.head is None:
        self.head = new_node
        self.tail = new_node
        
    else:
        new_node.prev = self.tail
        self.tail.next = new_node
        self.tail = new_node

3.Дальше мы создаем метод который будет добавлять элементы в начало списка

def prepend(self, data):

    new_node = Node(data)
    if self.head is None:
        self.head = new_node
        self.tail = new_node
    else:
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

4.Дальше мы добавляем метод который будет искать есть ли элемент в списке

def search(self, data):

    current = self.head
    while current:
        if current.data == data:
            return True
        current = current.next
    return False

5.Метод который ищет элемент по его индексу

def rsearch(self, index):

    if index >= 0:
        current = self.head
        position = 0
        while current:
            if position == index:
                return current.data
            current = current.next
            position += 1
    else:
        current = self.tail
        position = -1
        while current:
            if position == index:
                return current.data
            current = current.prev
            position -= 1
    return None

6.Метод который удаляет элемент из списка

def delete(self, data):

    current = self.head
    while current:
        if current.data == data:
            if current.prev:
                current.prev.next = current.next
            else:
                self.head = current.next
            if current.next:
                current.next.prev = current.prev
            else:
                self.tail = current.prev
            return
        current = current.next

7.Метод который находит обЪединение двух списков

def merge(self, other_list):

    new_list = LinkList()
    current = self.head

    while current:
        new_list.append(current.data)
        current = current.next

    current = other_list.head
    while current:
        if not new_list.search(current.data):
            new_list.append(current.data)
        current = current.next

    return new_list

8.Метод  который нажодит пересечение двух списков

def intersection(self, other_list):

    new_list = LinkList()
    current = self.head
    while current:
        if other_list.search(current.data):
            new_list.append(current.data)
        current = current.next
    return new_list

9.Метод который сортирует элементы по возростанию

 def vosr_sort(self):
 
     if self.head is None or self.head.next is None:
         return

     sorted_head = self.head
     unsorted_head = self.head.next
     sorted_head.next = None
     unsorted_head.prev = None

     while unsorted_head:
         current = unsorted_head
         unsorted_head = unsorted_head.next
         current.prev = None
         current.next = None

         if current.data < sorted_head.data:
             current.next = sorted_head
             sorted_head.prev = current
             sorted_head = current
         else:
             temp = sorted_head
             while temp.next and temp.next.data < current.data:
                 temp = temp.next
             current.next = temp.next
             if temp.next:
                 temp.next.prev = current
             temp.next = current
             current.prev = temp

     self.head = sorted_head
     self.tail = current

10. Сортировка по убыванию

   def ubiv_sort(self):
   
       if self.head is None or self.head.next is None:
           return

       sorted_head = self.head
       unsorted_head = self.head.next
       sorted_head.next = None
       unsorted_head.prev = None

       while unsorted_head:
           current = unsorted_head
           unsorted_head = unsorted_head.next
           current.prev = None
           current.next = None

           if current.data > sorted_head.data:
               current.next = sorted_head
               sorted_head.prev = current
               sorted_head = current
           else:
               temp = sorted_head
               while temp.next and temp.next.data > current.data:
                   temp = temp.next
               current.next = temp.next
               if temp.next:
                   temp.next.prev = current
               temp.next = current
               current.prev = temp

       self.head = sorted_head
       self.tail = current
       
11.Создаем экземпляр класса LinkList вызываем методы(любые) а также прописываем цикл для вывода результата.


my_list = LinkList()


my_list.append(4)
my_list.append(2)
my_list.append(7)
my_list.append(1)



my_list.ubiv_sort()



print("Elements in the list:")
current = my_list.head
while current:
    print(current.data)
    current = current.next

<h3>Тестирование программы</h3>

<img width="897" alt="Снимок экрана 2024-02-21 211129" src="https://github.com/iis-32170x/RPIIS/assets/144939284/bb16a7fc-8b10-417e-b80d-1649e6b60dce">

<img width="917" alt="Снимок экрана 2024-02-21 211057" src="https://github.com/iis-32170x/RPIIS/assets/144939284/db38b76a-b89c-45ff-adcf-ec4fbc837250">

<img width="971" alt="Снимок экрана 2024-02-21 210958" src="https://github.com/iis-32170x/RPIIS/assets/144939284/77acbe24-a9ad-4bee-9cf0-914d300409f4">




