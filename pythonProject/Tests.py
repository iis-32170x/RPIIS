import unittest
from Attraction import Attraction
from Guide import Guide
from Photo import Photo
from Route import Route
from Map import Map


class TestAttraction(unittest.TestCase):
    def setUp(self):
        self.attraction = Attraction("Эйфелева башня", "Знаменитая башня в Париже")

    def test_initial_state(self):
        self.assertEqual(self.attraction.name, "Эйфелева башня")
        self.assertFalse(self.attraction.visit)
        self.assertEqual(self.attraction.reviews, [])

    def test_add_review_without_visit(self):
        with self.assertRaises(ValueError):
            self.attraction.add_review("Отличное место!")

    def test_add_photo_without_visit(self):
        with self.assertRaises(ValueError):
            self.attraction.add_photo(Photo("eiffel.jpg"))

    def test_change_visiting(self):
        self.attraction.change_visiting()
        self.assertTrue(self.attraction.visit)

    def test_add_review_with_visit(self):
        self.attraction.change_visiting()
        self.attraction.add_review("Красивый вид!")
        self.assertEqual(len(self.attraction.reviews), 1)


class TestGuide(unittest.TestCase):
    def setUp(self):
        self.guide = Guide()
        self.map = Map()
        self.attraction = Attraction("Колизей", "Древнеримский амфитеатр")

    def test_add_attraction(self):
        self.guide.add_attraction(self.attraction, self.map)
        self.assertIn(self.attraction, self.guide.attractions)
        self.assertIn(self.attraction, self.map.attractions)

    def test_find_attraction(self):
        self.guide.add_attraction(self.attraction, self.map)
        found = self.guide.find_attraction("Колизей")
        self.assertEqual(found, self.attraction)


class TestRoute(unittest.TestCase):
    def setUp(self):
        self.route = Route("Исторический маршрут")
        self.attraction = Attraction("Лувр", "Музей искусств")

    def test_add_attraction(self):
        self.route.add_attraction(self.attraction)
        self.assertIn(self.attraction, self.route.attractions)

    def test_show_route(self):
        self.route.add_attraction(self.attraction)
        self.assertEqual(self.route.show_route(), "Маршрут Исторический маршрут: Лувр")


class TestMap(unittest.TestCase):
    def setUp(self):
        self.map = Map()
        self.attraction = Attraction("Великая Китайская стена", "Огромная стена в Китае")

    def test_add_attraction(self):
        self.map.add_attraction(self.attraction)
        self.assertIn(self.attraction, self.map.attractions)


if __name__ == "__main__":
    unittest.main()
