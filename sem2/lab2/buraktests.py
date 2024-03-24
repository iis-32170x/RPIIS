import unittest
import buraksets

class TestBuraksSetMethods(unittest.TestCase):
    def test_format_1(self):
        self.assertTrue(buraksets.hasCorrectFormat1("{c}"))
        self.assertTrue(buraksets.hasCorrectFormat1("{A,b}"))
        self.assertTrue(buraksets.hasCorrectFormat1("{a,{b,c,a},b}"))
        self.assertFalse(buraksets.hasCorrectFormat1("A,b"))
        self.assertFalse(buraksets.hasCorrectFormat1("{a,{{e},b}"))
        self.assertFalse(buraksets.hasCorrectFormat1("{a,{b,{c,a}},b}"))
        self.assertTrue(buraksets.hasCorrectFormat1("{a,{},b}"))
        self.assertFalse(buraksets.hasCorrectFormat1("{a,b,cd}"))
        self.assertFalse(buraksets.hasCorrectFormat1("{a,5,c}"))
        
    def test_format_2(self):
        self.assertTrue(buraksets.hasCorrectFormat2(['A','b']))
        self.assertTrue(buraksets.hasCorrectFormat2(['{C}']))
        self.assertTrue(buraksets.hasCorrectFormat2(['a','b','{a,b,c}']))
        self.assertFalse(buraksets.hasCorrectFormat2(['a','b','{','b','c','}']))
        self.assertFalse(buraksets.hasCorrectFormat2(['','a','b']))
        self.assertFalse(buraksets.hasCorrectFormat2(['a','b','}']))
        

    def test_settostr(self):
        self.assertEqual(buraksets.Mnozh.setToStr(['a','b','c']),"{a,b,c}")
        self.assertEqual(buraksets.Mnozh.setToStr(['a','b','c','{d,e}']),"{a,b,c,{d,e}}")

    def test_strtoset(self):
        self.assertEqual(buraksets.strToSet("{A,b}"),['A','b'])
        self.assertEqual(buraksets.strToSet("{a,{b,c,a},b}"),['a','b','{a,b,c}'])
        self.assertEqual(buraksets.strToSet("{ab}"),"Error")
        self.assertEqual(buraksets.strToSet("{a,<5,c>}"),"Error")
        self.assertEqual(buraksets.strToSet("{a,5,c}}"),"Error")
        self.assertEqual(buraksets.strToSet("{a,{{e},b}"),"Error")
        self.assertEqual(buraksets.strToSet("{a,{b,{c,a}},b}"),"Error")
        self.assertEqual(buraksets.strToSet("{a,b,{,p,o}}"),"Error")
        
    def test_iselement(self):
        self.assertTrue(buraksets.Mnozh.isElement(['b'],['a','{b}']))
        self.assertFalse(buraksets.Mnozh.isElement(['b'],['a','b']))
        self.assertFalse(buraksets.Mnozh.isElement(['b'],['a','{b,c}']))
        self.assertEqual(buraksets.Mnozh.isElement(['{','a','}'],['a','b']),'Error')
        self.assertEqual(buraksets.Mnozh.isElement(['a','b'],['{','a','}']),'Error')
        
    def test_issubset(self):
        self.assertFalse(buraksets.Mnozh.isSubset(['b'],['a','{b}']))
        self.assertTrue(buraksets.Mnozh.isSubset(['b'],['a','b']))
        self.assertTrue(buraksets.Mnozh.isSubset(['c','b'],['c','a','b']))
        self.assertFalse(buraksets.Mnozh.isSubset(['c','b'],['{c,a}','b']))
        self.assertFalse(buraksets.Mnozh.isSubset(['c','b'],['{c,b}','a']))
        self.assertEqual(buraksets.Mnozh.isSubset(['{','a','}'],['{a}','b']),'Error')
        self.assertEqual(buraksets.Mnozh.isSubset(['{a}','b'],['{','a','}']),'Error')
        

if __name__ == '__main__':
    unittest.main()