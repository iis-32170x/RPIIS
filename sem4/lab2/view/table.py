from PySide6 import QtCore, QtWidgets
from PySide6.QtGui import QStandardItem, QStandardItemModel
from PySide6.QtWidgets import QTableView
from utils import logger
from anytree import Node, RenderTree

from controller.sportsman_controller import SportsmanController
from models import Sportsman
from view import Paginator


class Table(QTableView):
    def __init__(self):
        super().__init__()
        self.headers = list(Sportsman.model_fields.keys())
        self.controller = SportsmanController()
        self.data: list[Sportsman] = self.controller.get_all_records()

        self.model = QStandardItemModel()

        self.paginator = Paginator(self)
        self._configure_table()

    def _configure_table(self) -> None:
        self.model.setHorizontalHeaderLabels(self.headers)
        self.setModel(self.model)

        self.setSelectionBehavior(QtWidgets.QAbstractItemView.SelectRows)
        self.setSelectionMode(QtWidgets.QAbstractItemView.MultiSelection)

        self.paginator._refresh_current_page_data()
        self._refresh_view()

    def _refresh_view(self):
        """
        Method to refresh displayed data based on current page data, selected in paginator
        """
        self.model.removeRows(0, self.model.rowCount())
        current_page_records: list[Sportsman] = self.paginator._current_page_data
        if not current_page_records:
            logger.error("No sportsmen to view (current page data is empty)")
            return
        for sportsman in current_page_records:
            table_row = []
            for key, value in sportsman.model_dump().items():
                item = QStandardItem(str(value))
                table_row.append(item)
            self.model.appendRow(table_row)
        self.model.layoutChanged.emit()

    def _get_selected_rows(self) -> list[dict[str, str]]:
        """
        Method to get selected rows from table
        """
        selected_indexes = self.selectionModel().selectedRows()
        selected_data = []
        for index in selected_indexes:
            row_data = {}
            for col in range(self.model.columnCount()):
                column_name = self.model.headerData(col, QtCore.Qt.Horizontal)
                row_data[column_name] = self.model.item(index.row(), col).text()
            selected_data.append(row_data)
        logger.debug(f"Selected data: {selected_data}")
        return selected_data
    
    def _show_tree_view(self):
        sportsmen = self.controller.get_all_records()
        trees = []
        for sportsman in sportsmen:
            # Корневой узел – имя записи
            root = Node(sportsman.name)
            Node(f"Статус: {sportsman.status}", parent=root)
            Node(f"Позиция: {sportsman.position}", parent=root)
            Node(f"Количество титулов: {sportsman.title_count}", parent=root)
            Node(f"Вид спорта: {sportsman.sport_type}", parent=root)
            Node(f"Ранг: {sportsman.rank}", parent=root)
            trees.append(root)
        
        for tree in trees:
            for pre, _, node in RenderTree(tree):
                print(f"{pre}{node.name}")
                

        
