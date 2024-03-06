using Microsoft.VisualBasic;
using System;
using System.Runtime.CompilerServices;
using System.ComponentModel;

namespace TwoDimensionalArray
{
    /// <summary>
    /// Класс, для работы с двумерным массивом
    /// </summary>
    public class TwoArray
    {
        /// <summary>
        /// Это метод, который создаёт совсем новый массив
        /// <param name="massive">Ступенчатый массив, который нужно инициализировать.</param>
        /// </summary>
        [Description("Это метод, который создаёт совсем новый массив")]
        public void NewArray(ref int[][] massive)
        {
            int massSize;
            Console.Write("Введите размер массива NxN. N не должен превышать 5 элементов и должен быть больше нуля: ");
            try
            {
                massSize = Int32.Parse(Console.ReadLine());
            }
            catch
            {
                massSize = 0;
            }
            while (massSize > 5 || massSize <= 0)
            {
                Console.Write("N введён неверно, введите ещё раз: ");
                try
                {
                    massSize = Int32.Parse(Console.ReadLine());
                }
                catch
                {
                    massSize = 0;
                }
            }
            massive = new int[massSize][];
            for (int i = 0; i < massive.Length; i++)
            {
                massive[i] = new int[massSize];
            }
        }
        /// <summary>
        /// Это метод, с помощью которого вы добавляете все элементы в пустой массив
        /// <param name="massive">Ступенчатый массив, в который нужно добавлять элементы.</param>
        /// </summary>
        [Description("Это метод, с помощью которого вы добавляете все элементы в пустой массив")]
        public void AddElement(ref int[][]massive)
        {
            int count = 0;
            for(int i = 0; i < massive.Length; i++)
            {
                for(int j = 0; j < massive[i].Length; j++)
                {
                    Console.Write("Введите элемент {0} ",(count+1));
                again:
                    try
                    {
                        massive[i][j] = Int32.Parse(Console.ReadLine());
                    }
                    catch
                    {
                        Console.Write("Неправильный ввод, попробуйте ещё раз: ");
                        goto again;
                    }
                    count++;
                }
            }
        }
        /// <summary>
        /// Это метод, который сортирует ваш массив
        /// <param name="massive">Ступенчатый массив, который нужно отсортировать.</param>
        /// </summary>
        [Description("Это метод, который сортирует ваш массив")]
        public void Sort(ref int[][] massive)
        {
            var flattenedArray = massive.SelectMany(x => x).ToArray();

            Array.Sort(flattenedArray);

            int currentIndex = 0;
            for (int i = 0; i < massive.Length; i++)
            {
                for (int j = 0; j < massive[i].Length; j++)
                {
                    massive[i][j] = flattenedArray[currentIndex++];
                }
            }
        }
        /// <summary>
        /// Это метод, который выводит ваш массив
        /// </summary>
        [Description("Это метод, который выводит ваш массив")]
        public void OutPut(ref int[][] massive)
        {
            for(int i = 0; i < massive.Length; i++)
            {
                for(int j = 0; j < massive[i].Length;j++)
                {
                    if (massive[i][j] == 0) continue;
                    Console.Write("| {0,3}  ", massive[i][j]);
                }
                Console.WriteLine("|");
            }
        }
        /// <summary>
        /// Это метод, который добавляет один элемент в ваш массив
        /// </summary>
        /// <param name="element">Число, которое нужно вставить.</param>
        /// <param name="massive">Ступенчатый массив, в который нужно вставить элемент.</param>
        [Description("Это метод, который добавляет один элемент в ваш массив")]
        public void InsertElement(ref int[][] massive, int element)
        {
            int count = 0;
            int[][] reserve=new int[massive.Length][];
            massive.CopyTo(reserve, 0);
            for (int i = 0; i < massive.Length; i++)
            {
                if (massive[i].Length >= 5)
                {
                    count++;
                }
                else
                {
                    massive[i] = new int[massive[i].Length + 1];
                    massive[i][massive[i].Length - 1] = element;
                    break;
                }
            }
            if (count == massive.Length)
            {
                massive = new int[reserve.Length + 1][];
                reserve.CopyTo(massive, 0);
                massive[massive.Length-1] = new int[1];
                massive[massive.Length-1][0] = element;
            }
            else
            for(int i = 0; i < reserve.Length; i++)
            {
                for(int j = 0; j < reserve[i].Length;j++)
                {
                    massive[i][j] = reserve[i][j];
                }
            }
            Sort(ref massive);
        }
        /// <summary>
        /// Это метод, который находит элемент, находящийся в 
        /// определенной строке и определенном столбце
        /// </summary>
        /// <param name="massive">Ступенчатый массив, в котором нужно найти элемент.</param>
        /// <param name="row">Строка искомого элемента.</param>
        /// <param name="column">Столбец искомого элемента</param>
        [Description("Это метод, который находит элемент, находящийся в определенной строке и определенном столбце")]
        public int FindElement(ref int[][] massive,int row, int column)
        {
            int element = -1;
            try
            {
                element = massive[row][column];
            }
            catch
            {
                Console.WriteLine("Индекс вышел за границы массива.");
            }
            return element;
        }
        /// <summary> Это метод, который находит строку и столбец искомого элемента</summary>
        /// <param name="massive">Ступенчатый массив, в котором нужно найти элемент.</param>
        /// <param name="element">Элемент, который нужно найти.</param>
        /// <returns>В консоль строка и столбец искомого элемента.</returns>
        [Description("Это метод, который находит строку и столбец искомого элемента")]
        public void FindElement(ref int[][] massive, int element)
        {
            bool isElement = true;
            for(int i = 0; i < massive.Length; i++)
            {
                for(int j = 0; j < massive[i].Length; j++)
                {
                    if (massive[i][j] == element)
                    {
                        Console.WriteLine("Строка: {0}. Столбец: {1}", i, j);
                        isElement = false;
                    }
                }
            }
            if(isElement) Console.WriteLine("Элемент не найден");
        }
        /// <summary>
        /// Это метод, который меняет наш массив на
        /// объединение нашего массива и вводимого
        /// </summary>
        /// <param name="massive">Ступенчатый массив, который нужно объединить с другим массивом.</param>
        /// <param name="secondMass">Ступенчатый массив, который должен быть объединен с первым массивом.</param>
        [Description("Это метод, который меняет наш массив на объединение нашего массива и вводимого")]
        public void Merge(ref int[][] massive, ref int[][]secondMass)
        {
            bool isInMass = true;
            for(int i = 0; i < secondMass.Length; i++)
            {
                for(int j = 0; j < secondMass[i].Length;j++)
                {
                    for(int k = 0; k < massive.Length; k++)
                    {
                        for(int m = 0; m < massive[k].Length; m++)
                        {
                            if (secondMass[i][j] == massive[k][m]) isInMass = false;
                        }
                    }
                    if (isInMass) InsertElement(ref massive,secondMass[i][j]);
                    isInMass = true;
                }
            }
        }
        /// <summary>
        /// Это метод, который меняет наш массив на
        /// пересечение нашего массива и вводимого
        /// </summary>
        /// <param name="massive">Ступенчатый массив, в котором нужно найти пересечение с другим массивом.</param>
        /// <param name="secondMass">Ступенчатый массив, с которым должно быть найдено пересечение с первым массивом.</param>
        [Description("Это метод, который меняет наш массив на пересечение нашего массива и вводимого")]
        public void Intersect(ref int[][] massive, ref int[][] secondMass)
        {
            var flatMass = new int[1000];
            bool isRepeat = false;
            int countIndex = 0;
            for(int i = 0; i < massive.Length; i++)
            {
                for(int j = 0; j < massive[i].Length;j++)
                {
                    for(int k = 0; k < secondMass.Length;k++)
                    {
                        for(int m = 0; m < secondMass[k].Length;m++)
                        {
                            if (massive[i][j] == secondMass[k][m])
                            {
                                for(int s = 0; s < countIndex; s++)
                                {
                                    if (flatMass[s] == massive[i][j]) isRepeat = true;
                                }
                                if (isRepeat) break;
                                flatMass[countIndex++] = massive[i][j];
                                break;
                            }
                        }
                        if (isRepeat) break;
                    }
                    if (isRepeat)
                    {
                        isRepeat = false;
                        continue;
                    }
                }
            }
            if (countIndex == 0) Console.WriteLine("Пересечения нет");
            else
            {
                massive = new int[1][];
                massive[0] = new int[0];
                for(int i = 0; i < countIndex; i++)
                {
                    InsertElement(ref massive, flatMass[i]);
                }
            }
        }
    }
}
