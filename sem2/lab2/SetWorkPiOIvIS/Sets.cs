using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection.Metadata.Ecma335;

namespace SetWorkPiOIvIS
{
    /// <summary>
    /// Класс, для работы с множеством и рахождения разности этих множеств.
    /// </summary>
    public class Sets: ISets
    {
        /// <summary>
        /// Ступенчатый массив, который будет хранить наши множества.
        /// </summary>
        private int[][] massive= [];
        /// <summary>
        /// Метод для чтения из файла множеств и записи их в массив.
        /// </summary>
        /// <param name="fileName">Строка, которая хранит полный путь к файлу.</param>
        public void CreateSet(string fileName)
        {
            StreamReader file = new(fileName);
            int i = -1, j = 0;
            int countMassives = 2;
            massive = new int[countMassives][];
            while(!file.EndOfStream)
            {
                string text = file.ReadLine();
                if (text.Length == 1)
                {
                    i++;
                    massive[i] = new int[Int32.Parse(text)];
                }
                else if (text.Length > 1)
                {
                    foreach (char buff in text)
                    {
                        if(buff !=' ')
                        {
                            massive[i][j] = (int)buff-'0';
                            j++;
                        }
                    }
                    j = 0;
                }
            }
            file.Close();
        }
        /// <summary>
        /// Метод для обновления данных о множествах и перезаписи массива.
        /// </summary>
        /// <param name="fileName">Строка, которая хранит полный путь к файлу.</param>
        public void UpdateSet(string fileName)
        {
            CreateSet(fileName);
        }
        /// <summary>
        /// Метод для вывода множеств в консоль.
        /// </summary>
        public void OutPutSet()
        {
            for(int i = 0; i < massive.Length; i++)
            {
                Console.Write("Множество {0}: ", i);
                for(int j = 0; j < massive[i].Length; j++)
                {
                    Console.Write("{0} ", massive[i][j]);
                }
                Console.WriteLine();
            }
        }
        /// <summary>
        /// Метод для нахождения разности двух множеств.
        /// </summary>
        /// <param name="variant">Выбор между разностью А\B или B\A.</param>
        /// <returns>Множество полученное из разности.</returns>
        public int[] DifferenceSet(int variant)
        {
            int[] differenceMassive;
            int count=0, index = 0;
            int[] temp;
            switch (variant)
            {
                case 1:
                    {
                        temp = massive[0];
                        for(int i = 0; i < massive[1].Length; i++)
                        {
                            for(int j = 0; j < massive[0].Length; j++)
                            {
                                if (massive[0][j] == massive[1][i])
                                {
                                    temp[j] = int.MaxValue;
                                    count++;
                                    break;
                                }
                            }
                        }
                        differenceMassive = new int[temp.Length - count];
                        for(int i = 0; i < differenceMassive.Length; i++)
                        {
                            while (temp[index]==int.MaxValue)
                            {
                                index++;
                            }
                            differenceMassive[i] = temp[index];
                            index++;
                        }
                        return differenceMassive;
                    }
                case 2:
                    {
                        temp = massive[1];
                        for (int i = 0; i < massive[0].Length; i++)
                        {
                            for (int j = 0; j < massive[1].Length; j++)
                            {
                                if (massive[0][i] == massive[1][j])
                                {
                                    temp[j] = int.MaxValue;
                                    count++;
                                    break;
                                }
                            }
                        }
                        differenceMassive = new int[temp.Length - count];
                        for (int i = 0; i < differenceMassive.Length; i++)
                        {
                            while (temp[index] == int.MaxValue)
                            {
                                index++;
                            }
                            differenceMassive[i] = temp[index];
                            index++;
                        }
                        return differenceMassive;
                    }
            }
            return null;
        }
    }
}
