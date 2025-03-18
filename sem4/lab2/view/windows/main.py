from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QDial,
    QFileDialog,
    QLabel,
    QMainWindow,
    QSpinBox,
    QStatusBar,
    QToolBar,
    QSizePolicy,
    QWidget
)
from PySide6.QtGui import QAction
from utils import logger

from controller import SportsmanController
from view import Table
from view.windows import AddSportsmanWindow, FindSportsmanWindow


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("PPOIS2")

        self.controller = SportsmanController()

        self.record_toolbar = QToolBar("Main Toolbar")
        self.paginator = QToolBar("Paginator")
        
        self.table: Table = Table()
        
        self._configure_toolbars()
        self.setCentralWidget(self.table)

    def _configure_toolbars(self):
        self.addToolBar(Qt.ToolBarArea.LeftToolBarArea, self.record_toolbar)
        self.addToolBar(Qt.ToolBarArea.BottomToolBarArea, self.paginator)

        self._configure_record_toolbar()
        self._configure_paginator()

        self.setStatusBar(QStatusBar(self))

    def _configure_record_toolbar(self):
        load_file_button = QAction("Load", self)
        load_file_button.setStatusTip("Загрузить данные из файла")
        load_file_button.triggered.connect(self._load_xml_from_file)

        save_file_button = QAction("Save", self)
        save_file_button.setStatusTip("Сохранить данные в файл")
        save_file_button.triggered.connect(self._save_xml_to_file)

        file_control_menu = self.menuBar()
        file_menu = file_control_menu.addMenu("File")
        file_menu.addAction(load_file_button)
        file_menu.addAction(save_file_button)

        tree_view_button = QAction("Tree View", self)
        tree_view_button.setStatusTip("Отобразить в виде дерева")
        tree_view_button.triggered.connect(self.table._show_tree_view)
        
        tools_menu = self.menuBar()
        tools_menu = tools_menu.addMenu("Tools")
        tools_menu.addAction(tree_view_button)


        add_record_button = QAction("Add", self)
        add_record_button.setStatusTip("Добавить новую запись")
        add_record_button.triggered.connect(self._add_record)
        self.record_toolbar.addAction(add_record_button)

        self.record_toolbar.addSeparator()

        delete_record_button = QAction("Delete", self)
        delete_record_button.setStatusTip("Удалить записи")
        delete_record_button.triggered.connect(self._delete_record)
        self.record_toolbar.addAction(delete_record_button)

        self.record_toolbar.addSeparator()

        find_record_button = QAction("Find", self)
        find_record_button.setStatusTip("Найти запись")
        find_record_button.triggered.connect(self._find_record)
        self.record_toolbar.addAction(find_record_button) 

    
    def _configure_paginator(self):
        # кнопка перехода на первую страницу
        first_page_button = QAction("<<", self)
        first_page_button.setStatusTip("Перейти на первую страницу")
        first_page_button.triggered.connect(lambda: self._change_page("first"))
        self.paginator.addAction(first_page_button)       

        self.paginator.addSeparator()

        # кнопка перехода на предыдущую страницу
        prev_page_button = QAction("<", self)
        prev_page_button.setStatusTip("Перейти на предыдущую страницу")
        prev_page_button.triggered.connect(lambda: self._change_page("prev"))
        self.paginator.addAction(prev_page_button)

        self.paginator.addSeparator()
        
        # кнопка перехода на следующую страницу
        next_page_button = QAction(">", self)
        next_page_button.setStatusTip("Перейти на следующую страницу")
        next_page_button.triggered.connect(lambda: self._change_page("next"))
        self.paginator.addAction(next_page_button)

        self.paginator.addSeparator()

        # кнопка перехода на последнюю страницу
        last_page_button = QAction(">>", self)
        last_page_button.setStatusTip("Перейти на последнюю страницу")
        last_page_button.triggered.connect(lambda: self._change_page("last"))
        self.paginator.addAction(last_page_button)

        self.paginator.addSeparator()

        # конфигурация виджетов для отображения статистики пагинации
        def _configure_paginator_stats(self: MainWindow):
            # лейбл отображения колва страниц в виде "текущая / всего"
            self.pages_count_label = QLabel("")
            self.paginator.addWidget(self.pages_count_label)

            self.paginator.addSeparator()

            # лейбл отображения колва записей в виде "от - до / всего"
            self.records_count_label = QLabel("")
            self.paginator.addWidget(self.records_count_label)
            
            self.paginator.addSeparator()

            # штука чтобы сместить виджеты вправо
            spacer = QWidget()
            spacer.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Preferred)
            self.paginator.addWidget(spacer)

            # спинбокс изменения колва записей на странице
            self.page_size_edit = QSpinBox()
            self.page_size_edit.setRange(1, len(self.table.data))
            self.page_size_edit.setValue(self.table.paginator._page_size)
            self.page_size_edit.valueChanged.connect(
                lambda value: (
                    self.table.paginator._set_page_size(value),
                    self._refresh_paginator_stats(),
                    self._refresh_table()
                )
            )
            self.paginator.addWidget(self.page_size_edit)

            self.paginator.addSeparator()

            # рофляночка
            self.page_selector = QDial()
            self.page_selector.setRange(1, self.table.paginator._pages_count)
            self.page_selector.setSingleStep(1)
            self.page_selector.valueChanged.connect(
                lambda value: (
                    self.table.paginator._set_page(value),
                    self._refresh_table()
                )
            )
            self.paginator.addWidget(self.page_selector)

            self._refresh_paginator_stats()
        
        _configure_paginator_stats(self)
    
    def _refresh_table(self):
        """
        Method to refresh table data after, for example, adding or deleting records
        """
        self.table.data = self.controller.get_all_records()
        self.table.paginator._refresh_current_page_data()
        self.table._refresh_view()
        self._refresh_paginator_stats()

    def _refresh_paginator_stats(self):
        """
        Method to refresh paginator statistics
        """
        self.pages_count_label.setText(f"{self.table.paginator._current_page} / {self.table.paginator._pages_count} pages")

        self.records_count_label.setText(
            f"{(self.table.paginator._current_page - 1) * self.table.paginator._page_size + 1} - "
            f"{self.table.paginator._current_page * self.table.paginator._page_size} / "
            f"{len(self.table.data)} records"
        )
        
        self.page_size_edit.setRange(1, len(self.table.data))

        self.page_selector.setRange(1, self.table.paginator._pages_count)

    def _change_page(self, direction: str):
        """
        Method to change current page of table
        """
        if direction == "first":
            self.table.paginator._first_page()
        elif direction == "prev":
            self.table.paginator._prev_page()
        elif direction == "next":
            self.table.paginator._next_page()
        elif direction == "last":
            self.table.paginator._last_page()

        self._refresh_table()

    def _add_record(self):
        add_sportsman_window = AddSportsmanWindow()
        add_sportsman_window.setWindowTitle("Sportsman Adder")
        add_sportsman_window.exec()

        self._refresh_table()

    def _delete_record(self):
        sportsmen_to_delete = self.table._get_selected_rows()

        self.controller.delete_records(sportsmen_to_delete)
        
        self._refresh_table()

    def _find_record(self):
        # TODO убрать из окна таблицу, но перезаписывать self.data based on фильтрах поиска
        find_sportsman_dialog = FindSportsmanWindow()
        find_sportsman_dialog.setWindowTitle("Sportsman Finder")
        find_sportsman_dialog.exec()

    def _save_xml_to_file(self):
        filename, _ = QFileDialog.getSaveFileName(
            self,
            "Save XML File",
            "/home/Desktop/bsuir/RPIIS/sem4/lab2/",
            "XML Files (*.xml);;All Files (*)"
        )

        if not filename:
            logger.error("No file was selected")
            return
        
        if filename:
            if not filename.endswith(".xml"):
                filename += ".xml" 
            self.controller.export_to_xml_file(filename)

    def _load_xml_from_file(self):
        filename, _ = QFileDialog.getOpenFileName(
            self,
            "Open XML File",
            "/home/Desktop/bsuir/RPIIS/sem4/lab2/",
            "XML Files (*.xml);;All Files (*)"
        )

        if not filename:
            logger.error("No file was selected")
            return
    
        sportsmen = self.controller.import_from_xml_file(filename)
        if not sportsmen:
            logger.error("No data was loaded from XML file")
            return
        
        self.controller.overwrite_db(sportsmen)
        self._refresh_table()
        logger.success("Data was successfully loaded from XML file")
