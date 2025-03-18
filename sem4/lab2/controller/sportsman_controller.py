from PySide6.QtCore import QObject, Signal
from utils import logger

from database import SportsmanRepository
from database.xml_service import XMLService
from models import Sportsman


class SportsmanController(QObject):
    validationFailed = Signal()
    sportsmanAdded = Signal()

    def __init__(self):
        super().__init__()
        self.repo = SportsmanRepository()
        self.xml_service = XMLService("sportsmen", "sportsman")

    def get_all_records(self) -> list[Sportsman]:
        return self.repo.get_all()

    def add_record(self, data: dict[str, str]) -> None:
        try:
            sportsman = Sportsman.model_validate(data)
        except ValueError:
            logger.error("Error while validating fields. Maybe some fields are missing")
            self.validationFailed.emit()
            return

        self.repo.add(sportsman)
        logger.success("Sportsman added")
        self.sportsmanAdded.emit()

    def delete_records(self, records: list[dict[str, str]]) -> None:
        if not records:
            logger.debug("No sportsmen to delete")
            return
        
        # title_count в таблице хранится как str, а в бд как int, поэтому
        # сначала валидируем запись из таблицы в объект класса (title_count становится int)
        # потом дампим его в словарь, чтобы удалить из бд
        sportsmen = list(map(Sportsman.model_validate, records))

        for sportsman in sportsmen:
            filters = sportsman.model_dump()
            self.repo.delete_by_filters(filters)

        logger.success(f"{len(records)} sportsmen deleted")
    
    def get_records_by_filters(self, filters: dict[str, str]) -> list[Sportsman]:
        sportsmen = self.repo.get_by_filters(filters)
        return sportsmen

    def export_to_xml_file(self, filename: str) -> None:
        sportsmen = self.get_all_records()
        sportsmen = list(map(Sportsman.model_dump, sportsmen))

        xml = self.xml_service.dicts_to_xml(sportsmen)
        with open(filename, 'w', encoding="utf-8") as file:
            file.write(xml)

        logger.success("XML was successfully written to a file")

    def import_from_xml_file(self, filename: str) -> list[Sportsman]:
        with open(filename, 'r', encoding="utf-8") as file:
            xml = file.read()
            data = self.xml_service.xml_to_dicts(xml)
            sportsmen = list(map(Sportsman.model_validate, data))
            return sportsmen
        
    def overwrite_db(self, sportsmen: list[Sportsman]):
        for sportsman in self.repo.get_all():
            self.repo.delete(sportsman)
        
        for sportsman in sportsmen:
            self.repo.add(sportsman)

        logger.success("Database was successfully overwritten")
