using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TwoDimensionalArray
{
    interface ITwoArray
    {
        public void NewArray(ref int[][] massive);
        public void AddElement(ref int[][] massive);
        public void Sort(ref int[][] massive);
        public void OutPut(ref int[][] massive);
        public void InsertElement(ref int[][] massive, int element);
        public int FindElement(ref int[][] massive, int row, int column);
        public void FindElement(ref int[][] massive, int element);
        public void Merge(ref int[][] massive, ref int[][] secondMass);
        public void Intersect(ref int[][] massive, ref int[][] secondMass);
    }
}
