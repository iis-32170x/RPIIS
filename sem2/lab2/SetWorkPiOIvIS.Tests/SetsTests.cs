using NUnit.Framework;
using System;
using System.Buffers;
using System.Data.Common;
using System.IO;
using System.Xml.Linq;

namespace SetWorkPiOIvIS.Tests
{
    public class SetsTests
    {
        SetWorkPiOIvIS.Sets _sets = new SetWorkPiOIvIS.Sets();

        [Test]
        public void UpdateSet_CreatesSetFromFile1AndUpdateFromFile2_1()
        {
            using (StringWriter consoleOutput = new StringWriter())
            {
                Console.SetOut(consoleOutput);

                string fileName1 = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test1.txt";
                _sets.CreateSet(fileName1);
                _sets.OutPutSet();

                string fileName2 = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test2.txt";
                _sets.UpdateSet(fileName2);
                _sets.OutPutSet();

                string expectedOutput = "Множество 0: 1 2 4 1 \r\nМножество 1: 1 2 5 6 1 \r\n" +
                    "Множество 0: 1 4 1 \r\nМножество 1: 1 2 5 6 1 4 \r\n";
                Assert.AreEqual(expectedOutput, consoleOutput.ToString());
            }
        }
        [Test]
        public void UpdateSet_CreatesSetFromFile1AndUpdateFromFile2_2()
        {
            using (StringWriter consoleOutput = new StringWriter())
            {
                Console.SetOut(consoleOutput);

                string fileName1 = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test2.txt";
                _sets.CreateSet(fileName1);
                _sets.OutPutSet();

                string fileName2 = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test3.txt";
                _sets.UpdateSet(fileName2);
                _sets.OutPutSet();

                string expectedOutput = "Множество 0: 1 4 1 \r\nМножество 1: 1 2 5 6 1 4 \r\n" +
                    "Множество 0: 1 4 8 3 7 \r\nМножество 1: 1 2 5 6 1 9 \r\n";
                Assert.AreEqual(expectedOutput, consoleOutput.ToString());
            }
        }

        [Test]
        public void OutPut_PrintsArrayToConsole_1()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test1.txt";
            _sets.CreateSet(fileName);
            using (StringWriter consoleOutput = new StringWriter())
            {
                Console.SetOut(consoleOutput);

                _sets.OutPutSet();

                string expectedOutput = "Множество 0: 1 2 4 1 \r\nМножество 1: 1 2 5 6 1 \r\n";
                Assert.AreEqual(expectedOutput, consoleOutput.ToString());
            }
        }
        [Test]
        public void OutPut_PrintsArrayToConsole_2()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test2.txt";
            _sets.CreateSet(fileName);
            using (StringWriter consoleOutput = new StringWriter())
            {
                Console.SetOut(consoleOutput);

                _sets.OutPutSet();

                string expectedOutput = "Множество 0: 1 4 1 \r\nМножество 1: 1 2 5 6 1 4 \r\n";
                Assert.AreEqual(expectedOutput, consoleOutput.ToString());
            }
        }
        [Test]
        public void OutPut_PrintsArrayToConsole_3()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test3.txt";
            _sets.CreateSet(fileName);
            using (StringWriter consoleOutput = new StringWriter())
            {
                Console.SetOut(consoleOutput);

                _sets.OutPutSet();

                string expectedOutput = "Множество 0: 1 4 8 3 7 \r\nМножество 1: 1 2 5 6 1 9 \r\n";
                Assert.AreEqual(expectedOutput, consoleOutput.ToString());
            }
        }

        [Test]
        public void DifferenceSet_FindDifferenceSetFromFile1_1()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test1.txt";
            _sets.CreateSet(fileName);
            int[] difference = _sets.DifferenceSet(1);
            int[] expectedDifference = {4};
            Assert.AreEqual(expectedDifference, difference);
        }
        [Test]
        public void DifferenceSet_FindDifferenceSetFromFile1_2()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test1.txt";
            _sets.CreateSet(fileName);
            int[] difference = _sets.DifferenceSet(2);
            int[] expectedDifference = { 5,6 };
            Assert.AreEqual(expectedDifference, difference);
        }

        [Test]
        public void DifferenceSet_FindDifferenceSetFromFile2_1()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test2.txt";
            _sets.CreateSet(fileName);
            int[] difference = _sets.DifferenceSet(1);
            int[] expectedDifference = { };
            Assert.AreEqual(expectedDifference, difference);
        }
        [Test]
        public void DifferenceSet_FindDifferenceSetFromFile2_2()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test2.txt";
            _sets.CreateSet(fileName);
            int[] difference = _sets.DifferenceSet(2);
            int[] expectedDifference = { 2, 5, 6 };
            Assert.AreEqual(expectedDifference, difference);
        }

        [Test]
        public void DifferenceSet_FindDifferenceSetFromFile3_1()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test3.txt";
            _sets.CreateSet(fileName);
            int[] difference = _sets.DifferenceSet(1);
            int[] expectedDifference = { 4,8,3,7};
            Assert.AreEqual(expectedDifference, difference);
        }
        [Test]
        public void DifferenceSet_FindDifferenceSetFromFile3_2()
        {
            string fileName = "C:\\Users\\MrZet\\source\\repos\\SetWorkPiOIvIS\\bin\\Debug\\net8.0\\Test3.txt";
            _sets.CreateSet(fileName);
            int[] difference = _sets.DifferenceSet(2);
            int[] expectedDifference = { 2,5,6,1,9 };
            Assert.AreEqual(expectedDifference, difference);
        }
    }
}