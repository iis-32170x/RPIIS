import os

from pymongo import MongoClient
from pymongo.collection import Collection
from pymongo.database import Database

from models import Sportsman

class SportsmanRepository():
    """
    Database repository for interact with database
    """
    def __init__(self):
        self.client = MongoClient(os.getenv("MONGO_DB_URL"))
        self.db: Database = self.client["ppois2db"]
        self.sportsmen_coll: Collection[Sportsman] = self.db["sportsmen"]

    def get_all(self) -> list[Sportsman]:
        sportsmen = self.sportsmen_coll.find()
        return list(map(Sportsman.model_validate, sportsmen))

    def get_by_filters(self, filters: dict[str, str]) -> list[Sportsman]:
        sportsmen = self.sportsmen_coll.find(filters)
        return list(map(Sportsman.model_validate, sportsmen))

    def add(self, sportsman: Sportsman) -> None:
        self.sportsmen_coll.insert_one(sportsman.model_dump())

    def delete(self, sportsman: Sportsman) -> None:
        filters = sportsman.model_dump()
        self.sportsmen_coll.delete_one(filters)

    def delete_by_filters(self, filters: dict[str, str]) -> None:
        self.sportsmen_coll.delete_one(filters)
