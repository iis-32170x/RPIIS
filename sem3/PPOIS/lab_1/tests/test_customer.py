import unittest
from unittest.mock import patch
import io
from src.customer import Customer
from src.product import Product

class TestCustomer(unittest.TestCase):

    def setUp(self):
        self.customer = Customer("Bob", 5000)
        self.product1 = Product("Iphone 15 pro", 4000, 1)
        self.product2 = Product("Samsung Galaxy S22", 3500, 2)

    def test_get_name(self):
        self.assertEqual(self.customer.get_name(), "Bob")

    def test_add_product(self):
        self.customer.add_product(self.product1)
        self.assertIn(self.product1, self.customer._Customer__products)

    def test_remove_product(self):
        self.customer.add_product(self.product1)
        self.customer.remove_product(self.product1)
        self.assertNotIn(self.product1, self.customer._Customer__products)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_print_info_with_products(self, mock_stdout):
        self.customer.add_product(self.product1)
        self.customer.print_info()

        # Получаем вывод, который был напечатан
        printed_output = mock_stdout.getvalue()
        # Ожидаемое значение вывода
        expected_output = "Имя покупателя: Bob\nБаланс: 5000\nТовары: Iphone 15 pro\n"
        # Проверяем, что вывод соответствует ожидаемому
        self.assertEqual(printed_output, expected_output)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_print_info_without_products(self, mock_stdout):
        self.customer.print_info()

        printed_output = mock_stdout.getvalue()
        expected_output = "Имя покупателя: Bob\nБаланс: 5000\nТовары: Нет покупок\n"
        self.assertEqual(printed_output, expected_output)

    def test_set_money(self):
        self.customer.set_money(3000)
        self.assertEqual(self.customer.get_money(), 3000)

    def test_get_money(self):
        self.assertEqual(self.customer.get_money(), 5000)

if __name__ == "__main__":
    unittest.main()