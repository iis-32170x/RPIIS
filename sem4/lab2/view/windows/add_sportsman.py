from PySide6.QtWidgets import (
    QDialog,
    QLineEdit,
    QMessageBox,
    QSpinBox,
    QPushButton,
    QVBoxLayout,
    QLabel
)
from controller import SportsmanController
from faker import Faker


class AddSportsmanWindow(QDialog):
    """
    Window representing interface for filling data, that will be added to database
    """
    def __init__(self):
        super().__init__()
        self.controller = SportsmanController()

        self.setObjectName("Add sportsman")
        self.resize(300, 400)
        
        self.setup_ui()
        self.setup_buttons()
        self.setup_signals()

    def setup_signals(self):
        self.controller.validationFailed.connect(self.show_validation_error)
        self.controller.sportsmanAdded.connect(self.close)
    
    def show_validation_error(self):
        QMessageBox.critical(self, "Ошибка", "Проверьте правильность введенных данных")

    def setup_ui(self):
        main_layout = QVBoxLayout(self)

        # ввод имени
        self.name_input = QLineEdit()
        self.name_label = QLabel("ФИО спортсмена")
        self.name_input.setMaxLength(30)
        main_layout.addWidget(self.name_label)
        main_layout.addWidget(self.name_input)

        # выбор состава
        self.status_input = QLineEdit()
        self.status_label = QLabel("Состав")
        self.status_input.setMaxLength(30)
        main_layout.addWidget(self.status_label)
        main_layout.addWidget(self.status_input)

        # выбор позиции
        self.position_input = QLineEdit()
        self.position_label = QLabel("Позиция")
        self.position_input.setMaxLength(30)
        main_layout.addWidget(self.position_label)
        main_layout.addWidget(self.position_input)

        # спинбокс колва титулов
        self.title_count_selector = QSpinBox()
        self.title_count_label = QLabel("Число титулов")
        self.title_count_selector.setRange(0, 30)
        main_layout.addWidget(self.title_count_label)
        main_layout.addWidget(self.title_count_selector)

        # выбор вида спорта
        self.sport_type_input = QLineEdit()
        self.sport_type_label = QLabel("Вид спорта")
        self.sport_type_input.setMaxLength(30)
        main_layout.addWidget(self.sport_type_label)
        main_layout.addWidget(self.sport_type_input)

        # выбор разряда
        self.rank_input = QLineEdit()
        self.rank_label = QLabel("Разряд")
        main_layout.addWidget(self.rank_label)
        main_layout.addWidget(self.rank_input)

        # кнопка добавить
        self.add_button = QPushButton("Добавить")
        main_layout.addWidget(self.add_button)

        # кнопка заполнить случайными данными
        self.random_button = QPushButton("Случайные данные")
        self.random_button.clicked.connect(self.set_random_data)
        main_layout.addWidget(self.random_button)
        
        main_layout.addStretch()

        self.setLayout(main_layout)
    
    def set_random_data(self):
        fake = Faker()
        self.name_input.setText(fake.name())
        self.status_input.setText(fake.word())
        self.position_input.setText(fake.job())
        self.title_count_selector.setValue(fake.random_int(min=0, max=30))
        self.sport_type_input.setText(fake.word())
        self.rank_input.setText(fake.sentence(nb_words=1))

    def setup_buttons(self):
        self.add_button.clicked.connect(self.add_sportsman)

    def get_inputed_data(self) -> dict:
        data = {
            'name': self.name_input.text(),
            'status': self.status_input.text(),
            'position': self.position_input.text(),
            'title_count': self.title_count_selector.value(),
            'sport_type': self.sport_type_input.text(),
            'rank': self.rank_input.text()
        }
        return data

    def add_sportsman(self):
        data = self.get_inputed_data()
        self.controller.add_record(data)
