using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Orders
{
    class BidLimitComparer : IComparer<Limit>
    {
        public static IComparer<Limit> Comparer { get; } = new BidLimitComparer();
        public int Compare(Limit x, Limit y)
        {
            if(x.Price == y.Price)
                return 0;
            else if(x.Price > y.Price)
                return -1;
            else return 1;
        }
    }

    class AskLimitComparer : IComparer<Limit>
    {
        public int Compare(Limit x, Limit y)
        {
            if(x.Price == y.Price)
                return 0;
            else if(x.Price > y.Price)
                return 1;
            else return -1;
        }
    }
}
