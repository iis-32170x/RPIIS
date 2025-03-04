import os
from datetime import datetime
import time
import webbrowser

import questionary

from .entities import Doctor, MedicalRecord, User
from .repositories import UserRepository
from .utils import print_medical_history

repo = UserRepository("src/users.json")

def main_menu(user: User):
    choice = questionary.select(
        "Главное меню. Выберите действие: ",
        choices=[
            "Профиль",
            "Врач",
            "Поиск клиники",
            "Выход"
        ]
    ).ask()

    if choice == "Профиль":
        profile_menu(user)
    elif choice == "Врач":
        doctor_menu(user)
    elif choice == "Поиск клиники":
        clinic_menu(user)
    elif choice == "Выход":
        return


def profile_menu(user: User):
    choice = questionary.select(
        "Меню Профиль. Выберите действие: ",
        choices=[
            "Медицинская история",
            "Напоминание о приеме лекарств",
            "Назад"
        ]
    ).ask()

    if choice == "Медицинская история":
        print_medical_history(user.medical_history)
    elif choice == "Напоминание о приеме лекарств":
        remind_time = questionary.text("Введите количество секунд, через которое напомнить вам принять лекарства: ").ask()
        command = (
            f"nohup sh -c 'sleep {remind_time} && "
            f"notify-send \"Медицинский ассистент\" \"{user.name}, пора принимать лекарства!\"' "
            ">/dev/null 2>&1 &"
        )
        os.system(command)
    elif choice == "Назад":
        pass

    main_menu(user)


def doctor_menu(user: User):
    choice = questionary.select(
        "Меню Врач. Выберите действие: ",
        choices=[
            "Консультация онлайн",
            "Назад"
        ]
    ).ask()

    if choice == "Консультация онлайн":
        doctor = Doctor()
        symptoms = questionary.text("Введите ваши симптомы: ").ask()
        drugs, recommendations = doctor.consultation(symptoms)
        drugs, recommendations = drugs.strip("\n"), recommendations.strip("\n")

        print(f"Лекарства: {drugs}\nРекомендации: {recommendations}")

        record = MedicalRecord(
            date=datetime.now().replace(microsecond=0),
            symptoms=symptoms,
            drugs=drugs,
            recommendations=recommendations
        )
        user.add_medical_record(record)
        repo.save(user)
    elif choice == "Назад":
        pass

    main_menu(user)


def clinic_menu(user: User):
    choice = questionary.select(
        "Меню Клиника. Выберите действие:",
        choices=[
            "Поиск ближайшей клиники",
            "Назад"
        ]
    ).ask()

    if choice == "Поиск ближайшей клиники":
        url = "https://yandex.by/maps/157/minsk/search/%D0%BA%D0%BB%D0%B8%D0%BD%D0%B8%D0%BA%D0%B0/" \
              "?ll=27.601790%2C53.914489&sll=27.603632%2C53.915121&sspn=0.075315%2C0.028358&z=13.95"
        webbrowser.open(url)
        main_menu(user)
    elif choice == "Назад":
        main_menu(user)
