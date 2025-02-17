import unittest
from src.product import Product
from src.guarantee import Guarantee

class TestProduct(unittest.TestCase):

    def setUp(self):
        self.product = Product("Iphone 15 pro", 4000, 1)

    def test_get_name(self):
        self.assertEqual(self.product.get_name(), "Iphone 15 pro")

    def test_get_price(self):
        self.assertEqual(self.product.get_price(), 4000)

    def test_get_guarantee(self):
        self.assertEqual(self.product.get_guarantee(), 1)

if __name__ == "__main__":
    unittest.main()