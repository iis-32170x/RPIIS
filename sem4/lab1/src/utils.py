from tabulate import tabulate

from .entities import MedicalRecord


def print_medical_history(med_history: list[MedicalRecord]) -> None:
    if not med_history:
        print("Медицинская история пуста")
        return
    data = [
        [
            record.date, record.symptoms, record.drugs, record.recommendations
        ] for record in med_history
    ]
    headers = ["Время", "Симптомы", "Лекарства", "Рекомендации"]

    print(tabulate(data, headers=headers, tablefmt="grid"))
