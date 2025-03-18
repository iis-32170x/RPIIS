from PySide6.QtWidgets import QApplication
from dotenv import load_dotenv, find_dotenv

from view.windows import MainWindow

load_dotenv(find_dotenv(), override=True)


if __name__ == "__main__":
    app = QApplication()
    window = MainWindow()
    window.resize(750, 650)
    window.show()
    app.exec()