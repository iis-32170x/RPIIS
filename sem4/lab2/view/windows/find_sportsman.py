from PySide6.QtWidgets import QComboBox, QDialog, QHBoxLayout, QLineEdit, QSpinBox, QPushButton, QVBoxLayout, QLabel

from controller import SportsmanController
from utils import logger
from view import Table


class FindSportsmanWindow(QDialog):
    def __init__(self):
        # TODO сюда тоже пагинатор бахнуть
        super().__init__()
        self.controller = SportsmanController()

        self.table = Table()

        self.setObjectName("Find sportsman")
        self.resize(800, 400)
        
        self._setup_ui()
        self._setup_buttons()

    def _setup_ui(self):
        sportsmen = self.controller.get_all_records()

        left_layout = QVBoxLayout() # кнопки
        right_layout = QVBoxLayout() # таблица

        # ввод имени
        self.name_input = QLineEdit()
        self.name_label = QLabel("ФИО спортсмена")
        self.name_input.setMaxLength(30)
        left_layout.addWidget(self.name_label)
        left_layout.addWidget(self.name_input)

        # выбор состава
        self.status_selector = QComboBox()
        self.status_label = QLabel("Состав")
        self.unique_statuses = ["Не важно"] + sorted(list(set([f"{sportsman.status}" for sportsman in sportsmen])))
        self.status_selector.addItems(self.unique_statuses)
        left_layout.addWidget(self.status_label)
        left_layout.addWidget(self.status_selector)

        # выбор позиции
        self.position_selector = QComboBox()
        self.position_label = QLabel("Позиция")
        self.unique_positions = ["Не важно"] + sorted(list(set([f"{sportsman.position}" for sportsman in sportsmen])))
        self.position_selector.addItems(self.unique_positions)
        left_layout.addWidget(self.position_label)
        left_layout.addWidget(self.position_selector)

        # спинбокс колва титулов
        self.title_count_selector = QSpinBox()
        self.title_count_label = QLabel("Число титулов")
        self.title_count_selector.setRange(-1, 30)

        left_layout.addWidget(self.title_count_label)
        left_layout.addWidget(self.title_count_selector)

        # выбор вида спорта
        self.sport_type_selector = QComboBox()
        self.sport_type_label = QLabel("Вид спорта")
        self.unique_sport_types = ["Не важно"] + sorted(list(set([f"{sportsman.sport_type}" for sportsman in sportsmen])))
        self.sport_type_selector.addItems(self.unique_sport_types)
        left_layout.addWidget(self.sport_type_label)
        left_layout.addWidget(self.sport_type_selector)

        # выбор разряда
        self.rank_selector = QComboBox()
        self.rank_label = QLabel("Разряд")
        self.unique_ranks = ["Не важно"] + sorted(list(set([f"{sportsman.rank}" for sportsman in sportsmen])))
        self.rank_selector.addItems(self.unique_ranks)
        left_layout.addWidget(self.rank_label)
        left_layout.addWidget(self.rank_selector)
        
        # кнопка найти
        self.find_button = QPushButton("Найти")
        left_layout.addWidget(self.find_button)
        
        left_layout.addStretch()


        # таблица результатов поиска
        right_layout.addWidget(self.table)

        main_layout = QHBoxLayout(self)
        main_layout.addLayout(left_layout, 1)
        main_layout.addLayout(right_layout, 2)
        
        self.setLayout(main_layout)
        self.setLayout(left_layout)

    def _setup_buttons(self):
        self.find_button.clicked.connect(self._find_sportsman)

    def _get_search_params(self):
        data = {
            'name': self.name_input.text(),
            'status': self.status_selector.currentText(),
            'position': self.position_selector.currentText(),
            'title_count': self.title_count_selector.value(),
            'sport_type': self.sport_type_selector.currentText(),
            'rank': self.rank_selector.currentText()
        }

        filtered_data = {
            key: value for key, value in data.items()
            if value != '' and value != "Не важно" and value != -1
        }

        return filtered_data

    def _find_sportsman(self):
        filters = self._get_search_params()
        sportsmen = self.controller.get_records_by_filters(filters)
        logger.debug(f"Filters: {filters}")
        logger.debug(f"Found sportsmen: {sportsmen}")

        self.table.data = sportsmen
        self.table.paginator._page_size = len(sportsmen)
        self.table.paginator._current_page_data = sportsmen
        self.table._refresh_view()