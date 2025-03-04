import os

from dotenv import load_dotenv, find_dotenv
from loguru import logger
from pydantic import ValidationError

from src.repositories import UserRepository
from src.entities import User
from src.menus import main_menu

load_dotenv(find_dotenv(), override=True)


def main():
    repo = UserRepository("src/users.json")
    try:
        user = repo.load()
    except (ValidationError, FileNotFoundError):
        logger.error("Error while loading user from file. Recreating...")
        user = User(name="Nikita", medical_history=[])
        repo.save(user)
    main_menu(user)


if __name__ == "__main__":
    main()
