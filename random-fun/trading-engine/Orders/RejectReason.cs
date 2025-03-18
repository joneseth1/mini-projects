using System;
using System.Collections.Generic;
using System.Text;

namespace TradingEngineServer.Orders
{
    public enum RejectReason
    {
        Unkown, 
        OrderNotFound,
        InstrumentNotFound, 
        WrongSideModify
    }
}
