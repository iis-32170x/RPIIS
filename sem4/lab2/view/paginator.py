import math
from typing import TYPE_CHECKING

from utils import logger

from models import Sportsman

if TYPE_CHECKING:
    from view import Table

class Paginator():
    """
    Class to manage pagination of data in table
    
    Changing current page data based on all data in table with page size
    """
    def __init__(self, table: 'Table'):
        self._table: Table = table
        self._current_page: int = 1
        self._current_page_data: list[Sportsman]
        self._page_size: int = 10
        self._pages_count = math.ceil(len(self._table.data) / self._page_size)

    def _set_page_size(self, page_size: int):
        self._page_size = page_size
        self._refresh_current_page_data()

    def _refresh_current_page_data(self):
        """
        Method that specifying current page data based on page size

        How is it working: method is slicing all data that will show on current page
        and setting it to current_page_data attribute
        """
        left_border = (self._current_page - 1) * self._page_size
        right_border = self._current_page * self._page_size
        self._current_page_data = self._table.data[left_border:right_border]
        self._pages_count = math.ceil(len(self._table.data) / self._page_size)
        # logger.debug(f"\nCurrent page: {self._current_page} of total: {self._pages_count}\n"
        #              f"Count of records: {len(self._table.data)}\n"
        #              f"Left border to slice: {left_border}\n"
        #              f"Right border to slice: {right_border}")

    def _set_page(self, page: int):
        if page < 1 or page > self._pages_count:
            logger.error(f"Invalid page number: {page}")
            return
        self._current_page = page
        self._refresh_current_page_data()

    def _next_page(self):
        if self._current_page == self._pages_count:
            logger.debug("cur == pages, return")
            return
        
        self._current_page += 1
        self._refresh_current_page_data()

    def _prev_page(self):
        if self._current_page == 1:
            logger.debug("cur == 1, return")
            return

        self._current_page -= 1
        self._refresh_current_page_data()
    
    def _first_page(self):
        self._current_page = 1 
        self._refresh_current_page_data()

    def _last_page(self):
        self._current_page = self._pages_count
        self._refresh_current_page_data()
