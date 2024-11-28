using System;
using System.Collections.Generic;
using System.Text;
using TradingEngineServer.Orders;

namespace TradingEngineServer.Rejects
{
    public class Reject : IOrderCore
    {
        public Reject(IOrderCore rejectedOrder, RejectReason rejectReason)
        {
            _orderCore = rejectedOrder;
            RejectReason = rejectReason;
        }
        public RejectReason RejectReason { get; private set; }
        public long OrderId => _orderCore.OrderId;

        public string Username => _orderCore.Username;

        public int SecurityId => _orderCore.SecurityId;


        private readonly IOrderCore _orderCore;
    }
}
