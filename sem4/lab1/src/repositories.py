from .entities import User


class UserRepository:
    """
    Represents a repository for saving and loading user data.

    Attributes
    ----------
    filepath : str
        The path to the file where the user data is stored.
    """

    def __init__(self, filepath: str):
        self.__filepath = filepath

    def save(self, user: User) -> None:
        with open(self.__filepath, 'w', encoding="utf8") as file:
            file.write(user.model_dump_json(indent=4))

    def load(self) -> User:
        with open(self.__filepath, 'r', encoding="utf8") as file:
            json_data = file.read()
            return User.model_validate_json(json_data)
    
    
