from datetime import datetime

import pytest

from src.entities import MedicalRecord, User, Doctor
from src.repositories import UserRepository
from src.utils import print_medical_history


def test_medical_record_creation():
    test_datetime = datetime.now()
    record = MedicalRecord(
        date=test_datetime,
        symptoms="headache",
        drugs="Aspirin",
        recommendations="Rest well."
    )
    assert record.date == test_datetime
    assert record.symptoms == "headache" 
    assert record.drugs == "Aspirin"
    assert record.recommendations == "Rest well."

def test_doctor_consultation():
    doctor = Doctor()
    symptoms = "928y38-428ihuawnoibiuwercuwbworf"
    drugs, recoms = doctor.consultation(symptoms)
    assert type(drugs) == str
    assert type(recoms) == str

def test_adding_medical_record():
    user = User(name="Matthew McConaughey", medical_history=[])
    record = MedicalRecord(
        date=datetime.now(),
        symptoms="Interstellar",
        drugs="True Detective",
        recommendations="Dallas Buyers Club"
    )
    user.add_medical_record(record)
    assert len(user.medical_history) == 1
    assert user.medical_history[0].date == record.date
    assert user.medical_history[0].symptoms == record.symptoms
    assert user.medical_history[0].drugs == record.drugs
    assert user.medical_history[0].recommendations == record.recommendations

def test_printing_medical_history(capsys):
    user = User(
        name="Matthew McConaughey", medical_history=[
        MedicalRecord(
            date=datetime.now(),
            symptoms="Interstellar",
            drugs="True Detective",
            recommendations="Dallas Buyers Club"
        )
    ])
    print_medical_history(user.medical_history)
    captured = capsys.readouterr()
    assert "Interstellar" in captured.out
    assert "True Detective" in captured.out
    assert "Dallas Buyers Club" in captured.out

def test_user_repository():
    user = User(
        name="Matthew McConaughey", medical_history=[
        MedicalRecord(
            date=datetime.now(),
            symptoms="Interstellar",
            drugs="True Detective",
            recommendations="Dallas Buyers Club"
        )
    ])
    user_repo = UserRepository("test.json")
    user_repo.save(user)
    loaded_user = user_repo.load()
    assert user.name == loaded_user.name
    assert user.medical_history[0].date == loaded_user.medical_history[0].date
    assert user.medical_history[0].symptoms == loaded_user.medical_history[0].symptoms
    assert user.medical_history[0].drugs == loaded_user.medical_history[0].drugs
    assert user.medical_history[0].recommendations == loaded_user.medical_history[0].recommendations


if __name__ == "__main__":
    pytest.main()