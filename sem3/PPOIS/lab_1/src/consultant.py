from typing import Dict, Tuple, Optional


class Consultant:
    def __init__(self) -> None:
        self.questions: Dict[int, Tuple[str, str]] = { 
            1: ("Можно ли вернуть товар?", "Конечно, для возврата товара нужно воспользоваться соответствующей опцией"),
            2: ("Что будет, если выиграть в акции?", "Вы сможете выиграть 20 BYN"),
            3: ("Трудно ли писать вопросы для воображаемого сайта?", "Это развивает фантазию"),
            4: ("Не вернули деньги за возврат. Что делать?", "А вы докажите, что возвращали"),
            5: ("Время работы", "с 8:00 до 22:00")
        }

    def show_questions(self) -> None:
        print("Часто задаваемые вопросы:\n")
        for num, (question, _) in self.questions.items():
            print(f"{num}. {question}")

    def get_answer(self, num: int) -> Optional[str]:
        if num in self.questions: 
            question, answer = self.questions[num]
            return answer
        else:
            return None
        
    def choice_question(self) -> None:
        while True:
            try:
                choice = int(input("Введите номер вопроса: "))
                answer = self.get_answer(choice)
                if answer:
                    print(answer)
                    break
                else:
                    print("Вопрос с таким номером не найден")
            except ValueError:
                print("Пожалуйста, введите правильное число\n")