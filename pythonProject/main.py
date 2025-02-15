from Attraction import Attraction
from Guide import Guide
from Photo import Photo
from Route import Route
from Map import Map

def main():
    guide = Guide()
    map = Map()

    while True:
        print("\nЭлектронный гид")
        print("1. Добавить достопримечательность")
        print("2. Посмотреть информацию")
        print("3. Создать маршрут")
        print("4. Показать маршруты")
        print("5. Показать карту")
        print("6. Выйти")

        choice = input("Выберите действие: ")

        if choice == "1":
            name = input("Название: ")
            description = input("Описание: ")
            guide.add_attraction(Attraction(name, description),map)

        elif choice == "2":
            name = input("Название достопримечательности: ")
            attraction = guide.find_attraction(name)
            if attraction:
                print(attraction.show_info())
                print("1.Добавить фото")
                print("2.Добавить отзыв")
                print("3.Изменить 'не посетил' на 'посетил' ")
                choice_att = input("Выберете действие: ")
                if choice_att == "1":
                    try:
                        photo = input("Введите фото : ")
                        temp = Photo(photo)
                        attraction.add_photo(temp)
                    except ValueError as error:
                        print(error)
                elif choice_att == "2":
                    try:
                        review = input("Введите отзыв: ")
                        attraction.add_review(review)
                    except ValueError as error:
                        print(error)
                elif choice_att == "3":
                    attraction.change_visiting()

            else:
                print("Не найдено!")

        elif choice == "3":
            name = input("Название маршрута: ")
            attractions = input("Достопримечательности (через запятую): ").split(", ")
            guide.create_route(name, attractions)

        elif choice == "4":
            for route in guide.routes:
                print(route.show_route())

        elif choice == "5":
            guide.show_map(map)
            user_input = input("Введите номер достопремечательности,о котрой хотите узнать больше(exit - для выхода): ")
            while True:

                try:
                    if user_input == exit:
                        break
                    number = int(user_input)
                    guide.show_attraction_info(map, number)
                    break
                except ValueError:
                    print("Не верный ввод числа")

        elif choice == "6":
            break


if __name__ == "__main__":
    main()