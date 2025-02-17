import unittest
from unittest.mock import patch
from io import StringIO
from src.consultant import Consultant  # Убедитесь, что путь к классу Consultant правильный

class TestConsultant(unittest.TestCase):

    def setUp(self):
        self.consultant = Consultant()

    def test_show_questions(self):
        with patch('sys.stdout', new_callable=StringIO) as mock_stdout:
            self.consultant.show_questions()
            printed_output = mock_stdout.getvalue()
            expected_output = (
                "Часто задаваемые вопросы:\n\n"
                "1. Можно ли вернуть товар?\n"
                "2. Что будет, если выиграть в акции?\n"
                "3. Трудно ли писать вопросы для воображаемого сайта?\n"
                "4. Не вернули деньги за возврат. Что делать?\n"
                "5. Время работы\n"
            )
            self.assertEqual(printed_output, expected_output)

    def test_get_answer_valid(self):
        answer = self.consultant.get_answer(1)
        self.assertEqual(answer, "Конечно, для возврата товара нужно воспользоваться соответствующей опцией")

    def test_get_answer_invalid(self):
        answer = self.consultant.get_answer(34)
        self.assertIsNone(answer)

    @patch('builtins.input', side_effect=['1']) 
    @patch('sys.stdout', new_callable=StringIO)
    def test_choice_question_valid(self, mock_stdout, mock_input):
        self.consultant.choice_question()
        printed_output = mock_stdout.getvalue()
        expected_output = "Конечно, для возврата товара нужно воспользоваться соответствующей опцией\n"
        self.assertEqual(printed_output, expected_output)

    @patch('builtins.input', side_effect=['sfdf', '1'])
    @patch('sys.stdout', new_callable=StringIO)
    def test_choice_question_invalid_then_valid(self, mock_stdout, mock_input):
        self.consultant.choice_question()
        printed_output = mock_stdout.getvalue()
        self.assertIn("Пожалуйста, введите правильное число", printed_output)
        self.assertIn("Конечно, для возврата товара нужно воспользоваться соответствующей опцией", printed_output)

if __name__ == "__main__":
    unittest.main()