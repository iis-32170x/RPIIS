using NUnit.Framework;
using System;
using System.Buffers;
using System.Data.Common;
using System.IO;
using System.Xml.Linq;

namespace TwoDimensionalArray.Tests
{
    public class TwoArrayTests
    {
        int[][] massive,secondMassive;
        private TwoArray _twoArray = new TwoArray();

        [Test]
        public void Sort_SortsArrayInAscendingOrder_1()
        {
            massive = new int[5][]
            {
                new int[] { 5, 4, 3, 2, 1 },
                new int[] { 10, 9, 8, 7, 6 },
                new int[] { 15, 14, 13, 12, 11 },
                new int[] { 20, 19, 18, 17, 16 },
                new int[] { 25, 24, 23, 22, 21 }
            };

            _twoArray.Sort(ref massive);

            int[][] expected = new int[5][]
            {
                new int[] { 1, 2, 3, 4, 5 },
                new int[] { 6, 7, 8, 9, 10 },
                new int[] { 11, 12, 13, 14, 15 },
                new int[] { 16, 17, 18, 19, 20 },
                new int[] { 21, 22, 23, 24, 25 }
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void Sort_SortsArrayInAscendingOrder_2()
        {
            massive = new int[3][]
            {
                new int[] { 12, 5, 4},
                new int[] { 3, 2, 1},
                new int[] { 77, 44, 88},
            };

            _twoArray.Sort(ref massive);

            int[][] expected = new int[3][]
            {
                new int[] { 1, 2, 3},
                new int[] { 4, 5, 12},
                new int[] { 44, 77, 88},
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void OutPut_PrintsArrayToConsole()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            using (StringWriter sw = new StringWriter())
            {
                Console.SetOut(sw);

                _twoArray.OutPut(ref massive);

                string expectedOutput = "|   1  |   2  |   3  |\r\n|   4  |   5  |   6  |\r\n|   7  |   8  |   9  |\r\n";
                Assert.AreEqual(expectedOutput, sw.ToString());
            }
        }

        [Test]
        public void InsertElement_AddsElementToExistingArray_1()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            int element = 10;
            _twoArray.InsertElement(ref massive, element);

            int[][] expected = new int[3][]
            {
                new int[] { 1, 2, 3, 4},
                new int[] { 5, 6, 7 },
                new int[] { 8, 9, 10}
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void InsertElement_AddsElementToExistingArray_2()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 , 4, 5},
                new int[] { 6, 7, 8, 9, 10},
                new int[] { 11, 12, 13, 14, 15}
            };

            int element = 16;
            _twoArray.InsertElement(ref massive, element);

            int[][] expected = new int[4][]
            {
                new int[] { 1, 2, 3 , 4, 5},
                new int[] { 6, 7, 8, 9, 10},
                new int[] { 11, 12, 13, 14, 15},
                new int[] { 16 }
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void FindElement_ReturnsElementAtSpecifiedRowAndColumn_1()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            int row = 1;
            int column = 2;
            int expected = 6;

            int result = _twoArray.FindElement(ref massive, row, column);

            Assert.AreEqual(expected, result);
        }

        [Test]
        public void FindElement_ReturnsElementAtSpecifiedRowAndColumn_2()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            int row = 3;
            int column = 2;

            using (StringWriter sw = new StringWriter())
            {
                Console.SetOut(sw);

                _twoArray.FindElement(ref massive, row, column);

                string expectedOutput = "Индекс вышел за границы массива.\r\n";
                Assert.AreEqual(sw.ToString(), expectedOutput);
            }
        }

        [Test]
        public void FindElement_OutputsTheRowAndColumnOfTheSpecifiedElement_1()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            int element = 2;
            using (StringWriter sw = new StringWriter())
            {
                Console.SetOut(sw);

                _twoArray.FindElement(ref massive, element);

                string expectedOutput = "Строка: 0. Столбец: 1\r\n";
                Assert.AreEqual(expectedOutput, sw.ToString());
            }
        }

        [Test]
        public void FindElement_OutputsTheRowAndColumnOfTheSpecifiedElement_2()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            int element = 10;
            using (StringWriter sw = new StringWriter())
            {
                Console.SetOut(sw);

                _twoArray.FindElement(ref massive, element);

                string expectedOutput = "Элемент не найден\r\n";
                Assert.AreEqual(expectedOutput, sw.ToString());
            }
        }

        [Test]
        public void Merge_MergesTwoArraysIntoOne_1()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };
            secondMassive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            _twoArray.Merge(ref massive, ref secondMassive);

            int[][] expected = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void Merge_MergesTwoArraysIntoOne_2()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };
            secondMassive = new int[2][]
            {
                new int[] { 10, 11 },
                new int[] { 12, 13}
            };

            _twoArray.Merge(ref massive, ref secondMassive);

            int[][] expected = new int[3][]
            {
                new int[] { 1, 2, 3, 4, 5 },
                new int[] { 6, 7, 8, 9, 10 },
                new int[] { 11, 12, 13}
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void Merge_MergesTwoArraysIntoOne_3()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };
            secondMassive = new int[2][]
            {
                new int[] { 1, 2 , 4, 6},
                new int[] { 10, 3, 4}
            };

            _twoArray.Merge(ref massive, ref secondMassive);

            int[][] expected = new int[3][]
            {
                new int[] { 1, 2, 3, 4},
                new int[] { 5, 6, 7},
                new int[] { 8, 9, 10}
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void Intersect_IntersectTwoArraysIntoOne_1()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };
            secondMassive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            _twoArray.Intersect(ref massive, ref secondMassive);

            int[][] expected = new int[2][]
            {
                new int[] { 1, 2, 3, 4, 5 },
                new int[] { 6, 7, 8, 9},
            };

            Assert.AreEqual(expected, massive);
        }

        [Test]
        public void Intersect_IntersectTwoArraysIntoOne_2()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };
            secondMassive = new int[2][]
            {
                new int[] { 10, 11 },
                new int[] { 12, 13}
            };

            int[][] expected = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };

            using (StringWriter sw = new StringWriter())
            {
                Console.SetOut(sw);

                _twoArray.Intersect(ref massive,ref secondMassive);

                string expectedOutput = "Пересечения нет\r\n";
                Assert.AreEqual(sw.ToString(), expectedOutput);
                Assert.AreEqual(expected, massive);
            }
        }

        [Test]
        public void Intersect_IntersectTwoArraysIntoOne_3()
        {
            massive = new int[3][]
            {
                new int[] { 1, 2, 3 },
                new int[] { 4, 5, 6 },
                new int[] { 7, 8, 9 }
            };
            secondMassive = new int[2][]
            {
                new int[] { 1, 2 , 4, 6},
                new int[] { 10, 3, 4}
            };

            _twoArray.Intersect(ref massive, ref secondMassive);

            int[][] expected = new int[1][]
            {
                new int[] { 1, 2, 3, 4, 6}
            };

            Assert.AreEqual(expected, massive);
        }
    }
}