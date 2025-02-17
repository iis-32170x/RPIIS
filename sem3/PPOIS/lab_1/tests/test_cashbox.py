import unittest
from src.cashbox import Cashbox
from src.product import Product
from src.customer import Customer

class TestCashbox(unittest.TestCase):

    def setUp(self):
        self.customer = Customer("Bob", 150)  
        self.product = Product("prod1", 100, 1)  

    def test_buy_product_success(self):
        Cashbox.buy_product(self.customer, self.product)

        self.assertEqual(self.customer.get_money(), 50) 
        self.assertIn(self.product, self.customer._Customer__products)  

    def test_buy_product_insufficient_funds(self):

        expensive_product = Product("prod2", 200, 1) 
        
        Cashbox.buy_product(self.customer, expensive_product)

        self.assertEqual(self.customer.get_money(), 150)
        self.assertNotIn(expensive_product, self.customer._Customer__products)

    def test_return_product(self):
        Cashbox.buy_product(self.customer, self.product) 
        initial_balance = self.customer.get_money()

        Cashbox.return_product(self.customer, self.product)

        self.assertEqual(self.customer.get_money(), initial_balance + 100) 
        self.assertNotIn(self.product, self.customer._Customer__products)

if __name__ == "__main__":
    unittest.main()