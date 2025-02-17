import unittest
from unittest.mock import patch
from io import StringIO
from src.catalog import Catalog
from src.product import Product

class TestCatalog(unittest.TestCase):

    def setUp(self):
        self.catalog = Catalog()
        self.product1 = Product("Prod1", 100, 1)
        self.product2 = Product("Prod2", 200, 2)
        self.catalog.add_product(self.product1.get_name(), self.product1.get_price(), self.product1.get_guarantee())
        self.catalog.add_product(self.product2.get_name(), self.product2.get_price(), self.product2.get_guarantee())

    @patch('sys.stdout', new_callable=StringIO)
    def test_add_product_existing(self, mock_stdout):
        self.catalog.add_product("Prod1", 150, 1.5)
        printed_output = mock_stdout.getvalue()
        self.assertIn("Товар с названием Prod1 уже существует", printed_output)

    @patch('sys.stdout', new_callable=StringIO)
    def test_add_product_new(self, mock_stdout):
        self.catalog.add_product("Prod3", 300, 3)
        printed_output = mock_stdout.getvalue()
        self.assertIn("Продукт Prod3 добавлен в каталог", printed_output)
        self.assertEqual(len(self.catalog._Catalog__products), 3)

    @patch('sys.stdout', new_callable=StringIO)
    def test_remove_product_existing(self, mock_stdout):
        self.catalog.remove_product("Prod1")
        printed_output = mock_stdout.getvalue()
        self.assertIn("Продукт Prod1 удалён из каталога", printed_output)
        self.assertEqual(len(self.catalog._Catalog__products), 1)  

    @patch('sys.stdout', new_callable=StringIO)
    def test_remove_product_non_existing(self, mock_stdout):
        self.catalog.remove_product("Prod3")
        printed_output = mock_stdout.getvalue()
        self.assertIn("Продукта с названием Prod3 не найдено", printed_output)

    @patch('sys.stdout', new_callable=StringIO)
    def test_display_catalog_non_empty(self, mock_stdout):
        self.catalog.display_catalog()
        printed_output = mock_stdout.getvalue()
        self.assertIn("Каталог", printed_output)
        self.assertIn("Prod1", printed_output)
        self.assertIn("Prod2", printed_output)

    @patch('sys.stdout', new_callable=StringIO)
    def test_display_catalog_empty(self, mock_stdout):
        empty_catalog = Catalog()
        empty_catalog.display_catalog()
        printed_output = mock_stdout.getvalue()
        self.assertIn("Покупателей нет", printed_output)

    def test_find_product_existing(self):
        found_product = self.catalog.find_product("Prod1")
        self.assertEqual(found_product.get_name(), "Prod1")

    def test_find_product_non_existing(self):
        found_product = self.catalog.find_product("Prod3")
        self.assertIsNone(found_product)

if __name__ == "__main__":
    unittest.main()