import unittest
from unittest.mock import patch
from io import StringIO
from src.electroshop import Electroshop
from src.customer import Customer
from src.product import Product

class TestElectroshop(unittest.TestCase):

    def setUp(self):
        self.electroshop = Electroshop()
        self.electroshop.add_customer("Bob", 150)  
        self.electroshop.add_customer("Jessika", 200)  

    @patch('sys.stdout', new_callable=StringIO)
    def test_show_customers_non_empty(self, mock_stdout):
        self.electroshop.show_customers()
        printed_output = mock_stdout.getvalue()
        self.assertIn("1. ", printed_output)
        self.assertIn("Bob", printed_output)
        self.assertIn("2. ", printed_output)
        self.assertIn("Jessika", printed_output)

    @patch('sys.stdout', new_callable=StringIO)
    def test_show_customers_empty(self, mock_stdout):
        empty_shop = Electroshop()
        empty_shop.show_customers()
        printed_output = mock_stdout.getvalue()
        self.assertEqual(printed_output.strip(), "Покупателей нет")

    @patch('sys.stdout', new_callable=StringIO)
    def test_add_customer_existing(self, mock_stdout):
        self.electroshop.add_customer("Bob", 150)
        printed_output = mock_stdout.getvalue()
        self.assertIn("Покупатель Bob уже существует", printed_output)

    @patch('sys.stdout', new_callable=StringIO)
    def test_add_customer_new(self, mock_stdout):
        self.electroshop.add_customer("Sergio", 300)
        printed_output = mock_stdout.getvalue()
        self.assertIn("Покупатель Sergio добавлен", printed_output)
        self.assertEqual(len(self.electroshop._Electroshop__customers), 3)  # Проверка увеличения количества покупателей

    @patch('sys.stdout', new_callable=StringIO)
    def test_remove_customer_existing(self, mock_stdout):
        self.electroshop.remove_customer("Bob")
        printed_output = mock_stdout.getvalue()
        self.assertIn("Покупатель Bob удалён", printed_output)
        self.assertEqual(len(self.electroshop._Electroshop__customers), 1)  # Проверка уменьшения количества покупателей

    @patch('sys.stdout', new_callable=StringIO)
    def test_remove_customer_non_existing(self, mock_stdout):
        self.electroshop.remove_customer("Alexey")
        printed_output = mock_stdout.getvalue()
        self.assertIn("Покупателя Alexey не найдено", printed_output)

    @patch('builtins.input', side_effect=['1'])  # Подменяем ввод для выбора покупателя
    def test_get_customer_valid(self, mock_input):
        customer = self.electroshop.get_customer()
        self.assertEqual(customer.get_name(), "Bob")

    @patch('builtins.input', side_effect=['sdff', '1'])  # Подменяем ввод на некорректное значение и затем корректное
    def test_get_customer_invalid_input(self, mock_input):
        customer = self.electroshop.get_customer()
        self.assertEqual(customer.get_name(), "Bob")  # Проверяем, что вернулся корректный покупатель

if __name__ == "__main__":
    unittest.main()