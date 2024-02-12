using System;
using System.Collections.Generic;
using System.Text;
using TradingEngineServer.Orders;

namespace TradingEngineServer.Rejects
{
    public sealed class RejectCreator
    {
        public static Reject GenerateOrderCoreReject(IOrderCore rejectOrder, RejectReason rejectReason)
        {
            return new Reject(rejectOrder, rejectReason);
        }
    }
}
