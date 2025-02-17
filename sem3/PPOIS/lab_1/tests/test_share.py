import unittest
from unittest.mock import patch
from src.share import Share  


class TestShare(unittest.TestCase):

    @patch('builtins.input', side_effect=['3'])  
    @patch('random.randint', return_value=3) 
    def test_lottery_success(self, mock_random, mock_input):
        result = Share.lottery()
        self.assertTrue(result)  

    @patch('builtins.input', side_effect=['2']) 
    @patch('random.randint', return_value=3)  
    def test_lottery_failure(self, mock_random, mock_input):
        result = Share.lottery()
        self.assertFalse(result)  

    @patch('builtins.input', side_effect=['10'])  
    def test_lottery_invalid_input(self, mock_input):
        with self.assertRaises(ValueError) as context:
            Share.lottery()
        self.assertEqual(str(context.exception), "Число должно быть от 1 до 5.")

    @patch('builtins.input', side_effect=['0'])  
    def test_lottery_invalid_input_zero(self, mock_input):
        with self.assertRaises(ValueError) as context:
            Share.lottery()
        self.assertEqual(str(context.exception), "Число должно быть от 1 до 5.")

if __name__ == "__main__":
    unittest.main()