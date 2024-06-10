using System;

namespace SetWorkPiOIvIS
{
    interface ISets
    {
        public void CreateSet(string fileName);
        public void UpdateSet(string fileName);
        public void OutPutSet();
        public int[] DifferenceSet(int variatn);
    }
}
