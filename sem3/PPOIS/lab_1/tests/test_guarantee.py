import unittest
from src.guarantee import Guarantee

class TestGuarantee(unittest.TestCase):

    def setUp(self):
        self.guarantee = Guarantee(1) 

    def test_get_term(self):
        self.assertEqual(self.guarantee.get_term(), 1)

if __name__ == "__main__":
    unittest.main()